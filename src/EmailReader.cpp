#include <re2/re2.h>

#include <Data_Structures/Email.pb.h>
#include <EmailReader.h>

//------------------------------------------------------------------------------

void EmailReader::Run()
{
  static const RE2 start_email_regex("___JONTG_START_TOKEN___ ([a-zA-Z0-9\\._\\/\\-]*)\\s?");
  static const RE2 end_email_regex("___JONTG_EOF_TOKEN___\\s?");
  static const RE2 sender_regex("From: (.*)\\r\\s?");
  static const RE2 receiver_regex("To: (.*)\\r\\s?");
  static const RE2 cc_regex("cc: (.*)\\r\\s?");
  static const RE2 end_header_regex("^\\r");
  assert(start_email_regex.ok());
  assert(end_email_regex.ok());
  assert(sender_regex.ok());
  assert(receiver_regex.ok());
  assert(cc_regex.ok());
  assert(end_header_regex.ok());

  bool reading_header(true);
  Email *current_email(NULL);
  string current_line, folder_path, header_buffer, buffer;

  file->Open();
  while(!file->eof()) {
    if(!file->ReadLine(current_line)) continue;

    if(RE2::FullMatch(current_line, end_email_regex)) {
      current_email->set_body(buffer);
      processed_signal(current_email);

      reading_header = true;
      current_email = new Email();
      current_email->set_folder_metadata(folder_path);
      buffer = "";
    } else if(reading_header) {
      if(RE2::FullMatch(current_line, start_email_regex, &folder_path)) {
        current_email = new Email();
        current_email->set_folder_metadata(folder_path);
        continue;
      }

      buffer += current_line + "\n";
      if(RE2::FullMatch(current_line, sender_regex, &header_buffer)) {
        current_email->set_sender(header_buffer);

      } else if(RE2::FullMatch(current_line, receiver_regex, &header_buffer)) {
        current_email->add_receiver(header_buffer);
      } else if(RE2::FullMatch(current_line, cc_regex, &header_buffer)) {
        current_email->add_receiver(header_buffer);

      } else if(RE2::FullMatch(current_line, end_header_regex)) {
        reading_header = false;
        current_email->set_header(buffer);
        buffer = "";
      }
    } else buffer += current_line + "\n";
  }
  file->Close();
}

//------------------------------------------------------------------------------
