class Solution {
private:
    std::vector<std::string> res;

    std::unordered_map<char, std::string> numToLetterMapping
    {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };

    void backtrack(int it, std::string& combination, const std::string& digits)
    {
        if (combination.size() == digits.size())
        {
            res.push_back(combination);
            return;
        }

        for (char c : numToLetterMapping[digits[it]])
        {
            combination += c;
            backtrack(it+1, combination, digits);
            combination.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) 
    {
        std::string combination = "";
        int it = 0;
        backtrack(it, combination, digits);

        return res;
    }
};
