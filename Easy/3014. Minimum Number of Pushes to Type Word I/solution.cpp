class Solution {
public:
    int minimumPushes(string word) 
    {
        // the 1st to 8th characters = 1 push
        // the 9th to 16th character = 2 push
        // the 17th to 24th character = 3 push
        // the 25th to 26th character = 4 push

        std::vector<int> counts(26, 0);
        int res = 0;
        for (int i=0; i<word.size(); ++i)
        {
            int idx = word[i] - 'a';
            if (i <= 7 && counts[idx] == 0)
                counts[idx] = 1;

            if (i >= 8 && i <= 15 && counts[idx] == 0)
                counts[idx] = 2;

            if (i >= 16 && i <= 23 && counts[idx] == 0)
                counts[idx] = 3;

            if (i >= 24 && counts[idx] == 0)
                counts[idx] = 4;

            res += counts[idx];
        }

        return res;
    }
};