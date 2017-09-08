#include <stdio.h>
#include <stdlib.h>

#include "control_interface.h"

int main(int argc, char** argv)
{
  ControlInterface ctl;

  while(1)
  {
    ctl.set_joints_torques(0, 0);
    common::Time::MSleep(100);
  }
}
