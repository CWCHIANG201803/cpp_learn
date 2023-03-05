#include <iostream>
#include <string>
#include <tuple>
#include <stdexcept>
#include <list>
#include <cstddef>
#include <concepts>
#include <vector>

template<typename T>
class Vector {
private:
    T* elem;
    int sz;
public:
    explicit Vector(int s);
    ~Vector(){ delete[] elem; }

    T& operator[](int i){ return elem[i]; }
    const T& operator[](int i) const;
    int size() const { return sz; }
};

template<typename T> 
Vector<T>::Vector(int s) {
    if (s<0) 
        throw std::invalid_argument("cannot be negative");
    elem = new T[s];
    sz = s;
}

template<typename T> 
const T& Vector<T>::operator[](int i) const {
    if (i<0 || size()<=i)
        throw std::out_of_range("Vector::operator[]");
    return elem[i];
}

template<typename T>
T* begin(Vector<T>& x) {
    return x.size() ? &x[0] : nullptr;
    // pointer to ﬁrst element or nullptr
}

template<typename T>
T* end(Vector<T>& x) {
    return x.size() ? &x[0]+x.size() : nullptr;
    // pointer to one-past-last element
}

void write(const Vector<std::string>& vs) {
    std::cout << "run with traditional loop" << std::endl;
    for (int i = 0; i!=vs.size(); ++i)
        std::cout << vs[i] << '\n';
}

void f2(Vector<std::string>& vs) {
    std::cout << "run with range for loop" << std::endl;
    for (auto& s : vs)
        std::cout << s << '\n';
}



int main(int, char**) {

    Vector<char> vc(200);
    Vector<std::string> vs(5);
    Vector<std::list<int>> vli(45);
    vs[0] = "how are you";
    vs[4] = "nice to meet you";
    // write(vs);
    f2(vs);
    return 0;
}
