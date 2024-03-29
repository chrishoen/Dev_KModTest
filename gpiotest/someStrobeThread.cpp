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
         Cmn::gPeriodicParms.mTestThreadProcessor,
         Cmn::gPeriodicParms.mTestThreadPriority));

   // Set timer period.
   BaseClass::mPollProcessor = Cmn::gPeriodicParms.mPollProcessor;
   BaseClass::mStatPeriod = Cmn::gPeriodicParms.mStatPeriod;
   BaseClass::mPeriodUs = Cmn::gPeriodicParms.mPeriodUs;

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