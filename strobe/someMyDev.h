#pragma once

/*==============================================================================
This provides a wrapper for the gpio mydrv/mydev device driver.
==============================================================================*/

//******************************************************************************
//******************************************************************************
//******************************************************************************

namespace Some
{

//******************************************************************************
//******************************************************************************
//******************************************************************************
// This class provides an interface to some gpio bits.
// GND    : PIN25
// MyDev5  : PIN29 OUT : A 
// MyDev6  : PIN31 IN  : B
// MyDev13 : PIN33

class MyDev
{
public:

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Members.

   // If true then the device is valid and open.
   bool mValidFlag;

   // Device file descriptor.
   int mDevFd;

   // Test value.
   int mTestValue;

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Methods.

   // Constructor.
   MyDev();

   // Device initialize and finalize.
   void initialize();
   void finalize();

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Methods.

   // Write to the digital output for gpio A.
   void writeA(bool aValue);

   // Read the isr count.
   int readCount();

   // Do an ioctl test.
   void doTest1(int* aValue);
   void doTest2();
};

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Global singular instance.

#ifdef _SOMEMYDEV_CPP_
          MyDev gMyDev;
#else
   extern MyDev gMyDev;
#endif

//******************************************************************************
//******************************************************************************
//******************************************************************************
}//namespace

