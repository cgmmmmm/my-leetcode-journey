class Solution {
public:
    string removeDuplicateLetters(string s) 
    {
        // keep count of characters
        // while a char is lexicographically smaller than prev, remove prev
        // do not remove prev, if prev count == 1

        std::vector<int> abc(26, 0);
        for (char ch : s) abc[ch - 'a']++;

        std::vector<int> seen(26, 0);
        std::string res = "";
        for (char ch : s)
        {
            int idx = ch - 'a';
            abc[idx]--;
            if (seen[idx]) continue;
            
            while (!res.empty() && ch < res.back() && abc[res.back() - 'a'] != 0)
            {
                seen[res.back() - 'a']--;
                res.pop_back();
            }
            seen[idx]++;
            res.push_back(ch);
        }

        return res;
    }
};