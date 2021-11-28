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
#include <sys/eventfd.h>
#include <sys/ioctl.h>
#include <sys/stat.h>

#include "risProgramTime.h"
#include "risThreadsPriorities.h"

#include "somePeriodicParms.h"
#include "someStrobeParms.h"

#define  _SOMESTROBETHREAD1_CPP_
#include "someStrobeThread.h"

namespace Some
{

//******************************************************************************
//******************************************************************************
//******************************************************************************

StrobeThread::StrobeThread()
{
   // Set base class variables.
   BaseClass::setThreadName("Strobe");
   BaseClass::setThreadPriority(
      Ris::Threads::Priority(
         gPeriodicParms.mTestThreadProcessor,
         gPeriodicParms.mTestThreadPriority));

   // Set timer period.
   BaseClass::mTimerPeriod = gPeriodicParms.mTestThreadPeriod;
   BaseClass::mPollProcessor = gPeriodicParms.mPollProcessor;
   BaseClass::mStatPeriod = gPeriodicParms.mStatPeriod;

   // Set member variables.
   mTPFlag = false;
   mDevFd = 0;
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Thread init function. This is called by the base class immediately 
// after the thread starts running.

void StrobeThread::threadInitFunction()
{
   mDevFd = open(gStrobeParms.mDevPath, O_RDWR);

   if (mDevFd < 0)
   {
      printf("device open FAIL  %s %d %s\n", gStrobeParms.mDevPath, errno, strerror(errno));
   }
   else
   {
      printf("device open PASS %s\n", gStrobeParms.mDevPath);
   }
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Thread exit function, base class overload.

void  StrobeThread::threadExitFunction()
{
   if (mDevFd > 0)
   {
      printf("device close %s\n", gStrobeParms.mDevPath);
      close(mDevFd);
      mDevFd = -1;
   }
}

//******************************************************************************
//******************************************************************************
//******************************************************************************

void StrobeThread::executeOnTimer(int aTimeCount)
{
   // Guard.
   if (!mTPFlag) return;
   if (mDevFd <= 0) return;

   // Write to the device driver.
   int tRet = 0;
   char tBuffer[10];
   if (aTimeCount % 2)
   {
      strcpy(tBuffer, "1\n");
   }
   else
   {
      strcpy(tBuffer, "0\n");
   }
   tRet = write(mDevFd, tBuffer, 2);
   if (tRet < 0)
   {
      printf("device write FAIL  %d %s\n", errno, strerror(errno));
      close(mDevFd);
      mDevFd = -1;
   }
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
}//namespace