class Solution {
public:
    int passwordStrength(string password) 
    {
        int res = 0;
        unordered_set<char> seen;
        for (char ch : password)
        {
            if (seen.count(ch)) continue;
            if (ch >= 'a' &&  ch <= 'z') res += 1;
            if (ch >= 'A' &&  ch <= 'Z') res += 2;
            if (std::isdigit(static_cast<unsigned char>(ch))) res+= 3;
            if (ch == '!' || ch == '@' || ch == '#' || ch == '$') res += 5;
            seen.insert(ch);
        }
        return res;
    }
};