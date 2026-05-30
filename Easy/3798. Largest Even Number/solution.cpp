class Solution {
public:
    string largestEven(string s) 
    {
        int n = s.size() - 1;
        while ((n > -1) && ((s[n] - '0') % 2 == 1))
        {
            s.pop_back();
            n--;
        }
        return s;
    }
};