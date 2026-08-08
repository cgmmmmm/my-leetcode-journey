class Solution {
public:
    std::vector<std::string> res;
    char open = '(';
    char close = ')';

    void backtrack(std::string& str, int open_cnt, int close_cnt, const int n)
    {
        if (open_cnt == n && close_cnt == n)
        {
            res.push_back(str);
            return;
        }

        if (open_cnt < n)
        {
            str.push_back(open);
            backtrack(str, open_cnt+1, close_cnt, n);
            str.pop_back();
        }

        if (close_cnt < open_cnt)
        {
            str.push_back(close);
            backtrack(str, open_cnt, close_cnt+1, n);
            str.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) 
    {
        std::string initial = "";
        backtrack(initial, 0, 0, n);
        return res;
    }
};