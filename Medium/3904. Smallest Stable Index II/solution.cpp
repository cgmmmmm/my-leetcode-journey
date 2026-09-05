class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) 
    {
        std::deque<int> dq;
        for (int num : nums)
        {
            while (!dq.empty() && num < dq.back())
                dq.pop_back();
            dq.push_back(num);
        }

        int res = -1;
        int maxElem = INT_MIN;
        for (int i=0; i<nums.size(); ++i)
        {
            if (nums[i] > maxElem) maxElem = nums[i];
            if (maxElem - dq.front() <= k) return i;
            if (nums[i] == dq.front()) dq.pop_front();
        }

        return res;
    }
};