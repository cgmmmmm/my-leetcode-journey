class Solution {
public:
    long long minArraySum(vector<int>& nums) 
    {
        int max_num = *std::max_element(nums.begin(), nums.end());
        std::vector<bool> present(max_num+1, false);
        for (int n : nums) present[n] = true;

        if (present[1]) return (long long)nums.size();
            
        std::vector<int> min_div(max_num+1);
        for (int i=1; i<=max_num; ++i) min_div[i] = i;

        for (int div=1; div<=max_num; ++div)
        {
            if (present[div])
            {
                int mul = div*2;
                while (mul<=max_num)
                {
                    if (div < min_div[mul])
                        min_div[mul] = div;
                    mul+=div;
                }
            }
        }

        long long res = 0;
        for (int n : nums) res+=min_div[n];
        
        return res;
    }
};
