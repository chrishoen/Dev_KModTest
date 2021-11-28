
#include "stdafx.h"

#include "cmnPeriodicParms.h"
#include "cmnStrobeParms.h"
#include "someStrobeThread.h"
#include "someMyDev.h"

#include "CmdLineExec.h"

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
   if (aCmd->isCmd("W"))         executeWriteA(aCmd);
   if (aCmd->isCmd("R"))         executeReadB(aCmd);
   if (aCmd->isCmd("test"))      executeTest(aCmd);

   if (aCmd->isCmd("0"))         executeFn0(aCmd);
   if (aCmd->isCmd("1"))         executeFn1(aCmd);

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
   Some::gMyDev.writeA(aCmd->argBool(1));
}

//******************************************************************************
//******************************************************************************
//******************************************************************************

void CmdLineExec::executeReadB(Ris::CmdLineCmd* aCmd)
{
}

//******************************************************************************
//******************************************************************************
//******************************************************************************

void CmdLineExec::executeTest(Ris::CmdLineCmd* aCmd)
{
   int tValue = aCmd->argInt(1);
   Prn::print(0, "Value1 %d", tValue);

   Some::gMyDev.doTest1(&tValue);
   Prn::print(0, "Value2 %d", tValue);
}

//******************************************************************************
//******************************************************************************
//******************************************************************************

void CmdLineExec::executeFn0(Ris::CmdLineCmd* aCmd)
{
   Prn::unsuppressPrint();
   Prn::setFilter(Prn::Show1, false);
   Prn::setFilter(Prn::Show2, false);
}

//******************************************************************************
//******************************************************************************
//******************************************************************************

void CmdLineExec::executeFn1(Ris::CmdLineCmd* aCmd)
{
   Prn::unsuppressPrint();
   Prn::setFilter(Prn::Show1, true);
   Prn::setFilter(Prn::Show2, false);
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
   Cmn::gPeriodicParms.readSection("Periodic");
   Cmn::gPeriodicParms.show();

   Cmn::gStrobeParms.readSection("Strobe");
   Cmn::gStrobeParms.show();
}

//******************************************************************************
//******************************************************************************
//******************************************************************************

