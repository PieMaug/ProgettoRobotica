#ifndef __CONTROLINTERFACE
#define __CONTROLINTERFACE

#include <gazebo/transport/transport.hh>
#include <gazebo/msgs/msgs.hh>

#include "MotorsCommand.pb.h"

#include <stdio.h>
#include <stdlib.h>

using namespace gazebo;

class ControlInterface {
  public:
    ControlInterface();
    ~ControlInterface();

    void set_joints_torques(float left_signal, float right_signal);

  private:
    // Topic to write motor commands to.
    std::string topic;

    // Command message to send to topic.
    msgs::MotorsCommand msg;

    // The node on which we're advertising.
    transport::NodePtr node;

    // Publisher handle.
    transport::PublisherPtr pub;
};

#endif
