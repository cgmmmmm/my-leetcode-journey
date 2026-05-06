class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) 
    {
        int m = boxGrid.size();
        int n = boxGrid[0].size();

        std::vector<std::vector<char>> res(n, std::vector<char>(m, '.'));

        for (int next=0; next<m; ++next)
        {
            int stoneCnt = 0;
            for (int box=0; box<n; ++box)
            {
                if (boxGrid[next][box] == '#') stoneCnt++;
                if (boxGrid[next][box] == '*')
                {
                    int obstacleHIndex = box;
                    int obstacleVIndex = m-next-1;
                    res[obstacleHIndex][obstacleVIndex] = '*';
                    while (stoneCnt)
                    {
                        res[obstacleHIndex-1][obstacleVIndex] = '#';
                        obstacleHIndex--;
                        stoneCnt--;
                    }
                }
            }

            int horizontalEndIndex = n-1;
            int verticalEndIndex = m-next-1;
            while (stoneCnt)
            {
                res[horizontalEndIndex][verticalEndIndex] = '#';
                horizontalEndIndex--;
                stoneCnt--;
            }
        }

        return res;
    }
};
