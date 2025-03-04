/*
INSTRUCTIONS TO RUN THE CODE
g++ -c -fPIC hello.cpp -o hello.o            // fPIC generates Position Indipendent COde
g++ -shared -fPIC -o libhello.so hello.o     // creates shared library
g++ -o main main.cpp -L. -lhello             // -L tells the compiler to look for libraries in the same dir
                                             // -lhello links with libhello.so
export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH    // ensures the system can find libhello.so
./main                                       // runs the program   
*/

#include "hello.h"

int main() {
    hello();
    return 0;
}

