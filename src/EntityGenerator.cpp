#include <iostream>
#include <re2/re2.h>

#include <EntityGenerator.h>

//------------------------------------------------------------------------------

void EntityGenerator::ReceiveEmail(Email * email)
{
    static const RE2 is_sent_folder_regex("sent");
    assert(is_sent_folder_regex.ok());

    if(RE2::PartialMatch(email->folder_metadata()), is_sent_folder_regex) {
    } else {
      cout<<"Path "<<email->folder_metadata()<<" ignored"<<endl;
    }
}

//------------------------------------------------------------------------------
