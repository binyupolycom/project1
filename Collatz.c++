// ----------------------------
// projects/collatz/Collatz.c++
// Copyright (C) 2016
// Glenn P. Downing
// ----------------------------

// --------
// includes
// --------

#include <cassert>  // assert
#include <iostream> // endl, istream, ostream

#include "Collatz.h"

using namespace std;


#define max_size 10001

long arr[max_size] = { 0 };

// ------------
// collatz_read
// ------------

bool collatz_read (istream& r, int& i, int& j) {
    if (!(r >> i))
        return false;
    r >> j;
    return true;}

// ------------
// collatz_eval
// ------------
int circle_length(int i)
   {
       int len;

       if (i < max_size)
       {
           if (arr[i] != 0)
               return arr[i];
       }

       if (i == 1)
           len = 1;
       else if (i % 2 == 0)
           len = circle_length(i >> 1) + 1;
       else
           len = circle_length(i * 3 + 1) + 1;

       if (i < max_size)
           arr[i] = len;

       return len;
   }

int collatz_eval (int i, int j) {
    // <your code>

        int b1, b2;
        int count, max;

        max = 1;
        if (i <= j)
        {
            b1 = i;
            b2 = j;
        }
        else
        {
            b1 = i;
            b2 = j;
        }
        for (int n = b1; n <= b2; ++n)
        {
            count = circle_length(n);
            if (max < count)
                max = count;
        }

        return max;
}

// -------------
// collatz_print
// -------------

void collatz_print (ostream& w, int i, int j, int v) {
    w << i << " " << j << " " << v << endl;}

// -------------
// collatz_solve
// -------------

void collatz_solve (istream& r, ostream& w) {
    int i;
    int j;
    while (collatz_read(r, i, j)) {
        const int v = collatz_eval(i, j);
        collatz_print(w, i, j, v);}}
