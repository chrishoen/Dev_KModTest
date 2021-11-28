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

#include "somePeriodicParms.h"
#include "cmnGPIO.h"

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
}

//******************************************************************************
//******************************************************************************
//******************************************************************************

void StrobeThread::executeOnTimer(int aTimeCount)
{
   if (!mTPFlag) return;

   Cmn::gGPIO.writeA(aTimeCount % 2);
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
}//namespace