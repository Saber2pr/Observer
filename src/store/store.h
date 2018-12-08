#ifndef STORE_H
#define STORE_H
#include<functional>
#include<vector>
#include<algorithm>

#include<iostream>

using namespace std;

typedef function<void(int)> Listener;

typedef function<void()> unsubscribe;

template<typename T >
class Store
{
private:
    T state;
    vector<Listener> Listeners;
public:
    Store(T state){
        this->state = state;
    }

    ~Store(){
        this->Listeners.clear();
    }

    unsubscribe subscribe(Listener listener){
        this->Listeners.push_back(listener);
        int index = this->Listeners.size() - 1;
        return [=](){
            this->Listeners.erase(this->Listeners.begin() + index);
            cout << index << endl;
        };
    }

    void dispatch(T value){
        this->state = value;
        for_each(this->Listeners.begin(), this->Listeners.end(), [=](Listener listener){
            listener(this->state);
        });
    }

    T getState(){
        return this->state;
    }
};

#endif // STORE_H
