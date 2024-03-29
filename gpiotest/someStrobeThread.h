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

   // Base class overloads.
   void executeOnTimer(int aTimeCount) override;
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


