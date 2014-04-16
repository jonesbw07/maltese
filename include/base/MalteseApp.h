#ifndef MALTESEAPP_H
#define MALTESEAPP_H

#include "MooseApp.h"

class MalteseApp;

template<>
InputParameters validParams<MalteseApp>();

class MalteseApp : public MooseApp
{
public:
  MalteseApp(const std::string & name, InputParameters parameters);
  virtual ~MalteseApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* MALTESEAPP_H */
