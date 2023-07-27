#include <string>
using namespace std;

class Persister {
public:
  Persister(){}
};

class Reader {
public:
  Reader(){}
};

class Config {
public:
  std::string getDryConfiguration() const{
    return "";
  }
};


class TransactionManager {
public:
  TransactionManager(Reader* reader, Persister* persister){}
  virtual int getTransactionCount() {
    return 3;
  }
};

class FakeTransactionManager : public TransactionManager{
public:
  FakeTransactionManager(): TransactionManager(nullptr, nullptr){}
  int getTransactionCount() override {
    return 0;
  }
};

class ModelReader : public Reader {
public:
  ModelReader(std::string config): Reader(){}
};

class XMLStore : public Persister {
public:
  XMLStore(std::string config): Persister(){}
};

class Certificate {
public:
  Certificate(){}
};
class Customer {
public:
  Customer(){}
};

struct RFDIReport {

};

struct ACTIOReport {

};

struct RFPacket {

};