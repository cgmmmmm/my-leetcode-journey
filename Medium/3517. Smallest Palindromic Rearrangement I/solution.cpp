class Solution {
public:
    string smallestPalindrome(string s) 
    {
        int abc[26] = {0};
        for (char ch : s) abc[ch - 'a']++;

        int mid = -1;
        for (int i=0; i<26; ++i)
        {
            if (abc[i] % 2 == 1) 
                if (mid == -1) mid = i;
        }

        std::string str(s.size(), ' ');
        int l = 0;
        int r = s.size()-1;
        for (int i=0; i<26; ++i)
        {
            while (abc[i] >= 2)
            {
                str[l++] = (char) (i + 'a');
                str[r--] = (char) (i + 'a');
                abc[i] -= 2;
            }
        }

        if (mid != -1)
        {
            str[s.size()/2] = mid + 'a';
        }
        
        return str;
    }
};