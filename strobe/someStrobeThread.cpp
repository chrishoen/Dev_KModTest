/*==============================================================================
Description:
==============================================================================*/

//******************************************************************************
//******************************************************************************
//******************************************************************************
#include "stdafx.h"

#include "risProgramTime.h"
#include "risThreadsPriorities.h"

#include "cmnPeriodicParms.h"
#include "cmnStrobeParms.h"
#include "someMyDev.h"

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
         Cmn::gPeriodicParms.mTestThreadProcessor,
         Cmn::gPeriodicParms.mTestThreadPriority));

   // Set timer period.
   BaseClass::mTimerPeriod = Cmn::gPeriodicParms.mTestThreadPeriod;
   BaseClass::mPollProcessor = Cmn::gPeriodicParms.mPollProcessor;
   BaseClass::mStatPeriod = Cmn::gPeriodicParms.mStatPeriod;

   // Set member variables.
   mTPFlag = false;
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Thread init function. This is called by the base class immediately 
// after the thread starts running.

void StrobeThread::threadInitFunction()
{
   gMyDev.initialize();
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Thread exit function, base class overload.

void StrobeThread::threadExitFunction()
{
   gMyDev.finalize();
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Thread shutdown function.

void StrobeThread::shutdownThread()
{
   Prn::print(0, "StrobeThread::shutdownThread BEGIN");
   BaseClass::shutdownThread();
   Prn::print(0, "StrobeThread::shutdownThread END");
}

//******************************************************************************
//******************************************************************************
//******************************************************************************

void StrobeThread::executeOnTimer(int aTimeCount)
{
   // Guard.
   if (!mTPFlag) return;
   if (!gMyDev.mValidFlag) return;

   if (Cmn::gStrobeParms.mTestCode1 == 1)
   {
      // Write to the device driver.
      gMyDev.writeA(aTimeCount % 2);
   }
   else if (Cmn::gStrobeParms.mTestCode1 == 2)
   {
      // Write to the device driver.
      gMyDev.doTest2();
   }

}

//******************************************************************************
//******************************************************************************
//******************************************************************************
}//namespace