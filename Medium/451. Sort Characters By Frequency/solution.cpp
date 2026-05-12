class Solution {
public:
    string frequencySort(string s) 
    {
        std::unordered_map<char, int> freq;
        for (char c : s)
        {
            freq[c]++;
        }

        std::vector<std::pair<int, int>> sortPair(freq.begin(), freq.end());
        std::sort(sortPair.begin(), sortPair.end(), [](const auto& a, const auto& b) 
        {
            return a.second > b.second;
        });

        std::string res = "";
        for (const auto& [character, frequency] : sortPair)
        {
            int cnt = 0;
            while (cnt < frequency)
            {
                res += character;
                cnt++;
            }
        }

        return res;
    }
};
