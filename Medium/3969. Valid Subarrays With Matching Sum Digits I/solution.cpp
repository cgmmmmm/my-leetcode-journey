using ll = long long;

class Solution {
public:
    int findFirstDigit(ll num)
    {
        if (num == 0) return 0;

        num = abs(num);
        while (num >= 10) num /= 10;
        return num;
    }
    
    int countValidSubarrays(vector<int>& nums, int x) {
        int res = 0;
        ll ps = 0;

        std::unordered_map<ll, vector<ll>> psCnt;
        psCnt[0].push_back(0);

        for (int i=0; i<nums.size(); ++i)
        {
            ps += nums[i];

            ll target = (ps - x) % 10;
            if (target < 0) target += 10;

            if (psCnt.count(target))
            {
                for (ll past : psCnt[target])
                {
                    ll subSum = ps - past;
                    if (findFirstDigit(subSum) == x) res++;
                }
            }

            ll curr = ps % 10;
            if (curr < 0) curr += 10;
            psCnt[curr].push_back(ps);
        }

        return res;
    }
};