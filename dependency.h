#include <string>

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

class TransactionManager{
public:
  TransactionManager(Reader* reader, Persister* persister){}
};

class ModelReader : public Reader {
public:
  ModelReader(std::string config): Reader(){}
};

class XMLStore : public Persister {
public:
  XMLStore(std::string config): Persister(){}
};