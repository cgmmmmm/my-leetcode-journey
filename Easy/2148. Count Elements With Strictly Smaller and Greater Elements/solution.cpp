class Solution {
public:
    int countElements(vector<int>& nums) 
    {
        int res = 0;
        int maxE = INT_MIN;
        int minE = INT_MAX;

        for (int num : nums)
        {
            if (maxE < num) maxE = num;
            if (minE > num) minE = num;
        }

        for (int num : nums)
        {
            if (num != maxE && num != minE) res++;
        }

        return res;
    }
};