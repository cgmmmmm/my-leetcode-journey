using ll = long long;

class Solution {
public:
    long long maxRatings(vector<vector<int>>& units) 
    {
        int m = units.size();
        int n = units[0].size();
        
        ll globalMin = LLONG_MAX;
        ll sseMin = LLONG_MAX;
        ll sseSum = 0;
        ll initSum = 0;
        for (auto& d : units)
        {   
            std::sort(d.begin(), d.end());

            int fse = d[0];
            int sse = (n==1) ? 0 : d[1];

            initSum += fse;
            globalMin = (globalMin > fse) ? fse : globalMin;
            sseMin = (sseMin > sse) ? sse : sseMin;
            sseSum += sse;
        }

        if (n==1) return initSum;

        return sseSum - sseMin + globalMin;
    }
};