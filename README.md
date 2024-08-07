# BCC3004-Design-Patterns
## Exemplo de padrão criacional: Prototype
**Problema:**
Você precisa criar uma cópia exata de um objeto, evitando a criação de novos objetos do zero

**Solução:**
O prototype permite com que você copie objetos sem depenndência de classes, garantindo a independência das cópias

```
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

```
O código acima define a classe 'Prototype' como a interface que servirá de base para a cópia de objetos e cria uma instância de 'ConcreteProtype' e clona ela. Note que as instâncias são independentes

## Exemplo de padrão estrututal: Adapter
**Problema:**
Você possui uma interface existente incompatível com a interface que você precisa

**Solução:**
O adapter permite objetos de diferentes interfaces trabalharem juntos, convertendo interfaces
```

entry converterXmlParaStruct
	params
		string vLista, vItems, vStruct
	endparams
	
	putitem/id vItems, "NAMESPACE", "http://www.teste.com" ;preechendo lista com valores
	putitem/id vItems, "LOCATION", "teste.xsd"
	
	putitem vLista, -1, vItems                             ;encadeando lista
	
	xmlToStruct vStruct, "arquivo.xml", vLista             ;convertendo um xml para uma struct
	
	return(0)
end

```
O código acima é uma função em procScript, que converte uma lista encadeada (XML) para um Struct, que poderia ser utilizado por outra interface
## Exemplo de padrão comportamental: Chain of resposability
**Problema:**
Você precisa criar uma solicitação que passe por vários objetos, de modo que o receptor não seja especificado

**Solução:**
O Chain of responsability permite com que uma informação passe por uma cadeia de handlers, que manipulam os dados

```
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

```
O código acima possui uma classe 'handler' que seria uma interface para manipulação, e as classes 'concretehandler' processam as informações
