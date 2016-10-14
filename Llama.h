#ifndef _LLAMA_H_
#define _LLAMA_H_

/* File: Llama.h

   UMBC CMSC 341 Fall 2016 Project 1

   This file has the class declaration for the LlamaNode class
   for Project 1. See project description for details.

   You may add public and private data members to the Llama class.

   You may add public and private member functions to the Llama class.

*/


#include <stdexcept>
#include <string>
#include "LlamaNode.h"

using namespace std ;


class LlamaUnderflow : public std::out_of_range
{

public:

    LlamaUnderflow(const string& what) : std::out_of_range(what) { }

} ;


template <class T, int LN_SIZE>
class Llama
{

public:

    Llama() ;
    Llama(const Llama<T,LN_SIZE>& other) ;   // copy constructor
    ~Llama() ;


    int size() ;
    void dump() ;
    void push(const T& data) ;
    T pop() ;


    void dup() ;    //  (top) A B C D -> A A B C D
    void swap() ;   //  (top) A B C D -> B A C D
    void rot() ;    //  (top) A B C D -> C A B D


    T peek(int offset) const ;


    // overloaded assignment operator
    //
    const Llama<T,LN_SIZE>& operator=(const Llama<T,LN_SIZE>& rhs) ;


    //
    // Add your public member functions & public data mebers here:
    //
    //int *data;


private:


    //
    // Add your private member functions & private data mebers here:
    //
    LlamaNode<T, LN_SIZE> *m_head;//pointer object for the head (start) of the list.
    LlamaNode<T, LN_SIZE> *m_tail;//pointer object for the tail (end) of the list. Does not point to "extra" node, if there is one.
    int m_counter;//used to count what index must be read from a node next.
    int m_size;//total number of items in the stack.
    bool isExtra;//if the stack has an "extra" node. Yes if true.

} ;


#include "Llama.cpp"


#endif
