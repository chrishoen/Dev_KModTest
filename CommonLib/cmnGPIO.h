#pragma once

/*==============================================================================
This provides a wrapper for the gpio facilities.
==============================================================================*/

#include <gpiod.h>

//******************************************************************************
//******************************************************************************
//******************************************************************************

namespace Cmn
{

//******************************************************************************
//******************************************************************************
//******************************************************************************
// This class provides an interface to some gpio bits.
// GND    : PIN25
// GPIO5  : PIN29 OUT : A 
// GPIO6  : PIN31 IN  : B
// GPIO13 : PIN33

class GPIO
{
public:

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Constants.

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Members.

   struct gpiod_chip* mChip0;
   struct gpiod_chip* mChip1;

   struct gpiod_line* mLineA;
   struct gpiod_line* mLineB;

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Methods.

   // Constructor.
   GPIO();

   // Device initialize and finalize.
   void initialize();
   void finalize();

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Methods.

   // Write to the digital output for gpio A.
   void writeA(bool aValue);

   // Read from the digital output for gpio B.
   bool readB();

};

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Global singular instance.

#ifdef _CMNGPIO_CPP_
          GPIO gGPIO;
#else
   extern GPIO gGPIO;
#endif

//******************************************************************************
//******************************************************************************
//******************************************************************************
}//namespace

