class Solution {
public:
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) 
    {
        std::string s = "";
        for (std::string& str : chunks) s+=str;

        int start = 0;
        while (start < s.size() && (s[start] == '-' || s[start] == ' ')) start++;

        int end = s.size()-1;
        while (end >= 0 && (s[end] == '-' || s[end] == ' ')) end--;

        std::vector<std::string> words;
        std::string word = "";
        for (int i=start; i<=end; ++i)
        {
            if (s[i] == '-')
            {
                if (i - 1 >= 0 && i + 1 < s.size() && 
                    (s[i-1] >= 'a' && s[i-1] <= 'z') && 
                    (s[i+1] >= 'a' && s[i+1] <= 'z'))
                {
                    word+=s[i];
                    continue;
                }
                else
                {
                    if (!word.empty()) words.push_back(word);
                    word = "";
                    continue;
                }
            }
            if (s[i] == ' ') 
            { 
                if (!word.empty()) words.push_back(word);
                word = "";
                continue;
            }
            word+=s[i];
        }
        if (!word.empty()) words.push_back(word);

        std::unordered_map<std::string, int> map;
        for (const std::string& w : words)
        {
            map[w]++;    
        }
        
        std::vector<int> res(queries.size(), 0);
        for (int i=0; i<queries.size(); ++i)
        {
            res[i] = map[queries[i]];
        }

        return res;
    }
};
