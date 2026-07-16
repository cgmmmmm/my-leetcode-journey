using ll = long long;

class Solution {
public:
    ll gcd(int a, int b)
    {
        ll rem;
        while (b != 0)
        {
            rem = a % b;
            a = b;
            b = rem;
        }
        return a;
    }

    ll gcdSum(vector<int>& nums)
    {
        int n = nums.size();

        std::vector<ll> prefixGcd(n);
        int mx = INT_MIN;
        for (int i=0; i<n; ++i)
        {
            mx = (mx < nums[i]) ? nums[i] : mx;
            prefixGcd[i] = gcd(nums[i], mx);
        }
        std::sort(prefixGcd.begin(), prefixGcd.end());

        ll sum = 0;
        int l = 0, r = n-1;
        while (l < r)
        {
            sum += gcd(prefixGcd[l++], prefixGcd[r--]);
        }

        return sum;
    }
};