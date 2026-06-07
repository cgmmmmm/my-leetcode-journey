using ll = long long;

class Solution {
public:
    long long maximumSum(vector<int>& nums, int m, int l, int r) {
        const ll INF = 1e18;
        ll res = -INF;
        int n = nums.size();
        // m = max number of non-overlapping subarrays

        vector<ll> prefixSum(n+1, 0);
        for (int i=0; i<n; ++i)
        {
            prefixSum[i+1] = prefixSum[i] + nums[i];
        }

        vector<vector<ll>> dp(m+1, vector<ll>(n+1, -INF));

        for (int j=0; j<=n; ++j)
        {
            dp[0][j] = 0;    
        }
        
        for (int i=1; i<=m; ++i)
        {
            deque<int> dq;
            for (int j=1; j<=n; ++j)
            {
                dp[i][j] = dp[i][j-1];

                int newK = j - l;
                if (newK >= 0 && dp[i-1][newK] != -INF)
                {
                    ll newVal = dp[i-1][newK] - prefixSum[newK];

                    while (!dq.empty())
                    {
                        int backK = dq.back();
                        ll backVal = dp[i-1][backK] - prefixSum[backK];
                        
                        if (backVal <= newVal) dq.pop_back();
                        else break;
                    }
                    dq.push_back(newK);
                }

                int oldestK = j - r;
                while (!dq.empty() && dq.front() < oldestK) dq.pop_front();

                if (!dq.empty())
                {
                    int bestK = dq.front();
                    ll bestVal = dp[i-1][bestK] - prefixSum[bestK];
                    dp[i][j] = max(dp[i][j], prefixSum[j] + bestVal);
                }

                res = max(res, dp[i][j]);
            }
        }
        
        return res;
    }
};