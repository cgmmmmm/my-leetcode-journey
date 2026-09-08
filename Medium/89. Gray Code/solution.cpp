#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> grayCode(int n) 
    {
        std::vector<int> res;
        int max = 1;
        while (n > 0)
        {
            max *= 2;
            n--;
        }
        for (int i=0; i<max; ++i)
        {
            res.push_back(i ^ (i >> 1));
        }

        return res;
    }
};

// answer vector always has length 2^n
// every number's binary representation (incl. first and last) differs by exactly one bit

// example 1:
// n = 2
// vec: { 0, 1, 3, 2} OR vec: { 0, 2, 3, 1}
// bin: {00,01,11,10} OR bin: {00,10,11,01}

// adjacent numbers have difference of 2^x

// given n: min = 0, max = (2^n)-1

// example 2:
// n = 3
// vec: {  0,   1,   3,   2,   6,   7,   5,   4}
// bin: {000, 001, 011, 010, 110, 111, 101, 100}
// XOR: {000, 001, }