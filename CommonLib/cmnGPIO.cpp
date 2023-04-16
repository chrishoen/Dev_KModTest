/*==============================================================================
Description:
==============================================================================*/

//******************************************************************************
//******************************************************************************
//******************************************************************************

#include "stdafx.h"
#include "risThreadsThreads.h"

#define  _CMNGPIO_CPP_
#include "cmnGPIO.h"

namespace Cmn
{

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Constructor.

GPIO::GPIO()
{
}

void GPIO::initialize()
{
   // Chip 0.
   if ((mChip0 = gpiod_chip_open_by_name("gpiochip0")) == 0)
   {
      printf("GPIO::initialize FAIL1\n");
      return;
   }

   // Chip 1.
   if ((mChip1 = gpiod_chip_open_by_name("gpiochip1")) == 0)
   {
      printf("GPIO::initialize FAIL2\n");
      return;
   }

   // LineA. Chip0 Line5. Gpio5. Pin29. Output.
   if ((mLineA = gpiod_chip_get_line(mChip0, 5)) == 0)
   {
      printf("GPIO::initialize FAIL3\n");
      return;
   }
   if (gpiod_line_request_output(mLineA, "CmnGpio", 0))
   {
      printf("GPIO::initialize FAIL4\n");
      return;
   }

   // LineB. Chip0 Line6. Gpio6. Pin31. Input.
   if ((mLineB = gpiod_chip_get_line(mChip0, 6)) == 0)
   {
      printf("GPIO::initialize FAIL4\n");
      return;
   }
   if (gpiod_line_request_input(mLineB, "CmnGpio"))
   {
      printf("GPIO::initialize FAIL4\n");
      return;
   }
}

void GPIO::finalize()
{
   gpiod_line_release(mLineA);
   gpiod_line_release(mLineB);
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Write to the digital output for gpio A.

void GPIO::writeA(bool aValue)
{
   if (gpiod_line_set_value(mLineA, aValue))
   {
      printf("GPIO::WriteA FAIL\n");
      return;
   }
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Read from the digital output for gpio B.

bool GPIO::readB()
{
   return gpiod_line_get_value(mLineB);
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
}//namespace
