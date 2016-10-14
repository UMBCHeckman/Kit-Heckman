#ifndef _LLAMA_CPP_
#define _LLAMA_CPP_
/*
    description of this
*/

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
    LlamaNode<T, LN_SIZE> *current;
    current = m_head;
    while (current->m_next != NULL){//while current pointer isn't pointing at the last node
        current = current->m_next;
        cout << "why me" << endl;
    }
    if(current->m_next == NULL){//if we found the last node
        if(m_counter >= LN_SIZE){//make new node
            cout << "gotta make that new node, this one's full" << endl;
            current->m_next = new LlamaNode<T, LN_SIZE>;
            current = current->m_next;
            m_counter = 0;
        }
        current->arr[m_counter] = data;
        m_size ++;
        m_counter++;
    }
    m_tail = current;
}
template <class T, int LN_SIZE>
void Llama<T,LN_SIZE>::dump(){//this is printing backwards, work on that.
    LlamaNode<T, LN_SIZE> *dumpCurrent = m_tail;
    cerr << "***** Llama Stack Dump ******" << endl;
    cerr << "LN_SIZE = " << LN_SIZE << endl;
    cerr << "# of items in the stack = " << size() << endl;
    dumpCurrent->report();
    cerr << endl << "This stack does";
    if(isExtra == false){
        cerr << " not";
    }
    cerr << " have an extra node." << endl << endl;
    int dumpCounter = m_size;
    if(&m_tail != NULL){
            cerr << dumpCurrent << endl;
            while((dumpCounter%LN_SIZE) != 0){
                cerr << dumpCurrent->arr[((dumpCounter)%(LN_SIZE-1))] << endl;
                dumpCounter--;
            }
    }
    dumpCurrent = m_head;
    dumpCounter = m_size;
    while (dumpCurrent->m_next != NULL){//while current pointer isn't pointing at the last node
        if((dumpCounter) > (LN_SIZE-1)){//this really needs m_size to be correct. This checks for when we have an extra node and therfor this is a non full node. if true, this is false.
        cerr << dumpCurrent << endl;
        while (((m_size-dumpCounter)%LN_SIZE) != (LN_SIZE - 1)){
        cerr << dumpCurrent->arr[((m_size - dumpCounter)%LN_SIZE)] << endl;
        dumpCounter--;
        }
        cerr << dumpCurrent->arr[((m_size - dumpCounter)%LN_SIZE)] << endl;
        dumpCounter--;
        dumpCurrent = dumpCurrent->m_next;
    }
    }
//    if ((m_size - dumpCounter) < m_size){
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

}
//Llama<data, LN_SIZE> = Llama<&T>{}
template <class T, int LN_SIZE>
Llama<T,LN_SIZE>::Llama(const Llama<T,LN_SIZE>& other){

}

template <class T, int LN_SIZE>
int Llama<T,LN_SIZE>::size(){
    return m_size;
}

template <class T, int LN_SIZE>
T Llama<T,LN_SIZE>::peek(int offset) const{
    return "b";
}

template <class T, int LN_SIZE>
T Llama<T,LN_SIZE>::pop(){
    LlamaNode<T, LN_SIZE> *popCurrent = m_tail;
    T tempData = m_tail->arr[((m_size%LN_SIZE)-1)];
    m_size--;
    if((m_size%LN_SIZE) == 0){
        isExtra = true;
        popCurrent = m_head;
        while (popCurrent->m_next != m_tail){//while current pointer isn't pointing at the last node
        popCurrent = popCurrent->m_next;
        }
        m_tail = popCurrent;
    }
    if((m_size%LN_SIZE) > (LN_SIZE / 2)){
        delete popCurrent;
        cout << "2";
        isExtra = false;
        popCurrent = m_head;
        while (popCurrent->m_next != NULL){//while current pointer isn't pointing at the last node
        popCurrent = popCurrent->m_next;
        }
        m_tail = popCurrent;
    }
    return tempData;
}

#endif
