#ifndef STORE_H
#define STORE_H
#include<functional>
#include<vector>
#include<algorithm>

#include<iostream>

using namespace std;

typedef function<void(int)> Listener;

typedef function<void()> unsubscribe;

class Store
{
private:
    int state;
    vector<Listener> Listeners;
public:
    Store(int state = 0);
    ~Store();
    unsubscribe subscribe(Listener );
    void dispatch(int);
    int getState();
};

#endif // STORE_H
