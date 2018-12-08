#ifndef CONSOLE
#define CONSOLE

#include<iostream>

using namespace std;

class Console
{
public:
    template<typename T>
    static void log(T value) {
        cout << value << endl;
    }

    template<typename T1, typename T2>
    static void log(T1 value1, T2 value2) {
        cout << value1 << " "<< value2 << endl;
    }
};

#endif // CONSOLE

