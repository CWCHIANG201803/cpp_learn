#include "gtest/gtest.h"
#include "dependency.h"

struct IRGHConnection
{
    virtual void connect() = 0;
    virtual void disconnect() = 0;
    virtual RFDIReport RFDIReportFor(int id) = 0;
    virtual ACTIOReport ACTIOReportFor(int customerID) = 0;
};

class RGHConnection 
{
public:
    RGHConnection(int port, string name, string passwd) 
    {
        // ...
    }
    void connect()
    { 
        // ...
    }
    void disconnect()
    { 
        // ...
    }
    RFDIReport RFDIReportFor(int id) 
    { 
        return {}; 
    }
    ACTIOReport ACTIOReportFor(int customerID) 
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
    CreditValidator(RGHConnection* connection, CreditMaster* master, string validator_id)
    {
        // ...
    }
    Certificate validateCustomer(Customer customer)
    {
        return Certificate();
    }
};

TEST(Demo, testCreate){
    RGHConnection* connection = new RGHConnection(0, "admin", "rii8ii9s");
    CreditMaster* master = new CreditMaster("crm2.mas", true);
    CreditValidator* validator = new CreditValidator(connection, master, "a");
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
