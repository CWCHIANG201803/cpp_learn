#include <list>
#include <string>

class StyleTemplate {};

class StyleMaster {
public:
    static std::list<int> formStyles(StyleTemplate tmp, int id){
        return {};
    }
};
# ifdef old
class PageLayout {
private:
  int id = 0; 
  std::list<int> styles; 
  StyleTemplate tmp;
  //...
protected:
  void rebindStyles() {
    styles = StyleMaster::formStyles(tmp, id);
  }
};
#else
class PageLayout {
private:
  int id = 0; 
  std::list<int> styles; 
  StyleTemplate tmp;
  //...
protected:
  void rebindStyles() {
    styles = StyleMaster::formStyles(tmp, id);
  }
  std::list<int> formStyles(StyleTemplate tmpl, int id){
    return StyleMaster::formStyles(tmp, id);
  }
};
#endif
class TestingPageLayout : public PageLayout 
{
protected:
    std::list<int> formStyles(StyleTemplate tmpl, int id) {
        return std::list<int>();
    }
};

int main(int, char**) {
    return 0;
}