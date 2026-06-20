class Solution {
public:
    int findYMaximum(auto& l, auto& r)
    {
        int x1 = l[0], y1 = l[1], x2 = r[0], y2 = r[1];
        return min(y2, y1 + abs(x2 - x1));
    }

    int findYPeak(auto& l, auto& r)
    {
        int x1 = l[0], y1 = l[1], x2 = r[0], y2 = r[1];
        return (y1 + y2 + x2 - x1) >> 1;
    }

    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        auto& r = restrictions;
        if (restrictions.empty()) return n-1;

        r.push_back({1, 0});
        sort(r.begin(), r.end());
        int nR = r.size();

        for (int i=1; i<nR; ++i) r[i][1] = findYMaximum(r[i-1], r[i]);
        
        for (int i=nR-2; i>=0; --i) r[i][1] = findYMaximum(r[i+1], r[i]);

        int res = 0;
        for (int i=1; i<nR; ++i) res = max(res, findYPeak(r[i-1], r[i]));

        return max(res, r[nR-1][1] + n - r[nR-1][0]);
    }
};