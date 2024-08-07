#include <iostream>
#include <string>
#include <memory>

class Prototype {
public:
    virtual std::shared_ptr<Prototype> clone() const = 0;
    virtual void print() const = 0;
    virtual ~Prototype() = default;
};

class ConcretePrototype : public Prototype {
private:
    int value;
public:
    ConcretePrototype(int val) : value(val) {}
    std::shared_ptr<Prototype> clone() const override {
        return std::make_shared<ConcretePrototype>(*this);
    }
    void print() const override {
        std::cout << "ConcretePrototype with value: " << value << std::endl;
    }
};

// Uso
int main() {
    std::shared_ptr<Prototype> prototype = std::make_shared<ConcretePrototype>(42);
    std::shared_ptr<Prototype> clone = prototype->clone();

    prototype->print();  // ConcretePrototype with value: 42
    clone->print();      // ConcretePrototype with value: 42

    return 0;
}
