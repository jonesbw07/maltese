#include "MalteseApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"

template<>
InputParameters validParams<MalteseApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

MalteseApp::MalteseApp(const std::string & name, InputParameters parameters) :
    MooseApp(name, parameters)
{
  srand(libMesh::processor_id());
  
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  MalteseApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  MalteseApp::associateSyntax(_syntax, _action_factory);
}

MalteseApp::~MalteseApp()
{
}

extern "C" void MalteseApp__registerApps() { MalteseApp::registerApps(); }
void
MalteseApp::registerApps()
{
  registerApp(MalteseApp);
}

void
MalteseApp::registerObjects(Factory & factory)
{
}

void
MalteseApp::associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
}
