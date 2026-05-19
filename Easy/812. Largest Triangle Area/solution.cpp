class Solution {
public:
    double GaussAreaFormula(double x1, double y1, double x2, double y2, double x3, double y3)
    {
        double area = abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2;
        return area;
    }

    double largestTriangleArea(vector<vector<int>>& points) 
    {
        // Area = (1/2) * |x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)|
        double res = 0;

        for (int i=0; i<points.size()-2; ++i)
        {
            for (int j=i+1; j<points.size()-1; ++j)
            {
                for (int k=j+1; k<points.size(); ++k)
                {
                    double area = GaussAreaFormula(
                        points[i][0], points[i][1],
                        points[j][0], points[j][1],
                        points[k][0], points[k][1]
                    );
                    res = (res < area) ? area : res; 
                }
            }
        }

        return res;
    }
};
