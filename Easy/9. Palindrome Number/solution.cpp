class Solution {
public:
    bool isPalindrome(int x) 
    {
        if (x < 0) return false;
        
        int arr[10] = {};
        int l = 0, r = 0;
        int rm = 0;
        while (x != 0)
        {
            rm = x % 10;
            arr[r++] = rm;
            x /= 10;
        }
        r--;
        
        while (l < r)
        {
            if (arr[l++] != arr[r--]) return false;
        }

        return true;
    }
};