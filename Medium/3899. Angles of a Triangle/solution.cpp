class Solution {
public:
    static constexpr double PI = std::numbers::pi;

    double convertRadToDeg(double rad) 
    {
        return rad * (180/PI);
    }

    vector<double> internalAngles(vector<int>& sides) 
    {
        std::sort(sides.begin(), sides.end());
        double a = (double) sides[0], b = sides[1], c = sides[2];

        if (a + b <= c) return {};

        double cosA = (b*b + c*c - a*a) / (2 * b * c);
        double cosB = (a*a + c*c - b*b) / (2 * a * c);
        double cosC = (a*a + b*b - c*c) / (2 * a * b);
        
        double rad_A = std::acos(cosA); 
        double rad_B = std::acos(cosB);
        double rad_C = std::acos(cosC);

        return {convertRadToDeg(rad_A), convertRadToDeg(rad_B), convertRadToDeg(rad_C)};
    }
};