#include <iostream>
#include"./src/console/console.h"
#include"./src/store/store.h"

using namespace std;

void listener1(int state){
    Console::log("listener1: ",state);
}

void listener2(int state){
    Console::log("listener2: ",state);
}

void listener3(int state){
    Console::log("listener3: ",state);
}

int main()
{
    Store<int> store = Store<int>(233);

    //    Console::log("state: " ,store.getState());

    auto unListener1 = store.subscribe(listener1);
    auto unListener2 = store.subscribe(listener2);
    auto unListener3 = store.subscribe(listener3);

    unListener1();
        unListener2();
    //    unListener3();

    store.dispatch(233);

    //    Console::log("state: " ,store.getState());

    return 0;
}

