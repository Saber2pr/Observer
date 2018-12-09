#ifndef OBSERVER_H
#define OBSERVER_H
#include<functional>
#include<vector>
#include<algorithm>

using namespace std;

template<typename S>
/**
 * @brief The Observer class (Observer)
 * @infor: by saber2pr
 */
class Observer
{
    typedef function<void(S)> Listener;
    typedef function<void()> unsubscribe;

private:
    S _state;
    vector<Listener> _Listeners;

public:
    /**
     * @brief Observer
     * @param state
     */
    Observer(S state){
        this->_state = state;
    }

    ~Observer(){
        this->_Listeners.clear();
    }
    /**
     * @brief subscribe
     * @param listener
     * @return
     */
    unsubscribe subscribe(Listener listener){
        this->_Listeners.push_back(listener);
        int index = this->_Listeners.size() - 1;
        return [=](){
            this->_Listeners[index] = [](S){};
        };
    }
    /**
     * @brief dispatch
     * @param value
     */
    void dispatch(S value){
        this->_state = value;
        for_each(this->_Listeners.begin(), this->_Listeners.end(), [=](Listener listener){
            listener(this->_state);
        });
    }
    /**
     * @brief getState
     * @return
     */
    S getState(){
        return this->_state;
    }
};

#endif // OBSERVER_H
