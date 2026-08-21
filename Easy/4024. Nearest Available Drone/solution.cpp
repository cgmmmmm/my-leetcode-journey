class Solution {
public:
    int calcMD(int x1, int y1, int x2, int y2)
    {
        int dx = x1-x2, flagX = dx >> 31;
        int dy = y1-y2, flagY = dy >> 31;
        return ((dx + flagX) ^ flagX) + ((dy + flagY) ^ flagY);
    }

    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) 
    {
        int res = -1;
        int mdmn = INT_MAX;
        int x2 = target[0], y2 = target[1];
        for (int i=0; i<drones.size(); ++i)
        {
            int md = calcMD(drones[i][0], drones[i][1], x2, y2);
            if (md <= drones[i][2] && md < mdmn)
            {
                mdmn = md;
                res = i;
            }
        }

        return res;
    }
};