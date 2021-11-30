#pragma once

/*==============================================================================
Timer test thread.
==============================================================================*/

//******************************************************************************
//******************************************************************************
//******************************************************************************

#include "risThreadsPeriodicThread.h"

namespace Some
{
//******************************************************************************
//******************************************************************************
//******************************************************************************

class StrobeThread : public Ris::Threads::BasePeriodicThread
{
public:
   typedef Ris::Threads::BasePeriodicThread BaseClass;

   //******************************************************************************
   //******************************************************************************
   //******************************************************************************
   // Members.

   // If true then enable timer execution function.
   bool mTPFlag;

   //******************************************************************************
   //******************************************************************************
   //******************************************************************************
   // Members.

   //******************************************************************************
   //******************************************************************************
   //******************************************************************************
   // Methods.

   // Constructor.
   StrobeThread();

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Methods. Thread base class overloads.

   // Thread init function. This is called by the base class immediately 
   // after the thread starts running.
   void threadInitFunction() override;

   // Thread exit function. This is called by the base class immediately
   // before the thread is terminated.
   void threadExitFunction() override;

   // Thread shutdown function.
   void shutdownThread() override;

   // Execute periodically. This is called by the base class timer.
   void executeOnTimer(int aTimerCount) override;

};

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Global instance

#ifdef _SOMESTROBETHREAD1_CPP_
          StrobeThread* gStrobeThread = 0;
#else
   extern StrobeThread* gStrobeThread;
#endif

//******************************************************************************
//******************************************************************************
//******************************************************************************
}//namespace


