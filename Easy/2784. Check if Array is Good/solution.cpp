class Solution {
public:
    bool isGood(vector<int>& nums) 
    {
        std::unordered_set<int> s;
        
        for (int num : nums)
        {
            if (num >= nums.size())
                return false;
            if (num != nums.size()-1 && s.count(num))
                return false;
            s.insert(num);
        }
        
        return s.size() == nums.size()-1;
    }
};
