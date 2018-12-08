# saber-redux-cpp

```cpp
unsubscribe Store::subscribe(Listener listener){
    this->Listeners.push_back(listener);
    auto index = this->Listeners.end();
    return [=](){
        this->Listeners.erase(index);
    };
}
```
