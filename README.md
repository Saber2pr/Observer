# saber-redux-cpp

```cpp
unsubscribe subscribe(Listener listener){
    this->Listeners.push_back(listener);
    int index = this->Listeners.size() - 1;
    return [=](){
        this->Listeners.erase(this->Listeners.begin() + index);
        cout << index << endl;
    };
}
```
