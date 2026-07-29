using ull = unsigned long long;

class Solution {
public:
    ull safe_binomial(int n, int m)
    {
        if (m > n - m) 
            m = n - m;

        ull res = 1;
        for (int i=1; i<=m; ++i)
        {
            ull numerator = (n - m + i);
            ull denominator = i;

            ull g = std::gcd(res, denominator);
            res /= g;
            denominator /= g;

            g = std::gcd(numerator, denominator);
            numerator /= g;
            denominator /= g;

            res *= numerator;
        }
        return res;
    }

    ull multinomial_coefficient(int n, std::vector<int>& counts, int k)
    {
        ull calc = 1;
        for (int f : counts)
        {
            if (f == 0) continue;
            if (n <= 0 || calc > 1'000'000 || calc > k) break;
            calc *= safe_binomial(n, f);
            n -= f;
        }

        return calc;
    }

    string smallestPalindrome(string s, int k) 
    {
        int fullLen = s.size();
        char mid;
        if (fullLen % 2 == 1) mid = s[fullLen/2];
        s = s.substr(0, fullLen/2);

        std::vector<int> counts(26, 0);
        for (char ch : s) counts[ch - 'a']++;

        int n = s.size();
        ull numOfPP = multinomial_coefficient(n, counts, k); // number of palindromic permutation
        if (numOfPP < k) return "";

        int remaining_slots = n;
        std::string first_half = "";
        while (remaining_slots > 0)
        {
            for (int i=0; i<26; ++i)
            {
                if (counts[i] > 0)
                {
                    counts[i]--;
                    ull numOfPPChar = multinomial_coefficient(remaining_slots - 1, counts, k);
                    if (numOfPPChar < k)
                    {
                        counts[i]++;
                        k -= numOfPPChar;
                        continue;
                    }
                    first_half += (char) (i + 'a');
                    remaining_slots--;
                    break;
                }
            }
        }

        std::string second_half = "";
        if (mid) second_half += mid;
        for (int i=first_half.size()-1; i>=0; --i)
            second_half += first_half[i];

        return first_half + second_half;
    }
};