class Solution {
public:
    double angleClock(int hour, int minutes) {
        // each minute is 6deg
        // shortest angle can be obtained from taking the minute hand a
        std::unordered_map<int, double> hourDegMap = {
            {12, 0.0}, {1, 30.0}, {2, 60.0}, {3, 90.0}, {4, 120.0}, {5, 150.0}, {6, 180.0},
            {7, 210.0}, {8, 240.0}, {9, 270.0}, {10, 300.0}, {11, 330.0}
        };

        double minuteDeg = minutes * 6.0;

        double ratio = (minutes/60.0);
        double hourDeg = hourDegMap[hour] + (30 * ratio);

        if (minuteDeg == hourDeg) return 0.0;
        double deg = (minuteDeg > hourDeg) ? minuteDeg - hourDeg : hourDeg - minuteDeg;
        if (deg > 180.0) return 360.0 - deg;
        return deg;  
    }
};