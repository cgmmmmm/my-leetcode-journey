class Solution {
public:
    int iter = 2;
    std::string base = "11";
    std::string res = "11";

    string countAndSay(int n) 
    {
        if (n == 1) return "1";

        if (iter == n) return res;

        res = "";
        int count;
        int l = 0;
        int len = base.size();
        for (int r=0; r<len; ++r)
        {
            if (base[l] != base[r])
            {
                count = r-l;
                res += (std::to_string(count) + base[l]);
                l = r;
            }
        }
        count = len-l;
        res += (std::to_string(count) + base[l]);
        base = res;

        iter++;

        return countAndSay(n);
    }
};