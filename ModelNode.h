#include <list>

class ModelNode { 
public:
    virtual ~ModelNode() = 0;
    virtual void addExteriorNode(ModelNode *newNode) = 0; 
    virtual void addInternalNode(ModelNode *newNode) = 0; 
    virtual void colorize() = 0; 
// ...
};