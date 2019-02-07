//
//  main.cpp
//  HW18
//
//  Created by Joshua Peckham on 11/3/16.
//  Copyright © 2016 Joshua Peckham. All rights reserved.
//


#include <iostream>
using namespace std;
template <class T>
class DynStack{
private:
    struct DyNode
    {
        DyNode* next; //pointer
        T value; // value in node                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
    };
    DyNode* last; // pointer to top
public:
    DynStack(){
        last = nullptr;
    }
    ~DynStack();
    bool empty();
    void pop(T &n);
    void push(T n);
    void runpop();
};

template <class T>
DynStack<T>::~DynStack(){
    DyNode* cptr = nullptr, *nptr = nullptr;
    
    cptr = last; //working from the top of the stack
    
    while(cptr != nullptr){
        nptr = cptr->next;
        delete cptr;
        cptr = nptr;
    }
    
}
template <class T>
bool DynStack<T>::empty(){
    bool result;
    
    if(!last){
        result = true;
    }
    else{
        result = false;
    }
    return result;
}

template <class T>
void DynStack<T>::pop(T &n){
    DyNode *temp = nullptr; //ptr to a new node
    
    if(empty()){
        cout << "Its empty." << endl;
    }
    else{
        n = last->value;
        temp = last->next;
        delete last;
        last = temp;
    }
}

template <class T>
void DynStack<T>::push(T n){
    DyNode *newNode = nullptr; //ptr to a new node
    
    newNode = new DyNode;
    newNode->value = n;
    
    
    if(empty()){
        last = newNode;
        newNode->next = nullptr;
    }
    else{
        newNode->next = last;
        last = newNode;
    }
}

template <class T>
void DynStack<T>::runpop(){
    T n;
    while (!empty()){
        pop(n);
        cout << "Info stored: " << n << endl;
    }
}


int main() {
    DynStack<int> m;
    
    int num;
    
    cout << "Trying to pop: ";
    m.pop(num);
    cout << endl;
    
    cout << "Filling Array" << endl;
    
    for(int i = 0, n = 1; i < 5; i++,n++){
        m.push(n);
    }
    
    m.runpop();
    
    m.~DynStack();
    
    DynStack<char> l;
    
    char a;
    char n = 'A';
    
    cout << "Trying to pop: ";
    l.pop(a);
    cout << endl;
    
    cout << "Filling Array" << endl;
    
    for(int i = 0; i < 5; i++,n++){
        l.push(n);
    }
    
    l.runpop();
    
    
    return 0;
}
