using ll = long long;

class Solution {
public:
    long long maxTotal(vector<int>& nums, string s) {
        int n = s.size();
        ll res = 0;

        int i = 0;
        while (i < n && s[i] == '1')
        {
            res += nums[i];
            i++;
        }

        while (i < n)
        {
            if (s[i]=='0')
            {
                i++;
                continue;
            }

            int start = i-1;
            int minVal = nums[start];
            ll blockSum = nums[start];
            while (i<n && s[i] == '1')
            {
                blockSum += nums[i];
                minVal = (minVal < nums[i]) ? minVal : nums[i];
                i++;
            }

            res += (blockSum - minVal);
        }
        
        return res;
    }
};©leetcode