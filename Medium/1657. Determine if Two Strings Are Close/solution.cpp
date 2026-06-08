class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        if (n1 != n2) return false;

        std::vector<int> word1CharFreq(26, 0);
        std::vector<int> word2CharFreq(26, 0);
        for (int i=0; i<n1; ++i)
        {
            word1CharFreq[word1[i] - 'a']++;
            word2CharFreq[word2[i] - 'a']++;
        }

        for (int i=0; i<26; ++i)
        {
            if ((word1CharFreq[i] == 0) != (word2CharFreq[i] == 0))
                return false;
        }

        std::sort(word1CharFreq.begin(), word1CharFreq.end());
        std::sort(word2CharFreq.begin(), word2CharFreq.end());

        return word1CharFreq == word2CharFreq;
    }
};