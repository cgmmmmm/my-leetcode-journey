class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = std::max(word1.size(), word2.size());
        std::string s = "";
        for (int i=0; i<n; ++i)
        {
            if (i <= word1.size()-1) s += word1[i];
            if (i <= word2.size()-1) s += word2[i];
        }

        return s;
    }
};