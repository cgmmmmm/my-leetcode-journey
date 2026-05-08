class Solution {
public:
    void backtrack(
        std::vector<std::string>& res, 
        std::string& s, 
        int it,
        int len, 
        const std::string& binary, 
        const int n)
    {
        if (len == n) 
        { 
            res.push_back(s);
            return;
        }

        for (int i=it; i<2; ++i)
        {
            s += binary[i];
            len++;
            if (s[len-1] == '0') backtrack(res, s, 1, len, binary, n);
            else backtrack(res, s, 0, len, binary, n);
            s.pop_back();
            len--;
        }
    }

    vector<string> validStrings(int n) 
    {
        if (n == 1) return {"0", "1"};
        if (n == 2) return {"01", "10", "11"};

        // the binary string must be alternating or 1s
        std::string binary = "01";
        std::vector<std::string> res;
        std::string s = "";
        int len = 0;
        
        backtrack(res, s, 0, len, binary, n);

        return res;
    }
};
