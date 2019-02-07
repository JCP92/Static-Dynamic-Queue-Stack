//
//  StaticStack.h
//  HW18
//
//  Created by Joshua Peckham on 11/3/16.
//  Copyright © 2016 Joshua Peckham. All rights reserved.
//

#ifndef StaticStack_h
#define StaticStack_h
#include <iostream>
using namespace std;

template <class T>
class StatStack{
private:
    T* stArray;
    int stSize;
    int last;
public:
    StatStack(T size){
        stArray = new T[size];
        stSize = size;
        last = -1;
    }
    ~StatStack(){
        delete [] stArray;
    }
    bool empty() const;
    bool full() const;
    void pop(T &n);
    void push(T n);
    void view() const;
    void runpop();
};

template <class T>
bool StatStack<T>::empty() const{
    bool result;
    
    if(last == -1){
        result = true;
    }
    else{
        result = false;
    }
    return result;
}

template <class T>
bool StatStack<T>::full() const{
    bool result;
    
    if(last == stSize-1){
        result = true;
    }
    else{
        result = false;
    }
    return result;
}

template <class T>
void StatStack<T>::pop(T &n){
    if(empty()){
        cout << "Its empty." << endl;
    }
    else{
        n = stArray[last];
        last--;
    }
}

template <class T>
void StatStack<T>::push(T n){
    if(full()){
        cout << "Its full." << endl;
    }
    else{
        last++;
        stArray[last] = n;
    }
}

template <class T>
void StatStack<T>::view()const{
    for(int i=0; i < stSize; i++){
        cout << stArray[i] << "\t";
    }
    cout << endl;
}

template <class T>
void StatStack<T>::runpop(){
    for(int i = 0, n; i < stSize; i++){
        pop(n);
        cout << "Value stored: " << n << endl;
    }
}


#endif /* StaticStack_h */
