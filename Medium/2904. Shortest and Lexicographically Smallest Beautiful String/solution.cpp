class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) 
    {   
        int n = s.size();
        std::string_view res;
        std::string_view sv(s);

        int ones = 0;
        int minLen = INT_MAX;
        int l=0;
        for (int r=0; r<n; ++r)
        {
            if (s[r] == '1') ones++;
            while (ones == k)
            {
                int len = r-l+1;
                std::string_view ss = sv.substr(l, len);
                if (len < minLen)
                {
                    res = ss;
                    minLen = len;
                }
                else if (len == minLen && ss < res)
                {
                    res = ss;
                }

                if (s[l] == '1') ones--;
                l++;
            }
        }
        return std::string(res);
    }
};