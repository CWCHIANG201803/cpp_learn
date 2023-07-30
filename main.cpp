#include "gtest/gtest.h"
#include "dependency.h"
#include <exception>

class PermitRepository { 
private: 
	static PermitRepository* instance;
protected:
	PermitRepository() {}
public: 
	static void setTestingInstance(PermitRepository* newInstance) {
		instance = newInstance;
	}

	static PermitRepository* getInstance() { 
		if (instance == nullptr) { 
			instance = new PermitRepository(); 
		} 
		return instance; 
	}

	virtual Permit* findAssociatedPermit(PermitNotice* notice) { 
		return new Permit(notice);
	} 
	// ...
};
PermitRepository* PermitRepository::instance = nullptr;

class TestingPermitRepository : public PermitRepository {
private:
    map<PermitNotice*,Permit*> permits;
public:
    void addAssociatedPermit(PermitNotice* notice, Permit* permit) {
        permits.insert({notice, permit});
    }
    Permit* findAssociatedPermit(PermitNotice* notice) override {
        return permits[notice];
    }
};

class Facility { 
private: 
	Permit* basePermit = nullptr;
public:
	Facility(int facilityCode, std::string owner, PermitNotice* notice) {
		Permit* associatedPermit = PermitRepository::getInstance()->findAssociatedPermit(notice);
		if (associatedPermit->isValid() && !notice->isValid()) { 
			basePermit = associatedPermit; 
		} else if (!notice->isValid()) {
			Permit* permit = new Permit(notice);
			permit->validate();
			basePermit = permit; 
		} else{
            // throw new exception();
        }
	}
};


TEST(IrritatingGlobalDependencyTest, test1){
    PermitNotice* notice = new PermitNotice(0, "a");
    Facility* facility = new Facility(1, "b", notice);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
