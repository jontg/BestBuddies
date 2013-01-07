#ifndef __DATA_STORAGE_H__
#define __DATA_STORAGE_H__
#include <string>
#include <boost/signals2/signal.hpp>

#include <Data_Structures/Email.pb.h>
#include <Data_Structures/Entity.pb.h>

using namespace std;
using namespace EnronProject;

class DataStorage {
  typedef boost::signals2::signal<void (Entity *)> signal_t;

  public:
    DataStorage() {}

    boost::signals2::connection AttachSubscriber(signal_t::slot_type subscriber)
    { return processed_signal.connect(subscriber); }

    void ReceiveEmail(Email * email);

  private:
    signal_t processed_signal;
};

#endif
