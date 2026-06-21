class Solution {
public:
    int findDistance(int x, int y)
    {
        return abs(x + y);    
    }
    
    int maxDistance(string moves) {
        int x = 0, y = 0;
        int wc = 0;

        for (char c : moves)
        {
            if (c == 'U') y += 1;
            else if (c == 'D') y -= 1;
            else if (c == 'L') x -= 1;
            else if (c == 'R') x += 1;
            else if (c == '_') wc += 1;
        }

        int base = abs(x) + abs(y);

        return base + wc;
    }
};