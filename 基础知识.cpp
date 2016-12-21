Fundamental concept of OOPs: Encapsulation, Inheritance, Polymorphism, Abstraction
What is Encapsulation: The process of binding the data and the functions acting on the data together in a class called as encapsulation.
What is Abstraction: Abstraction refers to hiding the internal implementation and exhibiting only the necessary details.
What is Inheritance: Inheritance is the process of acquiring the properties of the existing class into the new class.(parent and child class)
What is keyword volatile: Declaring a variable volatile directs the compiler that the variable can be changed externally. Hence avoiding compiler optimization on the variable reference.

static int foo;
void bar(void) {
    foo = 0;
    while (foo != 255)
         ;
}
An optimizing compiler will notice that no other code can possibly change the value stored in foo, and will assume that it will remain equal to 0 at all times. The compiler will therefore replace the function body with an infinite loop similar to this:
void bar_optimized(void) {
    foo = 0;
    while (true)
         ;
}
However, foo might represent a location that can be changed by other elements of the computer system at any time, such as a hardware register of a device connected to the CPU. The above code would never detect such a change; without the volatile keyword, the compiler assumes that the current program is the only part of the system that could change the value.
static volatile int foo;
void bar (void) {
    foo = 0;
    while (foo != 255)
        ;
}


What is an inline function: The inline functions are faster in execution when compared to normal functions as the compiler treats inline functions as macros.
What is a storage class: Storage class specifies the life or scope of symbols such as variable or functions.(auto, static, extern, register, mutable)

// header:
#ifndef HEADER_H
#define HEADER_H

// any source file that includes this will be able to use "global_x"
extern int global_x;
void print_global_x();
#endif

// source 1:
#include "header.h"
// it needs to be defined somewhere
int global_x;
int main() {
    //set global_x here:
    global_x = 5;
    print_global_x();
}

// source 2:
#include <iostream>
#include "header.h"
void print_global_x() {
    //print global_x here:
    cout << global_x << endl;
}



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

操作系统的基本功能和四个特性：功能：内存的分配和管理，processor的控制和管理，外设的控制和管理，文件的控制和管理，task的控制和管理
四个特性：Concurrence, Sharing, Virtual, Asynchronism

Kernel mode: code has unrestricted access to the underlying hardware. It can execute any CPU instruction and reference any memory address. Kernel mode is reserved for the lowest level, most trusted functions of the Operationg Systems. Crashes in Kernel mode are catastrophic.
User mode: code cant access hardware or memory. Must delegate to system APIs to access hardware or memory. Crashes in user mode are always recoverable.

Process VS Thread: Process provides the resources needed to execute the program. A process has at least one thread of execution. Each process is started with a single thread, often called the primary thread, but can create additional threads from any of its threads.
A thread is the entity within a process that can be scheduled for execution.
The typical difference is that threads of the same process run in a shared memory space, while processes run in separate memory spaces.
1) processes are typically independent, while threads exist as subsets of a process
2) processes carry considerably more state information than threads, whereas multiple threads within a process share process state as well as memory and other resources
3) processes have separate address spaces, whereas threads share their address space
4) processes interact only through system-provided inter-process communication mechanisms
5) Context switching between threads in the same process is typically faster than context switching between processes.

进程的三种状态：就绪，执行，阻塞(created, ready, running, blocked, terminated)

进程死锁的条件：
1. 互斥条件：某个资源只能由一个进程占用
2. 请求和保持条件：一个进程因请求资源而阻塞时，对已获得的资源保持不放
3. 不剥夺条件：进程已获得的资源，在未使用完之前，不能强行剥夺
4. 循环等待条件：若干进程之间形成一种头尾相接的循环等待资源关系

进程间通信方式：inter-process communication(IPC) is the mechanisms that an operating system allows processes to share data and communicate with each other. Typically, applications can use IPC, categorized as clients and servers, where the client requests data and the server responds to client requests. This allows a program to handle many user requests at the same time. Since even a single user request may result in multiple processes running in the operating system, the processes need to communicate with each other. Each IPC method has its own advantages and limitations so it is not unusual for a single program to use all of the IPC methods.

线程间通信方式:
1) share memory or object
2) message queue
In computer science, message queues and mailboxes are software-engineering components used for inter-process communication (IPC), or for inter-thread communication within the same process. They use a queue for messaging – the passing of control or of content. Group communication systems provide similar kinds of functionality.
message queue //https://www.cloudamqp.com/blog/2014-12-03-what-is-message-queuing.html

进程调度算法：
First Come First Serve scheduling
Shortest Job Next Scheduling
Priority scheduling
Shortest Remaining time
Round Robin scheduling
Multiple-Level Queues Scheduling
**These algorithms are either non-preemptive or preemptive
//https://www.tutorialspoint.com/operating_system/os_process_scheduling_algorithms.htm

makefile文件的作用是: A makefile is a file containing a set of directives used with the make build automation tool.
Most often, the makefile directs make on how to compile and link a program. Using C/C++ as an example, when a C/C++ source file is changed, it must be recompiled. If a header file has changed, each C/C++ source file that includes the header file must be recompiled to be safe. Each compilation produces an object file corresponding to the source file. Finally, if any source file has been recompiled, all the object files, whether newly made or saved from previous compilations, must be linked together to produce the new executable program. These instructions with their dependencies are specified in a makefile. If none of the files that are prerequisites have been changed since the last time the program was compiled, no actions take place. For large software projects, using Makefiles can substantially reduce build times if only a few source files have changed.
// https://en.wikipedia.org/wiki/Makefile

execve() replaces the current executable image with another one loaded from an executable file.
fork() creates a child process.
vfork() is a historical optimized version of fork(), meant to be used when execve() is called directly after fork(). It turned out to work well in non-MMU systems (where fork() cannot work in an efficient manner) and when fork()ing processes with a huge memory footprint to run some small program (think Javas Runtime.exec()). POSIX has standardized the posix_spawn() to replace these latter two more modern uses of vfork().
posix_spawn() does the equivalent of a fork()/execve(), and also allows some fd juggling in between. Its supposed to replace fork()/execve(), mainly for non-MMU platforms.
pthread_create() creates a new thread.
clone() is a Linux-specific call, which can be used to implement anything from fork() to pthread_create(). It gives a lot of control.


An intrinsic function is a function available for use in a given programming language whose implementation is handled specially by the compiler. Typically, it substitutes a sequence of automatically generated instructions for the original function call, similar to an inline function. Unlike an inline function though, the compiler has an intimate knowledge of the intrinsic function and can therefore better integrate it and optimize it for the situation. This is also called builtin function in many languages. e.g.most standard library functions that the compiler can/will generate inline instead of calling an actual function in the library


difference between new/delete and malloc/free
// http://stackoverflow.com/questions/240212/what-is-the-difference-between-new-delete-and-malloc-free

_aligned_malloc(): This function is useful when the alignment of your memory allocation is important to you. Alignment means that the numerical value of the pointer returned must be evenly divisible by a certain number, ie. ((unsigned int)ptr) % alignment should evaluate to 0.

int strCmp(const char* s1, const char* s2) {
    while(*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return *(const unsigned char*)s1 - *(const unsigned char*)s2;
}

Name: aligned_malloc
Arguments: number of bytes & Alignment Boundry
Return : NULL on error
valid pointer on success

Working	: It will allocate memory with starting address
multiple of alignment passed and returns pointer
to it on success.

Ex.
aligned_malloc(50,128);
This will allocate 50 bytes of memory with starting address multiple of 128.

void *aligned_malloc(size_t bytes, size_t alignment) {
    void *p1 ,*p2; // basic pointer needed for computation.

    /* We need to use malloc provided by C.
    First we need to allocate memory of size bytes + alignment + sizeof(size_t).
    We need 'bytes' because user requested it.
    We need to add 'alignment' because malloc can give us any address and we need to
    find multiple of 'alignment', so at maximum multiple of alignment will be 'alignment' bytes away from any location.
    We need 'sizeof(size_t)' for implementing 'aligned_free', since we are returning modified memory pointer,
    not given by malloc, to the user, we must free the memory allocated by malloc not anything else.
    So I am storing address given by malloc just above pointer returning to user.
    Thats why I need extra space to store that address. Then I am checking for error returned by malloc, if it returns NULL
    then aligned_malloc will fail and return NULL.
    */
    if((p1 =(void *) malloc(bytes + alignment + sizeof(size_t)))==NULL)
    return NULL;

    /*	Next step is to find aligned memory address multiples of alignment.
    By using basic formule I am finding next address after p1 which is
    multiple of alignment. I am storing new address in p2.
    */
    size_t addr=(size_t)p1 + alignment + sizeof(size_t);

    p2=(void *)(addr - (addr%alignment));

    /*	Final step, I am storing the address returned by malloc 'p1' just "size_t"
    bytes above p2, which will be useful while calling aligned_free.
    */
    *((size_t *)p2-1) = (size_t)p1;

    return p2;
}

/************************************************
    Name: aligned_free
    Arguments: pointer to be freed
    Returns	: Nothing
*************************************************/

void aligned_free(void *p ) {
    /*	Find the address stored by aligned_malloc ,"size_t" bytes above the
    current pointer then free it using normal free routine provided by C.
    */
    free((void *)(*((size_t *) p-1)));
}



// the memcpy function is used to copy a block of data from a source address to a destination address. Below is its prototype.
void memcpy(void* destination, const void* source, size_t num);
// The idea is to simply typecast given addresses to char*. Then one by one copy data from source to destination.
void memcpy(void* dest, void* src, size_t n) {
    // typecast src and dest addresses to (char*)
    char* csrc = (char*)src;
    char* cdest = (char*)dest;
    // copy contents of src[] to dest[]
    for(int i = 0; i < n; i++) {
        cdest[i] = csrc[i];
    }
}


// memmove() is similar to memcpy() as it also copies data from a source to destination. memcpy() leads to problems when source and destination addresses overlap as memcpy() simply copies data one by one from one location to another.
// use a temp array instead of directly copying from src to dest.

void memmove(void* dest, void* src, size_t n) {
    char* csrc = (char*)src;
    char* cdest = (char*)dest;
    char* temp = new char[n];

    for(int i = 0; i < n; i++) {
        temp[i] = csrc[i];
    }
    for(int i = 0; i < n; i++) {
        cdest[i] = temp[i];
    }
    delete []temp;
}





stack &&&&&& heap!!!!!!!!
