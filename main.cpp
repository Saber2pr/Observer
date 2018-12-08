#include <iostream>
#include"./src/console/console.h"
#include"./src/store/store.h"

using namespace std;

void listener(int state){
    Console::log(state);
}

int main()
{
    auto store = Store();

    Console::log("state: " ,store.getState());

    store.subscribe(listener);

    store.dispatch(233);

    Console::log("state: " ,store.getState());

    return 0;
}

