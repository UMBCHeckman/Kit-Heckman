#include <iostream>
#include <string>
using namespace std ;

#include "Llama.h"

int main()
{
    cout << "Hello world!" << endl;
    Llama<string,4> S ;

   // Push a bunch of strings

    S.push("cdef") ;
    S.push("yzab") ;
    S.push("vwx") ;
    S.push("stu") ;

    S.push("pqr") ;
   S.push("mno") ;
   S.push("jkl") ;
   S.push("ghi") ;

   S.push("def") ;
   S.push("abc") ;
   S.dump() ;
   return 0;
}
