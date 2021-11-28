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

void MonitorThread::executeOnTimer(int aTimeCount)
{
   if (gStrobeThread->mStatPollFlag)
   {
      gStrobeThread->mStatPollFlag = false;
      Prn::print(0, "S %5d %2d  J %5.1f %5.1f %5.1f  E %5.1f",
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