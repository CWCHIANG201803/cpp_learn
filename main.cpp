#include "gtest/gtest.h"
#include "dependency.h"

class SerialTask
{
public:
    virtual void run(){
        std::cout << "run method from serial task" << std::endl;        
    }
    virtual void query(){
        std::cout << "query method from serial task" << std::endl;
    }
};

class ISchedulingTask
{
public:
    virtual void run() = 0;
};

class SchedulingTask : public SerialTask, public ISchedulingTask
{
public:
     virtual void run() override { SerialTask::run();}
};

class FakeSchedulingTask : public ISchedulingTask
{
public:
    virtual void run() override{
        std::cout << "run method from fake scheduling task" << std::endl;
    }
};

TEST(DependencyTest, testCase1)
{
    ISchedulingTask* task = new SchedulingTask();
    task->run();
    ISchedulingTask* fake_task = new FakeSchedulingTask();
    fake_task->run();
    // purpose: create a fake schedulingTask
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
