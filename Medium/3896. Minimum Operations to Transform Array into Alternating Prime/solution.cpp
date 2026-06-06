class Solution {
private:
    std::unordered_set<int> sieveOfErathosthenes(int n)
    {
        std::vector<bool> isPrime(n+1, true);
        if (n >= 0) isPrime[0] = false;
        if (n >= 1) isPrime[1] = false;

        for (int p=2; p*p<=n; ++p)
        {
            if (isPrime[p])
            {
                for (int i=p*p; i<=n; i+=p)
                {
                    isPrime[i] = false;
                }
            }
        }

        std::unordered_set<int> primes;
        for (int p=2; p<=n; ++p)
        {
            if (isPrime[p]) primes.insert(p);
        }

        return primes;
    }

public:
    int minOperations(vector<int>& nums) 
    {
        int maxVal = *std::max_element(nums.begin(), nums.end());
        std::unordered_set<int> primes = sieveOfErathosthenes(maxVal+100);

        int op = 0;
        for (int i=0; i<nums.size(); ++i)
        {
            int num = nums[i];
            if ((i & 1) == 0)
            {
                while (!primes.count(num))
                {
                    op++;
                    num++;
                }
            }
            else
            {
                while (primes.count(num))
                {
                    op++;
                    num++;
                }
            }
        }

        return op;
    }
};