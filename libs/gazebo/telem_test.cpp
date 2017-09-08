#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "telem_interface.h"

int main(int argc, char** argv)
{
  TelemInterface telem;
  float ts;
  int left_ticks;
  int right_ticks;
  float left_velocity;
  float right_velocity;

  while(1)
  {
    telem.get_sample(&ts, &left_ticks, &right_ticks, &left_velocity, &right_velocity);
    printf("Timestamp = %f, Left ticks = %d, Right ticks = %d, Left velocity = %f, Right velocity = %f\n", \
          ts, left_ticks, right_ticks, left_velocity, right_velocity);
    usleep(500000);
  }
}
