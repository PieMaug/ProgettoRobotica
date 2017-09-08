#include <math.h>

#include "telem_interface.h"

#define RESOLUTION 4000 // ticks per revolution
#define UPPER 10000
#define LOWER 0.000001

TelemInterface::TelemInterface()
{
  printf("TELEM INTERFACE CONSTRUCTOR\n");
  transport::init();
  transport::run();
  node = transport::NodePtr(new transport::Node());
  node->Init("rgsim");
  sub = node->Subscribe("~/encoders", &TelemInterface::telem_callback, this);
}

TelemInterface::~TelemInterface()
{
  printf("TELEM INTERFACE DESTRUCTOR\n");
  node->Fini();
  sub->Unsubscribe();
}

float TelemInterface::get_timestamp(){
	return m_ts;
}

int TelemInterface::get_left_tick(){
	return m_left_ticks;
}

int TelemInterface::get_right_tick(){
	return m_right_ticks;
}

float TelemInterface::get_left_vel(){
	if(m_left_velocity > 0 && ( m_left_velocity < LOWER | m_left_velocity > UPPER) ) return 0;
	if(m_left_velocity < 0 && ( m_left_velocity < -UPPER | m_left_velocity > -LOWER) ) return 0;
	return m_left_velocity;
}

float TelemInterface::get_right_vel(){
	if(m_right_velocity > 0 && ( m_right_velocity < LOWER | m_right_velocity > UPPER) ) return 0;
	if(m_right_velocity < 0 && ( m_right_velocity < -UPPER | m_right_velocity > -LOWER) ) return 0;
	return m_right_velocity;
}

float TelemInterface::get_left_angle(){
	return m_left_angle;
}

float TelemInterface::get_right_angle(){
	return m_right_angle;
}

void TelemInterface::get_sample(float* ts, int* left_ticks, int* right_ticks, float* left_velocity, float* right_velocity)
{
  *ts = m_ts;
  *left_ticks = m_left_ticks;
  *right_ticks = m_right_ticks;
  *left_velocity = m_left_velocity;
  *right_velocity = m_right_velocity;
  //printf("ts %f, tick l %d, r %d, vel l %f, r %f\n",ts,left_ticks,right_ticks,left_velocity,right_velocity);
}

void TelemInterface::print()
{
  printf("Timestamp = %f, Left ticks = %d, Right ticks = %d, Left velocity = %f, Right velocity = %f\n", 
          m_ts, m_left_ticks, m_right_ticks, m_left_velocity, m_right_velocity);
}

void TelemInterface::telem_callback(const ConstEncoderMsgPtr& msg)
{
  m_ts = msg->timestamp();
  m_left_angle = msg->left_angle();
  m_right_angle = msg->right_angle();
#if ISRADIANT
  m_left_angle = m_right_angle - ((int)(m_right_angle/(2 * M_PI)))* (2 * M_PI);
  m_right_angle = m_right_angle - ((int)(m_right_angle/(2 * M_PI)))* (2 * M_PI);
#else
  m_left_angle = m_right_angle - ((int)(m_right_angle/360))*360;
  m_right_angle = m_right_angle - ((int)(m_right_angle/360))*360;
#endif
  m_left_ticks = m_left_angle * RESOLUTION / (2 * M_PI);
  m_right_ticks = m_right_angle * RESOLUTION / (2 * M_PI);
  m_left_velocity = msg->left_velocity();
  m_right_velocity = msg->right_velocity();
}
