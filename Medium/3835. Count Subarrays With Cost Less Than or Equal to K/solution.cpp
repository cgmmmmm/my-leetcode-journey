using ll = long long;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        // cost = (max - min) * (r - l + 1)

        int n = nums.size();
        std::deque<int> maxq, minq;

        ll res = 0;
        int l = 0;

        for (int r=0; r<n; ++r)
        {
            while (!maxq.empty() && nums[r] >= nums[maxq.back()])
                maxq.pop_back();
            maxq.push_back(r);

            while (!minq.empty() && nums[r] <= nums[minq.back()])
                minq.pop_back();
            minq.push_back(r);

            while (l<=r && 1LL * (r-l+1) * ((ll)nums[maxq.front()] - nums[minq.front()]) > k)
            {
                if (!maxq.empty() && maxq.front() == l)
                    maxq.pop_front();
                if (!minq.empty() && minq.front() == l)
                    minq.pop_front();
                l++;
            }

            res += (r-l+1);
        }

        return res;
    }
};