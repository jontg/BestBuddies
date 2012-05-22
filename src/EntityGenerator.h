#ifndef __ENTITY_GENERATOR_H__
#define __ENTITY_GENERATOR_H__
#include <string>
#include <boost/signals2/signal.hpp>

#include <Data_Structures/Email.pb.h>
#include <Data_Structures/Entity.pb.h>

using namespace std;
using namespace EnronProject;

class EntityGenerator {
  typedef boost::signals2::signal<void (Entity *)> signal_t;

  public:
    EntityGenerator();

    boost::signals2::connection AttachSubscriber(signal_t::slot_type subscriber)
    { return processed_signal.connect(subscriber); }

    void ReceiveEmail(Email * email);

  private:
    signal_t processed_signal;
};

#endif
