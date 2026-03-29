class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        std::vector<int> even_cnt(26, 0);
        std::vector<int> odd_cnt(26, 0);

        for (int i=0; i<4; i++) {
            if (i==0 || i==2) {
                even_cnt[s1[i] - 'a']++;
                even_cnt[s2[i] - 'a']--;
            }
            else {
                odd_cnt[s1[i] - 'a']++;
                odd_cnt[s2[i] - 'a']--;
            }
        }

        for (int i=0; i<26; i++) {
            if (even_cnt[i] != 0 || odd_cnt[i] != 0) return false;
        }

        return true;
    }
};
