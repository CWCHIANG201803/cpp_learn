#include "ModelNode.h"
#include <list>

class ProductioModelNode : public ModelNode{ 
private:
    std::list<ProductioModelNode *> m_interiorNodes;
    std::list<ProductioModelNode *> m_exteriorNodes;
    double m_weight;
    void createSpanningLinks();

public:
    void addExteriorNode(ProductioModelNode *newNode) override; 
    void addInternalNode(ProductioModelNode *newNode) override; 
    void colorize() override; 
// ...
};