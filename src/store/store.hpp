#ifndef STORE_H
#define STORE_H
#include<functional>
#include<vector>
#include<algorithm>

using namespace std;

template<typename S>
class Store
{
    typedef function<void(S)> Listener;
    typedef function<void()> unsubscribe;

private:
    S _state;
    vector<Listener> _Listeners;

public:
    Store(S state){
        this->_state = state;
    }

    ~Store(){
        this->_Listeners.clear();
    }

    unsubscribe subscribe(Listener listener){
        this->_Listeners.push_back(listener);
        int index = this->_Listeners.size() - 1;
        return [=](){
            this->_Listeners[index] = [](S){};
        };
    }

    void dispatch(S value){
        this->_state = value;
        for_each(this->_Listeners.begin(), this->_Listeners.end(), [=](Listener listener){
            listener(this->_state);
        });
    }

    S getState(){
        return this->_state;
    }
};

#endif // STORE_H
