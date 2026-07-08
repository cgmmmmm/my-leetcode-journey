class Solution {
public:
    int maxVowels(string s, int k) {
        std::vector<int> abc(26, 0);
        const int a=0, e=4, i=8, o=14, u=20;

        int n = s.size();
        int res = 0;
        int l = 0, r = 0;
        while (r < n)
        {
            abc[s[r] - 'a']++;

            while (r - l + 1 > k)
            {
                abc[s[l] - 'a']--;
                l++;
            }

            if (r - l + 1 == k)
            {
                int swRes = abc[a] + abc[e] + abc[i] + abc[o] + abc[u];
                res = (swRes > res) ? swRes : res;
            }

            r++;
        }

        return res;
    }
};