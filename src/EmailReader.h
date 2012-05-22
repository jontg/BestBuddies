#ifndef __EMAILREADER_H__
#define __EMAILREADER_H__
#include <string>
#include <boost/signals2/signal.hpp>

#include <Data_Structures/Email.pb.h>
#include <Interfaces/FileInterface.h>

using namespace std;
using namespace EnronProject;

class EmailReader {
    typedef boost::signals2::signal<void (Email *)> signal_t;
  public:
    EmailReader(FileInterface* file)
      : file(file)
    {}

    ~EmailReader()
    { delete file; }

    boost::signals2::connection AttachSubscriber(signal_t::slot_type subscriber)
    { return processed_signal.connect(subscriber); }

    void Run();

  private:
    FileInterface* file;
    signal_t processed_signal;
};

#endif
