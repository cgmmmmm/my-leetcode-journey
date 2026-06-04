class Solution {
public:
    int totalWaviness(int num1, int num2) 
    {
        if (num1 < 100 && num2 < 100) return 0;

        int res = 0;
        for (int num=num1; num<=num2; ++num)
        {
            if (num < 100) continue;
            int n = num;
            int prev = n % 10;
            n /= 10;
            int curr = n % 10;
            n /= 10;
            int next = n % 10;
            n /= 10;
            if ((curr > prev && curr > next) || (curr < prev && curr < next)) res++;
            while (n > 0)
            {
                prev = curr;
                curr = next;
                next = n % 10;
                if ((curr > prev && curr > next) || (curr < prev && curr < next)) res++;
                n /= 10;
            }
        }

        return res;
    }
};