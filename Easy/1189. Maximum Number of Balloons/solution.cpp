class Solution {
public:
    int maxNumberOfBalloons(string text) {
        std::vector<int> balloon(26, 0);
        balloon[1] = 1; // b
        balloon[0] = 1; // a
        balloon[11] = 2; // l
        balloon[14] = 2; // o
        balloon[13] = 1; // n

        std::vector<int> freq(26, 0);
        for (char c : text) freq[c - 'a']++;

        int b = balloon[1];
        int a = balloon[0];
        int l = balloon[11];
        int o = balloon[14];
        int n = balloon[13];
        int res = 0;
        while (b <= freq[1] && a <= freq[0] && l <= freq[11] && o <= freq[14] && n <= freq[13])
        {
            freq[1]--;
            freq[0]--;
            freq[11] -= 2;
            freq[14] -= 2;
            freq[13]--;
            res++;
        }

        return res;
    }
};