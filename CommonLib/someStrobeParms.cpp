//******************************************************************************
//******************************************************************************
//******************************************************************************

#include "stdafx.h"

#include "risCmdLineFile.h"

#define  _SOMESTROBEPARMS_CPP_
#include "someStrobeParms.h"

//******************************************************************************
//******************************************************************************
//******************************************************************************

namespace Some
{

//******************************************************************************
//******************************************************************************
//******************************************************************************
//******************************************************************************
//******************************************************************************
//******************************************************************************
// Constructor.

StrobeParms::StrobeParms()
{
   reset();
}

void StrobeParms::reset()
{
   BaseClass::reset();
   if (Ris::portableIsWindows())
   {
      BaseClass::setFilePath("c:/aaa_prime/files/Strobe_Parms.txt");
   }
   else
   {
      BaseClass::setFilePath("/opt/prime/files/Strobe_Parms.txt");
   }

   mDevPath[0] = 0;
   mTestCode1 = 0;
   mTestCode2 = 0;

}

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Show.

void StrobeParms::show()
{
   printf("\n");
   printf("StrobeParms************************************************ %s\n", mTargetSection);

   printf("\n");
   printf("DevPath                  %-10s\n", mDevPath);
   printf("\n");
   printf("TestCode1                %-10d\n", mTestCode1);
   printf("TestCode2                %-10d\n", mTestCode2);
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Base class override: Execute a command from the command file to set a 
// member variable.  Only process commands for the target section.This is
// called by the associated command file object for each command in the file.

void StrobeParms::execute(Ris::CmdLineCmd* aCmd)
{
   if (!isTargetSection(aCmd)) return;

   if (aCmd->isCmd("DevPath"))         aCmd->copyArgString(1, mDevPath, cMaxStringSize);
   if (aCmd->isCmd("TestCode1"))       mTestCode1 = aCmd->argInt(1);
   if (aCmd->isCmd("TestCode2"))       mTestCode2 = aCmd->argInt(1);
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Calculate expanded member variables. This is called after the entire
// section of the command file has been processed.

void StrobeParms::expand()
{
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
}//namespace