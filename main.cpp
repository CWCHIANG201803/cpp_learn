#include "dependency.h"

// WorkflowEngine.h
/*
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

*/
class WorkflowEngine {
private:
  TransactionManager *tm;
  Config AppConfig;
protected:
  TransactionManager *getTransactionManager();
public:
  WorkflowEngine();
};

WorkflowEngine::WorkflowEngine() :tm (nullptr) {
  // ...
}

TransactionManager* WorkflowEngine::getTransactionManager() {

  if (tm == nullptr) {
    Reader *reader = new ModelReader(AppConfig.getDryConfiguration());
    Persister *persister = new XMLStore(AppConfig.getDryConfiguration());
    tm = new TransactionManager(reader,persister);
  }
  return tm;
}


int main(int, char**) {
    return 0;
}