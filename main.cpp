#include <iostream>
#include"./src/console/console.hpp"
#include"./src/store/store.hpp"

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

    Store<string> store = Store<string>("haha");

    auto unListener1 = store.subscribe(listener1);
    auto unListener2 = store.subscribe(listener2);
    auto unListener3 = store.subscribe(listener3);

    //    unListener1();
    unListener2();
    //    unListener3();

    store.dispatch("lalala");

    return 0;
}

