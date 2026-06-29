class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int res = 0;
        for (std::string p : patterns)
            if (word.contains(p)) res++;

        return res;
    }
};