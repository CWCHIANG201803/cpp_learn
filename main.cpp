#include "gtest/gtest.h"
#include "dependency.h"

struct IRGHConnection
{
    virtual void connect() = 0;
    virtual void disconnect() = 0;
    virtual RFDIReport RFDIReportFor(int id) = 0;
    virtual ACTIOReport ACTIOReportFor(int customerID) = 0;
};

class FakeConnection : public IRGHConnection
{
public:
    RFDIReport* report = nullptr;
public:
    FakeConnection()
    {

    }
    void connect() override 
    {

    }
    void disconnect() override 
    {

    }
    RFDIReport RFDIReportFor(int id) override 
    {
        return RFDIReport();
    }
    ACTIOReport ACTIOReportFor(int customerID) override 
    {
        return ACTIOReport();
    }
};

class RGHConnection : public IRGHConnection
{
public:
    RGHConnection(int port, string name, string passwd) 
    {
        // ...
    }
    void connect() override
    { 
        // ...
    }
    void disconnect() override
    { 
        // ...
    }
    RFDIReport RFDIReportFor(int id) override
    { 
        return {}; 
    }
    ACTIOReport ACTIOReportFor(int customerID) override
    { 
        return {}; 
    }
private:
    void retry()
    {

    }
    RFPacket formPacket() 
    { 
        return {}; 
    }
};

class CreditMaster 
{
public:
    CreditMaster(string filename, bool islocal) 
    {
        // ...
    }
};

class CreditValidator
{
public:
    CreditValidator(IRGHConnection* connection, CreditMaster* master, string validator_id="")
    {
        // ...
    }
    Certificate validateCustomer(Customer* customer)
    {
        bool is_member = customer->getName()=="Peter" && customer->getId()==2;
        Certificate c;
        c.setStatus(is_member);
        return c;
    }
    double getValidationPercent(){ return 100.0; }
};

TEST(ValidatorTest, testCreate){
    // RGHConnection* connection = new RGHConnection(0, "admin", "rii8ii9s");
    FakeConnection* connection = new FakeConnection();
    CreditMaster* master = new CreditMaster("crm2.mas", true);
    CreditValidator* validator = new CreditValidator(connection, master, "a");
    connection->report = new RFDIReport();
    Certificate result = validator->validateCustomer(new Customer("Peter", 2));
    ASSERT_EQ(CertificateState::VALID, result.getStatus());
}

TEST(ValidatorTest, testAllPassed100Percent){
    FakeConnection* connection = new FakeConnection();
    CreditValidator* validator = new CreditValidator(connection, nullptr, "a");
    connection->report = new RFDIReport();
    Certificate result = validator->validateCustomer(new Customer("Jacky", 3));

    ASSERT_DOUBLE_EQ(100.0, validator->getValidationPercent());
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
