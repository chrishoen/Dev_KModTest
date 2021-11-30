/*==============================================================================
Description:
==============================================================================*/

//******************************************************************************
//******************************************************************************
//******************************************************************************
#include "stdafx.h"

#include <time.h>

#include "risProgramTime.h"
#include "risThreadsPriorities.h"

#include "cmnPeriodicParms.h"
#include "someStrobeThread.h"

#define  _SOMEMONITORTHREAD_CPP_
#include "someMonitorThread.h"

namespace Some
{

//******************************************************************************
//******************************************************************************
//******************************************************************************

MonitorThread::MonitorThread()
{
   // Set base class variables.
   BaseClass::setThreadName("Monitor");

   // Set base class variables.
   BaseClass::setThreadPriority(Ris::Threads::gPriorities.mMonitor);

   // Set timer period.
   BaseClass::mTimerPeriod = Cmn::gPeriodicParms.mMonitorThreadPeriod;
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Thread init function. This is called by the base class immediately 
// after the thread starts running.

void MonitorThread::threadInitFunction()
{
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Thread exit function, base class overload.

void MonitorThread::threadExitFunction()
{
   Prn::print(0, "MonitorThread::threadExitFunction BEGIN");
   Prn::print(0, "MonitorThread::threadExitFunction END");
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Thread shutdown function.

void MonitorThread::shutdownThread()
{
   Prn::print(0, "MonitorThread::shutdownThread BEGIN");
   BaseClass::shutdownThread();
   Prn::print(0, "MonitorThread::shutdownThread END");
}

//******************************************************************************
//******************************************************************************
//******************************************************************************

void MonitorThread::executeOnTimer(int aTimeCount)
{
   if (gStrobeThread->mStatPollFlag)
   {
      gStrobeThread->mStatPollFlag = false;
      Prn::print(Prn::Show1, "S %5d %2d  J %5.1f %5.1f %5.1f  E %5.1f",
         gStrobeThread->mStatCount,
         gStrobeThread->mThreadCurrentProcessor,
         gStrobeThread->mStatJitterMean,
         gStrobeThread->mStatJitterStdDev,
         gStrobeThread->mStatJitterMax,
         gStrobeThread->mStatExecMax);
   }
}

//******************************************************************************
//******************************************************************************
//******************************************************************************

}//namespace