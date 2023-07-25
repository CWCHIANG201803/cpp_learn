#include "dependency.h"
#include "gtest/gtest.h"
#include <memory>
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
  virtual TransactionManager *getTransactionManager();
public:
  WorkflowEngine();
  void run(){}
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

class TestWorkflowEngine : public WorkflowEngine {
public:
  TransactionManager *getTransactionManager() override { 
    return &transactionManager; 
  }
private:
  FakeTransactionManager transactionManager;
};

TEST(TransactionCount, WorkflowEngine){
  std::unique_ptr<TestWorkflowEngine> engine(new TestWorkflowEngine);
  engine->run();
  ASSERT_EQ(0, engine->getTransactionManager()
                    ->getTransactionCount());
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


