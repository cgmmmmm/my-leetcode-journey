class Solution {
public:
    int numberOfSpecialChars(string word) {
        std::vector<int> lastSeenLowercase(26, -1);
        std::vector<int> firstSeenUppercase(26, -1);
        for (int i=0; i<word.size(); ++i)
        {
            if (word[i] >= 'a' && word[i] <= 'z') lastSeenLowercase[word[i] - 'a'] = i;
            else 
            {
                if (firstSeenUppercase[word[i] - 'A'] != -1) continue;
                firstSeenUppercase[word[i] - 'A'] = i;
            }
        }

        int res = 0;
        for (int i=0; i<lastSeenLowercase.size(); ++i)
        {
            if (lastSeenLowercase[i] != -1 && firstSeenUppercase[i] != -1 && (lastSeenLowercase[i] < firstSeenUppercase[i]))
                res++;
        }

        return res;
    }
};
