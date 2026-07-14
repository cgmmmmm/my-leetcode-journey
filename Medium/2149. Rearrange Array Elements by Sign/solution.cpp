class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) 
    {
        int n = nums.size();

        std::queue<int> pos, neg;
        for (int num : nums)
        {
            if (num < 0) neg.push(num);
            else pos.push(num);
        }

        std::vector<int> res;
        res.reserve(n);
        for (int num : nums)
        {
            if (!pos.empty())
            {
                res.push_back(pos.front());
                pos.pop();
            }
            if (!neg.empty())
            {
                res.push_back(neg.front());
                neg.pop();
            }
        }

        return res;
    }
};