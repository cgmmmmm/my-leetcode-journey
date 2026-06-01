class Solution {
public:
    int minimumCost(vector<int>& cost) 
    {
        std::sort(cost.begin(), cost.end(), std::greater<>());
        int total = 0;
        int f = 1;
        for (int i=0; i<cost.size(); ++i)
        {
            if (f % 3 != 0) total += cost[i];
            f++;
        }
        
        return total;
    }
};