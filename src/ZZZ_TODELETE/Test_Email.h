#include "Email.h"

bool test_read_email() {
    std::cout<<"Testing LoadFromFile()"<<std::endl;
    std::string filename("test_data/1.");
    Email e(0, filename);
    e.LoadFromFile();

    assert(e.text.length() > 2000);
    std::cout<<"\tTest 1 PASSED"<<std::endl;

    std::string garbage_filename("asdfa;lkjasdf;lkjasdf;lkjd");
    Email e2(1,garbage_filename);
    try {e2.LoadFromFile();
    } catch(std::exception& e) {
        std::cout<<"\tTest 2 PASSED"<<std::endl;
    }
    return true;
}
