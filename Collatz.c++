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

#include <iostream> // cin, cout
#include <cstdio>
#include <algorithm>

using namespace std;

const int max_size = 1000001;
short arr[max_size] = { 0 };


// ------------
// collatz_read
// ------------

bool collatz_read(istream& r, int& i, int& j) {

    if (!(r >> i))
        return false;
    r >> j;
    return true;
}

// ------------
// collatz_eval
// ------------

int circle_length(int num)
{
    int length = arr[num];
    if (length != 0) return length;
    length++;
    long long int current = num;
    while (current != 1)
    {
        if (current % 2 == 0) current = current / 2;
        else current = 3 * current + 1;
        length++;
    }

    arr[num] = length;
    return length;
}

int collatz_eval(int i, int j) {
    // <your code>

    int b1, b2;
    int count, maxnum;
    maxnum = 1;

    b1 = min(i, j);
    b2 = max(i, j);
    for (int n = b1; n <= b2; ++n)
    {
        count = circle_length(n);
        if (maxnum < count)
            maxnum = count;
    }
    return maxnum;
}

// -------------
// collatz_print
// -------------

void collatz_print(ostream& w, int i, int j, int v) {

    w << i << " " << j << " " << v << endl;
}

// -------------
// collatz_solve
// -------------

void collatz_solve(istream& r, ostream& w) {

    int i;
    int j;
    int v;

    while (collatz_read(r, i, j)) {
        v = collatz_eval(i, j);
        collatz_print(w, i, j, v);
    }
}
