#pragma once

#include <string>

#include <gazebo/common/common.hh>
#include <gazebo/transport/transport.hh>

#include "EncoderMsg.pb.h"

using namespace gazebo;

typedef const boost::shared_ptr<const msgs::EncoderMsg> ConstEncoderMsgPtr;

class TelemInterface {
  public:
    TelemInterface();
    ~TelemInterface();
	float get_timestamp();
	int get_left_tick();
	int get_right_tick();
	float get_left_angle();
	float get_right_angle();
	float get_left_vel();
	float get_right_vel();
    void get_sample(float* ts, int* left_ticks, int* right_ticks, float* left_velocity, float* right_velocity);
    void print();

  private:
    float m_ts;
    int m_left_ticks;
    int m_right_ticks;
	float m_left_angle;
	float m_right_angle;
    float m_left_velocity;
    float m_right_velocity;

    // Topic to read encoder signals from.
    std::string topic;

    // The node on which we're advertising.
    transport::NodePtr node;

    // Subscriber handle.
    transport::SubscriberPtr sub;

    // Function to call when a new message arrives on topic.
    void telem_callback(const ConstEncoderMsgPtr& msg);
};
