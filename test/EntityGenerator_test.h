#include <EntityGenerator.h>

TEST(EntityGenerator, EndToEndTest) {
  MockFile * mock_file = new MockFile();
  mock_file->AssignOpenResponse(true);
  mock_file->AssignReadLineResponse(true, "___JONTG_START_TOKEN___ ruscitti-k/_sent_mail/SUMMARY.txt");
  mock_file->AssignReadLineResponse(true, "Message-ID: <20851539.1075852837765.JavaMail.evans@thyme>\r");
  mock_file->AssignReadLineResponse(true, "Date: Tue, 25 Sep 2001 15:04:00 -0700 (PDT)\r");
  mock_file->AssignReadLineResponse(true, "From: 40enron@enron.com\r");
  mock_file->AssignReadLineResponse(true, "To: john.lavorato@enron.com\r");
  mock_file->AssignReadLineResponse(true, "Subject: 2001 Special Stock Option Grant Awards\r");
  mock_file->AssignReadLineResponse(true, "Mime-Version: 1.0\r");
  mock_file->AssignReadLineResponse(true, "Content-Type: text/plain; charset=ANSI_X3.4-1968\r");
  mock_file->AssignReadLineResponse(true, "Content-Transfer-Encoding: 7bit\r");
  mock_file->AssignReadLineResponse(true, "\r");
  mock_file->AssignReadLineResponse(true, "We are pleased to present you with a 2001 Special Stock Option Grant Award.");
  mock_file->AssignReadLineResponse(true, "As a participant in this grant you have the opportunity to share in the ownership");
  mock_file->AssignReadLineResponse(true, "of Enron and the potential profit from increases in the value of Enron's common stock.");
  mock_file->AssignReadLineResponse(true, "___JONTG_EOF_TOKEN___");
  mock_file->AssignReadLineResponse(true, "Message-ID: <20851539.1075852837765.JavaMail.evans@thyme>\r");
  mock_file->AssignReadLineResponse(true, "Date: Tue, 25 Sep 2001 15:04:00 -0700 (PDT)\r");
  mock_file->AssignReadLineResponse(true, "From: 40enron@enron.com\r");
  mock_file->AssignReadLineResponse(true, "To: john.lavorato@enron.com\r");
  mock_file->AssignReadLineResponse(true, "Subject: 2001 Special Stock Option Grant Awards\r");
  mock_file->AssignReadLineResponse(true, "Mime-Version: 1.0\r");
  mock_file->AssignReadLineResponse(true, "Content-Type: text/plain; charset=ANSI_X3.4-1968\r");
  mock_file->AssignReadLineResponse(true, "Content-Transfer-Encoding: 7bit\r");
  mock_file->AssignReadLineResponse(true, "\r");
  mock_file->AssignReadLineResponse(true, "We are pleased to present you with a 2001 Special Stock Option Grant Award.");
  mock_file->AssignReadLineResponse(true, "As a participant in this grant you have the opportunity to share in the ownership");
  mock_file->AssignReadLineResponse(true, "of Enron and the potential profit from increases in the value of Enron's common stock.");
  mock_file->AssignReadLineResponse(true, "___JONTG_EOF_TOKEN___");
  mock_file->AssignCloseResponse(true);

  EmailReader reader(mock_file);
  EntityGenerator generator;

  boost::signals2::connection conn = reader.AttachSubscriber(boost::bind(&EntityGenerator::ReceiveEmail, &generator, _1));

  reader.Run();
  generator.AnnounceResults();
  conn.disconnect();
}
