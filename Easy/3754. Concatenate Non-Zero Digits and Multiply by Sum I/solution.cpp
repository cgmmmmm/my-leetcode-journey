using ll = long long;

class Solution {
public:
    long long sumAndMultiply(int n) {
        int sum = 0;
        ll res = 0;
        int e = 0;
        while (n > 0)
        {
            int x = n % 10;
            if (x != 0)
            {
                sum += x;
                res += x * std::pow(10, e);
                e++;
            }
            n /= 10;
        }

        return res * sum;
    }
};