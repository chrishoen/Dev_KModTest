
#include "stdafx.h"

#include "cmnGPIO.h"
#include "CmdLineExec.h"

#include "cmnPeriodicParms.h"
#include "someStrobeThread.h"

//******************************************************************************
//******************************************************************************
//******************************************************************************

CmdLineExec::CmdLineExec()
{
}

void CmdLineExec::reset()
{
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
// This class is the program command line executive. It processes user
// command line inputs and executes them. It inherits from the command line
// command executive base class, which provides an interface for executing
// command line commands. It provides an override execute function that is
// called by a console executive when it receives a console command line input.
// The execute function then executes the command.

void CmdLineExec::execute(Ris::CmdLineCmd* aCmd)
{
   if (aCmd->isCmd("TP"))        Some::gStrobeThread->mTPFlag = aCmd->argBool(1);
   if (aCmd->isCmd("A"))         executeWriteA(aCmd);
   if (aCmd->isCmd("B"))         executeReadB(aCmd);

   if (aCmd->isCmd("GO1"))       executeGo1(aCmd);
   if (aCmd->isCmd("GO2"))       executeGo2(aCmd);
   if (aCmd->isCmd("GO3"))       executeGo3(aCmd);
   if (aCmd->isCmd("GO4"))       executeGo4(aCmd);
   if (aCmd->isCmd("Parms"))     executeParms(aCmd);
}

//******************************************************************************
//******************************************************************************
//******************************************************************************

void CmdLineExec::executeWriteA(Ris::CmdLineCmd* aCmd)
{
   aCmd->setArgDefault(1, false);
   Cmn::gGPIO.writeA(aCmd->argBool(1));
}

//******************************************************************************
//******************************************************************************
//******************************************************************************

void CmdLineExec::executeReadB(Ris::CmdLineCmd* aCmd)
{
   Prn::print(0,"GpioB %d",Cmn::gGPIO.readB());
}

//******************************************************************************
//******************************************************************************
//******************************************************************************

void CmdLineExec::executeGo1(Ris::CmdLineCmd* aCmd)
{
}

//******************************************************************************
//******************************************************************************
//******************************************************************************

void CmdLineExec::executeGo2(Ris::CmdLineCmd* aCmd)
{
}

//******************************************************************************
//******************************************************************************
//******************************************************************************

void CmdLineExec::executeGo3(Ris::CmdLineCmd* aCmd)
{
}

//******************************************************************************
//******************************************************************************
//******************************************************************************

void CmdLineExec::executeGo4(Ris::CmdLineCmd* aCmd)
{
}

//******************************************************************************
//******************************************************************************
//******************************************************************************

void CmdLineExec::executeParms(Ris::CmdLineCmd* aCmd)
{
   Cmn::gPeriodicParms.reset();
   Cmn::gPeriodicParms.readSection("default");
   Cmn::gPeriodicParms.show();
}

//******************************************************************************
//******************************************************************************
//******************************************************************************

