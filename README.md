# saber-redux-cpp
> Observer

```cpp
unsubscribe subscribe(Listener listener){
    this->_Listeners.push_back(listener);
    int index = this->_Listeners.size() - 1;
    return [=](){
        this->_Listeners[index] = [](S){};
    };
}
```
