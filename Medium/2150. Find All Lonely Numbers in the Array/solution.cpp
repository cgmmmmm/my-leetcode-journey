class Solution {
public:
    vector<int> findLonely(vector<int>& nums) 
    {
        // lonely = x appear once in entire array, and the array has no adjacent values to x where, x+1, x-1
        std::unordered_map<int, int> mp;
        for (int num : nums)
            mp[num]++;

        
        std::vector<int> res;
        for (int num : nums)
        {
            if (mp[num] == 1 && !mp.count(num+1) && !mp.count(num-1))
                res.push_back(num);
        }

        return res;
    }
};