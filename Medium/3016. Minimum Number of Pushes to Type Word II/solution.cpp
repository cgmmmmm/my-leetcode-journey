class Solution {
public:
    int minimumPushes(string word) 
    {
        std::vector<int> counts(26, 0);
        for (char ch : word)
            counts[ch - 'a']++;
        
        std::sort(counts.rbegin(), counts.rend());

        int res = 0;
        for (int i=0; i<26; ++i)
        {
            if (counts[i] == 0) break;

            int cost = (i / 8) + 1;
            res += counts[i] * cost;
        }

        return res;
    }
};