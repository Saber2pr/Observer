#include "store.h"

Store::Store(int state)
{
    this->state = state;
}

Store::~Store()
{
    this->Listeners.clear();
}

unsubscribe Store::subscribe(Listener listener){
    this->Listeners.push_back(listener);
    auto index = this->Listeners.end();
    return [=](){
        this->Listeners.erase(index);
    };
}

void Store::dispatch(int value){
    this->state = value;
    for_each(this->Listeners.begin(), this->Listeners.end(), [=](Listener listener){
       listener(this->state);
    });
}

int Store::getState(){
    return this->state;
}
