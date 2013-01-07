#include <iostream>
#include <re2/re2.h>

#include <DataStorage.h>

//------------------------------------------------------------------------------

void DataStorage::ReceiveEmail(Email * email)
{
  // static const RE2 is_sent_folder_regex("/_?sent");
  // static const RE2 sender_name_regex("^([^/]+)");
  // assert(is_sent_folder_regex.ok());
  // assert(sender_name_regex.ok());

  // if(RE2::PartialMatch(email->folder_metadata(), is_sent_folder_regex)) {
  //   string sender_name;
  //   RE2::PartialMatch(email->folder_metadata(), sender_name_regex, &sender_name);
  //   sender_address_count[sender_name][email->sender()]++;
  // }
}

//------------------------------------------------------------------------------
