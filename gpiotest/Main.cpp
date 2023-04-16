#include "stdafx.h"

#include "risThreadsProcess.h"
#include "risCmdLineConsole.h"
#include "CmdLineExec.h"
#include "MainInit.h"

#include "cmnPeriodicParms.h"
#include "someStrobeThread.h"
#include "someMonitorThread.h"

//******************************************************************************
//******************************************************************************
//******************************************************************************

int main(int argc,char** argv)
{
   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Initialize program.

   main_initialize(argc,argv);

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Launch program threads.

   if (false)
   {
      Some::gStrobeThread = new Some::StrobeThread;
      Some::gStrobeThread->launchThread();
   }
   if (false)
   {
      Some::gMonitorThread = new Some::MonitorThread;
      Some::gMonitorThread->launchThread();
   }

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Show program threads.

   Ris::Threads::showCurrentThreadInfo();
   if (Some::gStrobeThread) Some::gStrobeThread->showThreadInfo();
   if (Some::gMonitorThread) Some::gMonitorThread->showThreadInfo();

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Start user command line executive, wait for user to exit.

   CmdLineExec* exec = new CmdLineExec;
   Ris::executeCmdLineConsole(exec);
   delete exec;

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Shutdown program Threads.
   if (Some::gStrobeThread)
   {
      Some::gMonitorThread->shutdownThread();
      delete Some::gMonitorThread;
      Some::gMonitorThread = 0;
   }

   if (Some::gMonitorThread)
   {
      Some::gStrobeThread->shutdownThread();
      delete Some::gStrobeThread;
      Some::gStrobeThread = 0;
   }

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Finalize program.

   main_finalize();
   return 0;
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
