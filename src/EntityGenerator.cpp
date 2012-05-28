#include <iostream>
#include <re2/re2.h>

#include <DiskFile.h>
#include <EntityGenerator.h>

//------------------------------------------------------------------------------

void EntityGenerator::ReceiveEmail(Email * email)
{
  static const RE2 is_sent_folder_regex("/_?sent");
  static const RE2 sender_name_regex("^([^/]+)");
  assert(is_sent_folder_regex.ok());
  assert(sender_name_regex.ok());

  if(RE2::PartialMatch(email->folder_metadata(), is_sent_folder_regex)) {
    string sender_name;
    RE2::PartialMatch(email->folder_metadata(), sender_name_regex, &sender_name);
    sender_address_count[sender_name][email->sender()]++;
  }
}

//------------------------------------------------------------------------------

void EntityGenerator::AnnounceResults()
{
  for(map<string, map<string, int> >::const_iterator iter = sender_address_count.begin();
      iter != sender_address_count.end(); ++iter) {
    cout<<iter->first<<":"<<endl;
    for(map<string,int>::const_iterator res_iter = iter->second.begin();
        res_iter != iter->second.end(); ++res_iter) {
      cout<<"\t"<<res_iter->first<<"\t"<<res_iter->second<<endl;
    }
  }
}
//------------------------------------------------------------------------------
