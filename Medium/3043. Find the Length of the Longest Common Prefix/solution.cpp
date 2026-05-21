class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) 
    {
        std::unordered_set<int> prefixes;
        for (int num : arr1)
        {
            int x = num;
            while (x>0)
            {
                prefixes.insert(x);
                x /= 10;
            }
        }

        int res = 0;
        for (int num : arr2)
        {
            int length = 0;

            int x1 = num;
            while (x1>0)
            {
                x1 /= 10;
                length++;
            }

            int x2 = num;
            while (x2>0)
            {
                if (prefixes.count(x2)) res = (res < length) ? length : res;
                x2 /= 10;
                length--;
            }
        }

        return res;
    }
};
