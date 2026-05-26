class Solution {
public:
    int numberOfSpecialChars(string word) {
        std::vector<int> lowercase(26, 0);
        std::vector<int> uppercase(26, 0);

        for (int i=0; i<word.size(); ++i)
        {
            if (word[i] >= 'a' && word[i] <= 'z') lowercase[word[i] - 'a'] = 1;
            else uppercase[word[i] - 'A'] = 1;
        }

        int res = 0;
        for (int i=0; i<lowercase.size(); ++i)
        {
            if (lowercase[i] == 1 && uppercase[i] == 1) res++;
        }

        return res;
    }
};
