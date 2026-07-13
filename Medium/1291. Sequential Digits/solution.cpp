using ll = long long;
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) 
    {
        std::unordered_map<int, std::vector<int>> mp = {
            {10, {12, 23, 34, 45, 56, 67, 78, 89}},
            {100, {123, 234, 345, 456, 567, 678, 789}},
            {1'000, {1'234, 2'345, 3'456, 4'567, 5'678, 6'789}},
            {10'000, {12'345, 23'456, 34'567, 45'678, 56'789}},
            {100'000, {123'456, 234'567, 345'678, 456'789}},
            {1'000'000, {1'234'567, 2'345'678, 3'456'789}},
            {10'000'000, {12'345'678, 23'456'789}},
            {100'000'000, {123'456'789}}
        };

        int lx = low;
        ll lower_bound = 1;
        while (lx > 0)
        {
            lx /= 10;
            lower_bound *= 10;
        }
        lower_bound /= 10;

        int hx = high;
        ll upper_bound = 1;
        while (hx > 0)
        {
            hx /= 10;
            upper_bound *= 10;
        }
        upper_bound /= 10;

        std::vector<int> res;
        bool fin = false;
        while (lower_bound <= upper_bound)
        {
            if (fin) break;

            for (int num : mp[lower_bound])
            {
                if (num > high) fin = true;
                if (num < low) continue;
                if (!fin) res.push_back(num);
            }

            lower_bound *= 10;
        }

        return res;
    }
};