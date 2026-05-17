class Solution {
public:
    bool isAdjacentDiffAtMostTwo(string s) {
        for (int i=0; i<s.size()-1; ++i)
        {
            if (std::abs(s[i] - s[i+1]) > 2) return false;
        }

        return true;
    }
};
