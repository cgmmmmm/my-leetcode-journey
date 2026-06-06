using ll = long long;

class Solution {
public:
    long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) 
    {
        ll numOfLightBulbsNeeded = (brightness + 2) / 3;

        std::sort(intervals.begin(), intervals.end());
        
        ll totalTime = 0;
        ll currentStart = intervals[0][0];
        ll currentEnd = intervals[0][1];
        
        for (int i=1; i<intervals.size(); ++i)
        {
            if (intervals[i][0] <= currentEnd)
                currentEnd = (intervals[i][1] > currentEnd) ? intervals[i][1] : currentEnd;
            else
            {
                totalTime += (currentEnd - currentStart + 1);
                currentStart = intervals[i][0];
                currentEnd = intervals[i][1];
            }
        }

        totalTime += (currentEnd - currentStart + 1);

        return totalTime * numOfLightBulbsNeeded;
    }
};