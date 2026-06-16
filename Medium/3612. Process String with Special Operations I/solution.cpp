class Solution {
public:
    void reverse(std::string& res)
    {
        int l = 0, r = res.size()-1;
        while (l < r)
        {
            std::swap(res[l], res[r]);
            l++;
            r--;
        }
    }
        
    string processStr(string s) 
    {
        std::string res = "";

        for (char ch : s)
        {
            if (ch == '#') res += res;
            else if (ch == '*')
            {
                if (!res.empty())
                    res.pop_back();
            }
            else if (ch == '%') reverse(res);
            else res += ch;
        }

        return res;
    }
};