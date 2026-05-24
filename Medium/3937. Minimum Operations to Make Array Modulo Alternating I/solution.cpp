class Solution {
public:
    int minOperations(vector<int>& nums, int k) 
    {
        // every even index, nums[i] % k = x
        // every odd index, nums[i] % k = y
        // a condition is that 0 <= x, y < k

        // compute cost at every remainder in even and odd 
        // all elements in even should be equal, and all elements in odd should be equal, but elements in odd and even should not be equal
        // therefore, we can calc the cost at each even and odd indices to find the min

        vector<long long> even_cost(k, 0);
        vector<long long> odd_cost(k, 0);
        
        for (int i=0; i<nums.size(); ++i)
        {
            long long rem = nums[i] % k;

            for (int r=0; r<k; ++r)
            {
                long long diff = (r - rem + k) % k;
                long long cost = std::min(diff, k - diff);
                
                if (i % 2 == 0) even_cost[r] += cost;
                else odd_cost[r] += cost;
            }
        }

        long long res = LLONG_MAX;
        for (int x=0; x<k; ++x)
        {
            for (int y=0; y<k; ++y)
            {
                if (x != y) res = std::min(res, even_cost[x] + odd_cost[y]);
            }
        }

        return static_cast<int>(res);
    }
};