using ll = long long;

class Solution {
public:
    int gcd(int a, int b)
    {
        int rem;
        while (b != 0)
        {
            rem = a % b;
            a = b;
            b = rem;
        }
        return a;
    }

    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) 
    {
        int mx = *max_element(nums.begin(), nums.end());
        std::vector<ll> count(mx+1, 0);
        for (int x : nums)
            count[x]++;
        
        std::vector<ll> count_div(mx+1, 0);
        for (int i=1; i<=mx; ++i)
        {
            for (int j=i; j<=mx; j+=i)
                count_div[i] += count[j];
        }

        std::vector<ll> gcd_count(mx+1, 0);
        for (int i=mx; i>=1; --i)
        {
            gcd_count[i] = count_div[i] * (count_div[i] - 1) / 2;
            for (int j=2*i; j<=mx; j+=i)
                gcd_count[i] -= gcd_count[j];
        }

        std::vector<std::pair<ll, int>> ps;
        ll sum = 0;
        for (int i=1; i<=mx; ++i)
        {
            if (gcd_count[i] > 0)
            {
                sum += gcd_count[i];
                ps.push_back({sum, i});
            }
        }

        int n = queries.size();
        std::vector<int> res(n);
        for (int i=0; i<n; ++i)
        {
            ll target = queries[i] + 1;
            auto it = std::lower_bound(ps.begin(), ps.end(), std::make_pair(target, 0));
            res[i] = it->second;
        }

        return res;
    }
};