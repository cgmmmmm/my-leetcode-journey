class Solution {
public:
    bool validDigit(int n, int x) {
        bool isValid = false;
        while (n > 0)
        {
            int a = n % 10;
            if (n < 10)
            {    
                if (a == x) return false;
            }
            else
            {
                if (a == x) isValid = true;
            }
            n /= 10;
        }

        return isValid;
    }
};