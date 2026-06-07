class Solution {
public:
    void backtrack(int cost, string& s, char prev, vector<string>& res, const int n, const int k)
    {
        if (cost > k) return;
        if (s.size() == n)
        {
            res.push_back(s);
            return;
        }

        s += '0';
        backtrack(cost, s, '0', res, n, k);
        s.pop_back();
        if (prev != '1')
        {
            s += '1';
            backtrack(cost + (s.size()-1), s, '1', res, n, k);
            s.pop_back();
        }
    }
    
    vector<string> generateValidStrings(int n, int k) {
        // cost = sum of all indices that are '1'
        vector<string> res;
        string s = "";
        backtrack(0, s, ' ', res, n, k);

        return res;
    }
};