#include "stdafx.h"

#include <sys/mman.h>

#include "risThreadsProcess.h"
#include "cmnPeriodicParms.h"
#include "cmnStrobeParms.h"

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Initialize program resources.

void main_initialize(int argc,char** argv)
{
   printf("strobe Program****************************************BEGIN\n");
   printf("strobe Program****************************************BEGIN\n");
   printf("strobe Program****************************************BEGIN\n\n");

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Lock memory.

   mlockall(MCL_CURRENT | MCL_FUTURE);

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Enter process.

   Ris::Threads::enterProcessHigh();

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Program arguments.

   char tParmsPath[100];
   strcpy(tParmsPath, "/opt/prime/files/Program_Parms.txt");

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Initialize parms.

   // Read parameters files.
   Cmn::gStrobeParms.reset();
   Cmn::gStrobeParms.setFilePath(tParmsPath);
   Cmn::gStrobeParms.readSection("Strobe");

   // Read parameters files.
   Cmn::gPeriodicParms.reset();
   Cmn::gPeriodicParms.setFilePath(tParmsPath);
   Cmn::gPeriodicParms.readSection("Periodic");

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Initialize print facility.

   // Initialize print.
   Prn::resetPrint();
   Prn::useConsole(1);
   Prn::useConsole(2);
   Prn::initializePrint();

   // Initialize print filters.
   Prn::setFilter(Prn::ThreadInit1,     true);
   Prn::setFilter(Prn::ThreadRun1,      true);
   Prn::setFilter(Prn::ThreadRun2,      false);
   Prn::setFilter(Prn::ThreadRun3,      false);
   Prn::setFilter(Prn::ThreadRun4,      false);

   Prn::setFilter(Prn::View11, true, 1);
   Prn::setFilter(Prn::View12, false, 1);
   Prn::setFilter(Prn::View21, true, 2);
   Prn::setFilter(Prn::View22, false, 2);
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Finalize program resources.

void main_finalize()
{
   // Finalize print facility.
   Prn::finalizePrint();

   // Exit process.
   Ris::Threads::exitProcess();

   // Done.
   printf("\n");
   printf("strobe Program****************************************END\n\n");
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
