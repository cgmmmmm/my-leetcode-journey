class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) 
    {
        int len = target.size();
        
        std::vector<int> nums;
        for (int num=1; num<=target[len-1]; ++num)
            nums.push_back(num);

        std::vector<std::string> res;
        int idx = 0;
        for (int i=0; i<nums.size(); ++i)
        {
            if (idx == len) break;
            
            if (nums[i] != target[idx])
            {
                res.push_back("Push");
                res.push_back("Pop");
            }
            else
            {
                res.push_back("Push");
                idx++;
            }
        }

        return res;
    }
};