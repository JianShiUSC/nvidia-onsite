Fundamental concept of OOPs: Encapsulation, Inheritance, Polymorphism, Abstraction
What is Encapsulation: The process of binding the data and the functions acting on the data together in a class called as encapsulation.
What is Abstraction: Abstraction refers to hiding the internal implementation and exhibiting only the necessary details.
What is Inheritance: Inheritance is the process of acquiring the properties of the existing class into the new class.(parent and child class)
What is keyword volatile: Declaring a variable volatile directs the compiler that the variable can be changed externally. Hence avoiding compiler optimization on the variable reference.
What is an inline function: The inline functions are faster in execution when compared to normal functions as the compiler treats inline functions as macros.
What is a storage class: Storage class specifies the life or scope of symbols such as variable or functions.(auto, static, extern, register, mutable)

What is Pure Virtual function: A pure virtual function implicitly makes the class it is defined for abstract. Abstract classes cannot be instantiated. Derived classes need to override/implement all inherited pure virtual functions. If they do not, they too will become abstract. Briefly, its to make the class abstract, so that it cant be instantiated, but a child class can override the pure virtual methods to form a concrete class. This is a good way to define an interface in C++.
What is Virtual function: A virtual function makes its class a polymorphic base class. Derived classes can override virtual functions(need to provide implementation in the base class). Virtual functions called through base class pointers/references will be resolved at runtime.

// pure virtual function
class AbstractBase {
public:
    virtual void PureVirtualFunction() = 0;    // a pure virtual function
    // note that there is no function body
};

class Derived : public AbstractBase {
    virtual void PureVirtualFunction() override {

    }
};

// virtual function
class Animal {
public:
    virtual void eat() { cout << "I'm eating generic food." << endl; }
};

class Sheep : public Animal {
public:
    void eat() { cout << "Sheep eats grass!" << endl; }
};

What is abstract class: A class with at least one pure virtual function.
Role of static keyword on class member variable: A static variable does exist though the objects for the respective class are not created. Static member variable share a common memory across all the objects created for the respective class. A static member variable can be referred using the class name itself. A static variable retains its value between the function call and the default value is 0.
// the function will print 1, 2, 3 if called three times
void f() {
    static int i;
    ++i;
    printf("%d", i);
}

What is static member function: A static member function can be invoked using the class name as it exists before class objects come into existence. It can only access static members of the class.

What is function overloading: Define several functions with the same name with unique list of parameters is called function overloading.
What is function overriding: Defining the functions within the base and derived class with the same signature and name, where the base class function is virtual.

'new' is the operator can be used to allocate dynamic memory
'delete' is used to release the dynamic memory which was created using 'new' operator

What is Friend Function: A function which is not a member of the class but can still access all the members of the class is called so. To make it happen we need to declare within the required class following the keyword 'friend'.
What is a Friend Class: A class member can gain accessibility over other class member by placing the class declaration prefixed with the key word 'friend' in the destination class.

class B {
    friend class A; // A is a friend of B
private:
    int i;
};

class A {
public:
    A(B b) {
        b.i = 0;    // legal access due to friendship
    }
};

Where an automatic variable is stored: Every local variable by default being an auto variable is stored in stack memory.
What is difference between including the header file within < > and " ": using " " prioritizes headers in the current working directory over system headers.  < > usually is used for system headers.
