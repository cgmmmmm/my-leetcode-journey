class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) 
    {
        std::string res = "";
        for (std::string& word : words)
        {
            int w = 0;
            for (const char& c : word)
            {
                w += weights[c - 'a'];
            }
            w %= 26;
            res += static_cast<char>(122 - w);
        }
        
        return res;
    }
};