//
//  DynamicStack.h
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
    bool empty() const;
    void pop(T &n);
    void push(T n);
    void runpop();
};

template <class T>
DynStack::~DynStack(){
    DyNode* cptr = nullptr, *nptr = nullptr;
    
    cptr = last; //working from the top of the stack
    
    while(cptr != nullptr){
        nptr = cptr->next;
        delete cptr;
        cptr = nptr;
    }
    
}
template <class T>
bool StatStack<T>::empty() const{
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
void StatStack<T>::pop(T &n){
    DyNode *temp = nullptr; //ptr to a new node

    if(empty()){
        cout << "Its empty." << endl;
    }
    else{
        n = top->value;
        temp = top->next;
        delete top;
        top = temp;
    }
}

template <class T>
void StatStack<T>::push(T n){
    DyNode *newNode = nullptr; //ptr to a new node
    
    newNode = new DyStack;
    newNode->value = n;
    
    
    if(empty()){
        last = newNode;
        newNode->next = nullptr;
    }
    else{
        newNode-> = top;
        top = newNode;
    }
}

template <class T>
void StatStack<T>::runpop(){
    for(int i = 0, n; i < stSize; i++){
        pop(n);
        cout << "Value stored: " << n << endl;
    }
}


#endif /* StaticStack_h */
