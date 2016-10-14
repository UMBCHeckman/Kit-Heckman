/************************************************
 ** File:    driver.cpp

 ** Project: CMSC 341 Project 1, Fall 2016

 ** Author:  Steven Heckman
 ** Date:    10/4/16
 ** Section: 05
 ** E-mail:  heckman1@umbc.edu
 **

 **   This file tests LLama.
 **
 ***********************************************/

#include <iostream>
#include <string>
using namespace std ;

#include "Llama.h"

int main()
{
    Llama<string,4> R ;

    // Push a bunch of strings

    R.push("cdef") ;
    R.push("yzab") ;
    R.push("vwx") ;
    R.push("stu") ;

    R.push("pqr") ;
    R.push("mno") ;
    R.push("jkl") ;
    R.push("ghi") ;

    R.push("def") ;
    R.push("abc") ;
    R.dump() ;


    cerr << "\n***** Dump using peek *****" ;
    int size = R.size() ;
    cerr << "\nsize = " << size << endl ;

    for (int i=0 ; i < R.size() ; i++)
    {
        cerr << i << ": " << R.peek(i) << endl ;
    }


    // Pop some strings off
    string s1 ;

    cerr << "\n***** Pop Test *****\n" ;
    s1 = R.pop() ;
    cerr << "popped " << s1 << endl ;
    s1 = R.pop() ;
    cerr << "popped " << s1 << endl ;
    s1 = R.pop() ;
    cerr << "popped " << s1 << endl ;
    s1 = R.pop() ;
    cerr << "popped " << s1 << endl;

    R.dump() ;  // should have "extra" node


    cerr << "\n***** Push Test *****\n" ;
    R.push("x789") ;
    R.push("x456") ;
    R.push("x123") ;

    R.dump() ;  // should use extra node


    cerr << "\n***** Pop Test *****\n" ;
    s1 = R.pop() ;
    cerr << "popped " << s1 << endl ;
    s1 = R.pop() ;
    cerr << "popped " << s1 << endl ;

    R.dump() ;  // should have extra node again


    cerr << "\n***** Pop Test *****\n" ;
    s1 = R.pop() ;
    cerr << "popped " << s1 << endl ;
    s1 = R.pop() ;
    cerr << "popped " << s1 << endl ;

    R.dump() ;  // extra node should be gone
    Llama<float,8> S ;
    float answer ;

    // Push a bunch of floats

    S.push(1.234) ;
    S.push(2.345) ;
    S.push(3.456) ;
    S.push(4.567) ;
    S.push(5.678) ;
    S.push(6.789) ;
    S.push(7.890) ;
    S.push(8.901) ;
    S.push(9.012) ;

    S.swap() ;
    S.dump() ;

    S.push(10.123) ;

    S.rot() ;
    S.dump() ;

    S.swap() ;
    S.dump() ;


    // Testing assignment and copy constructor
    //
//   Llama<float,8> T(S) ;
//
//
//   T.pop() ;
//   T.pop() ;
//   cerr << "============================\n" ;
//   cerr << "Copied stack T has: \n" ;
//   T.dump() ;
//   cerr << "============================\n" ;
//   cerr << "Orginal stack S has: \n" ;
//   S.dump() ;


    Llama<float,8> U ;

    U = S ;
    U.pop() ;
    U.push(11.234) ;
    cerr << "============================\n" ;
    cerr << "Copied stack U has: \n" ;
    U.dump() ;
    cerr << "============================\n" ;
    cerr << "Orginal stack S has: \n" ;
    S.dump() ;

//   cerr << "\n***** Pop Test Until Exception *****\n" ;
//   s1 = S.pop() ;
//   cerr << "popped " << s1 << endl ;
//   s1 = S.pop() ;
//   cerr << "popped " << s1 << endl ;
//   s1 = S.pop() ;
//   cerr << "popped " << s1 << endl ;
//   s1 = S.pop() ;
//   cerr << "popped " << s1 << endl ;
//   s1 = S.pop() ;
//   cerr << "popped " << s1 << endl ;
//   s1 = S.pop() ;
//   cerr << "popped " << s1 << endl ;
//   s1 = S.pop() ;
//   cerr << "popped " << s1 << endl ;
//   s1 = S.pop() ;
//   cerr << "popped " << s1 << endl ;
//   s1 = S.pop() ;
//   cerr << "popped " << s1 << endl ;
    try
    {
        int i = 10000000000;
        Llama<float,8> S ;
        float answer ;
        while(i != 0)
        {
            answer = S.pop();
            i--;
        }

    }
    catch (LlamaUnderflow &e)
    {
        cerr << "*****\n" ;
        cerr << "Llama Stack error: " << e.what() << endl ;
        cerr << "*****\n" ;
    }

    return 0;
}
