class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        const int n = intervals.size();
        if (n == 1) return 1;

        std::sort(intervals.begin(), intervals.end());
        std::stack<std::vector<int>> ms;

        for (int i=0; i<n; ++i)
        {
            while (!ms.empty() && (ms.top()[0] >= intervals[i][0] && intervals[i][1] >= ms.top()[1]))
            {
                ms.pop();
            }
            if (!ms.empty() && ms.top()[0] <= intervals[i][0] && intervals[i][1] <= ms.top()[1])
                continue;
            ms.push(intervals[i]);
        }

        return ms.size();
    }
};