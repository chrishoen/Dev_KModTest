/*==============================================================================
Description:
==============================================================================*/

//******************************************************************************
//******************************************************************************
//******************************************************************************

#include "stdafx.h"

#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>
#include <signal.h>
#include <poll.h>
#include <sys/ioctl.h>
#include <sys/stat.h>

#include "cmnStrobeParms.h"

#define  _SOMEMYDEV_CPP_
#include "someMyDev.h"

namespace Some
{

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Constructor.

MyDev::MyDev()
{
   mValidFlag = false;
   mDevFd = 0;
   mTestValue = 0;
}

void MyDev::initialize()
{
   // Close device, if open.
   finalize();

   // Open the device.
   mDevFd = open(Cmn::gStrobeParms.mDevPath, O_RDWR);
   if (mDevFd < 0)
   {
      printf("device open FAIL  %s %d %s\n", Cmn::gStrobeParms.mDevPath, errno, strerror(errno));
   }
   else
   {
      printf("device open PASS %s\n", Cmn::gStrobeParms.mDevPath);
      mValidFlag = true;
   }
}

void MyDev::finalize()
{
   // Close device, if open.
   if (mValidFlag)
   {
      mValidFlag = false;
      close(mDevFd);
      mDevFd = -1;
   }
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Write to the digital output for gpio A.

void MyDev::writeA(bool aValue)
{
   // Guard.
   if (!mValidFlag) return;

   int tValue = aValue;
   int tRet = 0;
   tRet = ioctl(mDevFd, 102, &tValue);
   if (tRet < 0)
   {
      printf("device ioctl FAIL  %d %s\n", errno, strerror(errno));
      finalize();
   }
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Read from the digital output for gpio B.

bool MyDev::readB()
{
   return false;
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Do an ioctl test.

void MyDev::doTest1(int* aValue)
{
   // Guard.
   if (!mValidFlag) return;

   int tRet = 0;
   tRet = ioctl(mDevFd, 201, aValue);
   if (tRet < 0)
   {
      printf("device ioctl FAIL  %d %s\n", errno, strerror(errno));
      finalize();
   }
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Do an ioctl test.

void MyDev::doTest2()
{
   // Guard.
   if (!mValidFlag) return;

   if(ioctl(mDevFd, 201, &mTestValue) < 0)
   {
      printf("device ioctl FAIL  %d %s\n", errno, strerror(errno));
      finalize();
   }
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
}//namespace
