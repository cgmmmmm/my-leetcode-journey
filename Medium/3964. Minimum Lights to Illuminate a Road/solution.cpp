class Solution {
public:
    int minLights(vector<int>& lights) {
        int n = lights.size();
        
        vector<int> maxReached(n, -1);
        for (int i=0; i<n; ++i)
        {
            int v = lights[i];
            if (v > 0)
            {
                int l = max(0, i-v);
                int r = min(n-1, i+v);
                maxReached[l] = max(maxReached[l], r);
            }
        }

        int curr = -1;
        for (int i=0; i<n; ++i) 
        {
            curr = max(curr, maxReached[i]);
            maxReached[i] = curr;
        }

        int res = 0;
        int idx = 0;
        while (idx<n) 
        {
            if (maxReached[idx] >= idx) idx = maxReached[idx] + 1;
            else
            {
                res++;
                idx = idx+3;
            }
        }
        
        return res;
    }
};