class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        int n = temperatures.size();

        std::vector<int> res(n, 0);
        std::vector<int> stk;
        stk.reserve(n);
        for (int i=0; i<n; ++i)
        {
            while (!stk.empty() && temperatures[i] > temperatures[stk.back()])
            {
                int idx = stk.back();
                res[idx] = i - idx;
                stk.pop_back();
            }
            stk.push_back(i);
        }
        return res;
    }
};