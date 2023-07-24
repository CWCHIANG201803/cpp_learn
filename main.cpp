#include "dependency.h"

// WorkflowEngine.h

class WorkflowEngine { 
private:
  Config AppConfiguration;
  TransactionManager* tm;
public:
  WorkflowEngine ();
  //... 
};

// WorkflowEngine.cpp
WorkflowEngine::WorkflowEngine() {
  Reader *reader = new ModelReader(AppConfiguration.getDryConfiguration());
  Persister* persister = new XMLStore(AppConfiguration.getDryConfiguration());
  tm = new TransactionManager(reader, persister);
  // ...
};


int main(int, char**) {
    return 0;
}