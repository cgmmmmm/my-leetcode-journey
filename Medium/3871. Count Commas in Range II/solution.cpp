#include <iostream>
#include <math.h>

using ll = long long;

class Solution {
public:
    ll countCommas(ll n) 
    {
        if (n < 1000) return 0;

        ll k = 1;
        ll tmp = n;
        while (tmp >= 1'000)
        {
            tmp /= 1'000;
            k++;
        }
        k--;

        ll a = 1'000;
        ll res = k * (n - (std::pow(a, k) - 1));
        k--;
        while (k >= 2)
        {
            res += (k * ((std::pow(a, k+1) - 1) - (std::pow(a, k) - 1)));
            k--;
        }
        return res;
    }
};

// there are (N - 999) numbers with ONE ',' for all numbers in the range 1,000 <= N <= 999,999 
// ',' count = 1 * (N - 999) 

// there are (N - 999,999) numbers with TWO ',' for all numbers in the range 1,000,000 <= N <= 999,999,999 (incl. prev)
// ',' count = 2 * (N - 999,999) + (999'999 - 999)

// there are (N - 999,999,999) numbers with THREE ',' for all numbers in the range 1,000,000,000 <= N <= 999,999,999,999 (incl. prev)
// ',' count = 3 * (N - 999,999,999) + 2 * (999'999'999 - 999,999) + (999'999 - 999)

// general formula:
// Given N, where: 1,000^k <= N <= 1,000^(k+1)
// Let a = 1,000
// ',' count = [k * (N - (a^k - 1))] + [(k - 1) * ((a^k - 1) - (a^(k-1) - 1))] + ... + [1 * ((a^2 - 1) - (a^1 - 1))]