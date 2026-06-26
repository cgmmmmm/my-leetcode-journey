class Solution {
public:
    int reverse(int x) {
        const int MAX_MUL = 1'000'000'000;

        std::queue<int> q;
        int num = x;
        while (num != 0)
        {
            q.push(num % 10);
            num /= 10;
        }
        while (q.front() == 0) q.pop();

        int n = q.size();
        if (n > 10) return 0;

        int res = 0;
        int mul = std::pow(10, n - 1);
        if (mul == MAX_MUL && (q.front() < -2 || q.front() > 2)) return 0;
        while (!q.empty())
        {
            int a = q.front() * mul;
            if (((x > 0) && (INT_MAX - res - a < 0)) || ((x < 0) && (INT_MIN - res - a > 0)))
                return 0;

            res += a;

            mul /= 10;
            q.pop();
        }

        return res;
    }
};