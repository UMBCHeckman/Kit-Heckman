#ifndef _LLAMA_CPP_
#define _LLAMA_CPP_
/************************************************
 ** File:    Llama.cpp

 ** Project: CMSC 341 Project 1, Fall 2016

 ** Author:  Steven Heckman
 ** Date:    10/4/16
 ** Section: 05
 ** E-mail:  heckman1@umbc.edu
 **
 **   This file generates a "Llama".

 **   This file contains constructers and functions.
 **   This file will add undetermined data to an array of a determined size.
 **   This file will add LlamaNodes to a list and delete them.
 **
 ***********************************************/

#include <iostream>
#include "Llama.h"
#include "LlamaNode.cpp"
using namespace std;

template <class T, int LN_SIZE>
void Llama<T,LN_SIZE>::push(const T& data){
    //for(int i = 0; i<100; i++){
    //find last llamanode
    //do all this
    //new llamanode
    //add to that llamanode
    //}
    //for(int i = 0; )
    LlamaNode<T, LN_SIZE> *current;//temporary pointer object.
    current = m_head;
    if(isExtra == false){
    while (current->m_next != NULL){//while current pointer isn't pointing at the last node
        current = current->m_next;
    }
    if(current->m_next == NULL){//if we found the last node, for double checking.
        if(m_counter >= LN_SIZE){//then we need to make new node
            current->m_next = new LlamaNode<T, LN_SIZE>;
            current = current->m_next;
            m_counter = 0;//reset counter
        }
        current->arr[m_counter] = data;
        m_size ++;
        m_counter++;
    }
    }
    else if (isExtra = true){
        while(current != m_tail){//look for the tail, not for last non NULL node, since extra isn't NULL.
            current = current->m_next;
        }
        if((m_size % LN_SIZE) == 0){//move to empty node
            current = current->m_next;
            isExtra = false;
            m_counter = 0;
        }
        current->arr[m_counter] = data;
        m_size ++;
        m_counter++;
    }
    m_tail = current;
}
template <class T, int LN_SIZE>
void Llama<T,LN_SIZE>::dump(){
    LlamaNode<T, LN_SIZE> *dumpCurrent = m_head;
    LlamaNode<T, LN_SIZE> *dumpCurrentTail = m_tail;
    cerr << "***** Llama Stack Dump ******" << endl;
    cerr << "LN_SIZE = " << LN_SIZE << endl;
    cerr << "# of items in the stack = " << size() << endl;
    dumpCurrent->report();
    if(isExtra == false){
        cerr << endl << "This stack does not have an extra node." << endl << endl;
    }
    else{
            cerr << "This stack has an extra node: " << dumpCurrentTail->m_next << endl << endl;
    }
    int dumpCounter = m_size;//temporary copy of m_size for iteration.
    cerr << "Stack contents, top to bottom" << endl;
    while (dumpCounter > 0){
    cerr << dumpCurrentTail << endl;
    if((dumpCounter%LN_SIZE) == 0){
        cerr << dumpCurrentTail->arr[((dumpCounter -1)%LN_SIZE)] << endl;
        dumpCounter--;
    }
    while(((dumpCounter)%LN_SIZE) != 0){
        cerr << dumpCurrentTail->arr[((dumpCounter -1)%LN_SIZE)] << endl;
        dumpCounter--;
    }

    dumpCurrent = m_head;
    if(dumpCurrent != dumpCurrentTail){//if the tail is the head the following while loop behaves badly.
    while(dumpCurrent->m_next != dumpCurrentTail){
        dumpCurrent = dumpCurrent->m_next;
    }
    }
    dumpCurrentTail = dumpCurrent;
    }
    cerr << "-----Bottom Of Stack-----" << endl;
    cerr << "*************************" << endl;


//      **** Skeleton of abandoned Dump function, left here for prosperity. ****
//    if(isExtra == false){
//            cerr << dumpCurrent << endl;
//            while((dumpCounter%LN_SIZE) != 0){
//                cerr << dumpCurrent->arr[((dumpCounter)%(LN_SIZE-1))] << endl;
//                dumpCounter--;
//            }
//    }
//    dumpCurrent = m_head;
//    dumpCounter = m_size;
//    while (dumpCurrent->m_next != NULL){//while current pointer isn't pointing at the last node
//        if((dumpCounter) > (LN_SIZE-1)){//this really needs m_size to be correct. This checks for when we have an extra node and therfor this is a non full node. if true, this is false.
//        cerr << dumpCurrent << endl;
//        while (((m_size-dumpCounter)%LN_SIZE) != (LN_SIZE - 1)){
//        cerr << dumpCurrent->arr[((m_size - dumpCounter)%LN_SIZE)] << endl;
//        dumpCounter--;
//        }
//        cerr << dumpCurrent->arr[((m_size - dumpCounter)%LN_SIZE)] << endl;
//        dumpCounter--;
//        dumpCurrent = dumpCurrent->m_next;
//    }
//    }
//    }
////    if ((m_size - dumpCounter) < m_size){
//        cerr << dumpCurrent << endl;
//        while((m_size - dumpCounter) < m_size){
//            cerr << dumpCurrent->arr[((m_size - dumpCounter)%LN_SIZE)] << endl;
//            dumpCounter--;
//        }
//    }
}

template <class T, int LN_SIZE>
Llama<T,LN_SIZE>::Llama() {
    m_head = new LlamaNode<T, LN_SIZE>;
    m_tail = m_head;
    m_counter = 0;
    m_size = 0;
    isExtra = false;
}
template <class T, int LN_SIZE>
Llama<T,LN_SIZE>::~Llama(){
    LlamaNode<T, LN_SIZE> *killer = m_head;
    LlamaNode<T, LN_SIZE> *newKiller = m_head;
    while(killer->m_next != NULL){
        newKiller = killer->m_next;
        delete killer;
        killer = newKiller;
    }
    delete killer;
}
//Llama<data, LN_SIZE> = Llama<&T>{}
template <class T, int LN_SIZE>
Llama<T,LN_SIZE>::Llama(const Llama<T,LN_SIZE>& other){
    LlamaNode<T, LN_SIZE> *otherCopy = other.m_head;
    LlamaNode<T, LN_SIZE> *myCopy = other.m_head;
    m_head = new LlamaNode<T, LN_SIZE>;
    m_tail = new LlamaNode<T, LN_SIZE>;
    for (int i = 0; i < LN_SIZE; i++){
            m_head->arr[i] = other.m_head->arr[i];
            m_tail->arr[i] = other.m_tail->arr[i];
        }
    m_counter = other.m_counter;
    m_size = other.m_size;
    isExtra = other.isExtra;
    while(otherCopy->m_next != other.m_tail){
        myCopy->m_next = new LlamaNode<T, LN_SIZE>;
        for (int i = 0; i < LN_SIZE; i++){
            myCopy->m_next->arr[i] = otherCopy->m_next->arr[i];
        }
        otherCopy = otherCopy->m_next;
    }
}

template <class T, int LN_SIZE>
int Llama<T,LN_SIZE>::size(){
    return m_size;
}

template <class T, int LN_SIZE>
T Llama<T,LN_SIZE>::peek(int offset) const{
    int fromTheTop = (m_size - offset - 1);//how far from the top of the stack it is, offset at m_size will find the 0th index of m_head
    if (fromTheTop < 0){
        throw("Tried to peek further than size of stack.");
    }
    int numNodes = (fromTheTop / LN_SIZE);//integer division of fromTheTop to find the amount of full nodes
    LlamaNode<T, LN_SIZE> *seeker = m_head;
    for(int i = 0; i < numNodes; i++){
        seeker = seeker->m_next;
        }
    return (seeker->arr[((fromTheTop)%LN_SIZE)]);//mod to find the index content we need to return from our node
}

template <class T, int LN_SIZE>
T Llama<T,LN_SIZE>::pop(){
    if(m_size <= 0){
        throw LlamaUnderflow("Tried to pop from empty list.");
    }
    LlamaNode<T, LN_SIZE> *popCurrent = m_tail;
    T tempData = m_tail->arr[((m_size-1)%LN_SIZE)];
    m_size--;
    if((m_size%LN_SIZE) == 0){
        isExtra = true;
        popCurrent = m_head;
        if(popCurrent != m_tail){
        while (popCurrent->m_next != m_tail){//while current pointer isn't pointing at the last node
        popCurrent = popCurrent->m_next;
        }
        }
        m_tail = popCurrent;
    }
    else if(((m_size%LN_SIZE) <= (LN_SIZE / 2)) && (isExtra == true)){
        delete popCurrent->m_next;
        isExtra = false;
        m_tail = popCurrent;
    }
    m_counter = (m_size%LN_SIZE);
    return tempData;
}

template <class T, int LN_SIZE>
void Llama<T,LN_SIZE>::dup(){    //  (top) A B C D -> A A B C D
    if(m_size == 0){
        throw("Cannot duplicate from empty stack.");
    }
    T dupDat = peek(0);
    push(dupDat);
}

template <class T, int LN_SIZE>
void Llama<T,LN_SIZE>::swap(){   //  (top) A B C D -> B A C D
    if(m_size < 2){
        throw("Cannot swap from a stack below 2 items in size.");
    }
    T swapDat1 = pop();
    T swapDat2 = pop();
    push(swapDat1);
    push(swapDat2);
}

template <class T, int LN_SIZE>
void Llama<T,LN_SIZE>::rot(){    //  (top) A B C D -> C A B D
    if(m_size < 3){
        throw("Cannot rotate from a stack of less than 3.");
    }
    T rotDat1 = pop();
    T rotDat2 = pop();
    T rotDat3 = pop();
    push(rotDat2);
    push(rotDat1);
    push(rotDat3);
}

template <class T, int LN_SIZE>
const Llama<T,LN_SIZE>& Llama<T,LN_SIZE>::operator=(const Llama<T,LN_SIZE>& rhs){
    if(&rhs == this){
        return *this;
    }
    int g;
    LlamaNode<T, LN_SIZE> *otherCopy = rhs.m_head;

    m_head = new LlamaNode<T, LN_SIZE>;
    m_tail = new LlamaNode<T, LN_SIZE>;
    while(g < LN_SIZE){
            m_head->arr[g] = rhs.m_head->arr[g];
            m_tail->arr[g] = rhs.m_tail->arr[g];
            g++;
        }
    g = 0;
    m_counter = rhs.m_counter;
    m_size = rhs.m_size;
    isExtra = rhs.isExtra;
    LlamaNode<T, LN_SIZE> *myCopy = m_head;
    while(otherCopy->m_next != rhs.m_tail){
        g = 0;
        myCopy->m_next = new LlamaNode<T, LN_SIZE>;
        while (g < LN_SIZE){
            myCopy->m_next->arr[g] = otherCopy->m_next->arr[g];
            g++;
        }
        myCopy = myCopy->m_next;
        otherCopy = otherCopy->m_next;
    }
    return *this;
}

#endif
