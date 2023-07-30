#include <string>
#include <map>
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

enum class CertificateState {
  VALID, INVALID
};
class Certificate {
  CertificateState state_;
public:
  Certificate(){}
  void setStatus(bool is_member){
    state_ = is_member ? 
    CertificateState::VALID :
    CertificateState::INVALID;
  }
  CertificateState getStatus()
  { 
    return state_;
  }
};

class Customer {
  std::string name_;
  int id_;
public:
  Customer(std::string name="", int id=-1): name_(name), id_(id){
  }
  std::string getName(){ return name_;}
  int getId(){ return id_;}
};

struct RFDIReport {

};

struct ACTIOReport {

};

struct RFPacket {

};


struct PermitNotice{
    PermitNotice(int id, string name){}
    bool isValid(){ return true;}
};

class Permit {
public:
    Permit(PermitNotice* notice){}
    bool isValid(){ return false;}
    void validate(){}
};
