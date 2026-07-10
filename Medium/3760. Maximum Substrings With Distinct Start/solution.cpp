class Solution {
public:
    int maxDistinct(string s) 
    {
        std::vector<int> v(26, 0);
        int res = 0;
        for (char& ch : s)
        {
            int idx = ch - 'a';
            if (v[idx] == 0) 
                res++;
            v[idx]++;
        }

        return res;
    }
};