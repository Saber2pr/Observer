#include <iostream>
#include"./src/console/console.hpp"
#include"./src/store/Observer.hpp"

using namespace std;

void listener1(string state){
    Console::log("listener1: ",state);
}

void listener2(string state){
    Console::log("listener2: ",state);
}

void listener3(string state){
    Console::log("listener3: ",state);
}

int main()
{

    Observer<string> observer = Observer<string>("haha");

    auto unListener1 = observer.subscribe(listener1);
    auto unListener2 = observer.subscribe(listener2);
    auto unListener3 = observer.subscribe(listener3);

//    unListener1();
    unListener2();
//    unListener3();

    observer.dispatch("lalala");

    return 0;
}

