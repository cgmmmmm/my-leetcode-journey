class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int water = capacity;
        int steps = 0;
        for (int i=0; i<plants.size(); ++i)
        {
            if (water - plants[i] < 0)
            {
                water = capacity;
                steps += i*2 + 1;
            }
            else
            {
                steps++;
            }
            water -= plants[i];
        }

        return steps;
    }
};