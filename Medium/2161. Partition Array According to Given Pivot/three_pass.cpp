class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot)  {
        std::vector<int> res;
        res.reserve(nums.size());
        
        for (int num : nums) if (num < pivot) res.push_back(num);
        for (int num : nums) if (num == pivot) res.push_back(num); 
        for (int num : nums) if (num > pivot) res.push_back(num); 

        return res;
    }
};