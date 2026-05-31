class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) 
    {
        std::sort(asteroids.begin(), asteroids.end());
        long long planetMass = mass;
        for (int asteroidMass : asteroids)
        {
            if (asteroidMass > planetMass)
            {
                return false;
            }
            planetMass += asteroidMass;
        }
        return true;
    }
};