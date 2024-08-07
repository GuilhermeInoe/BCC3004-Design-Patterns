#include <iostream>
#include <string>

class Handler {
protected:
    Handler* successor;
public:
    Handler() : successor(nullptr) {}
    void setSuccessor(Handler* s) {
        successor = s;
    }
    virtual void handle(const std::string& request) {
        if (successor) {
            successor->handle(request);
        }
    }
    virtual ~Handler() = default;
};

class ConcreteHandler1 : public Handler {
public:
    void handle(const std::string& request) override {
        if (request == "R1") {
            std::cout << "ConcreteHandler1 handled request" << std::endl;
        } else {
            Handler::handle(request);
        }
    }
};

class ConcreteHandler2 : public Handler {
public:
    void handle(const std::string& request) override {
        if (request == "R2") {
            std::cout << "ConcreteHandler2 handled request" << std::endl;
        } else {
            Handler::handle(request);
        }
    }
};

class ConcreteHandler3 : public Handler {
public:
    void handle(const std::string& request) override {
        if (request == "R3") {
            std::cout << "ConcreteHandler3 handled request" << std::endl;
        } else {
            Handler::handle(request);
        }
    }
};

// Uso
int main() {
    ConcreteHandler1* handler1 = new ConcreteHandler1();
    ConcreteHandler2* handler2 = new ConcreteHandler2();
    ConcreteHandler3* handler3 = new ConcreteHandler3();

    handler1->setSuccessor(handler2);
    handler2->setSuccessor(handler3);

    handler1->handle("R2");  // ConcreteHandler2 handled request
    handler1->handle("R3");  // ConcreteHandler3 handled request
    handler1->handle("R1");  // ConcreteHandler1 handled request

    delete handler1;
    delete handler2;
    delete handler3;

    return 0;
}
