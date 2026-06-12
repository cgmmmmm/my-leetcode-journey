class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;
        
        int l = 0;
        int r = n-1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            bool leftLesser = (mid == 0) || (nums[mid] > nums[mid - 1]);
            bool rightLesser = (mid == n-1) || (nums[mid] > nums[mid + 1]);
            if (leftLesser && rightLesser) 
                return mid;

            if (mid < n - 1 && nums[mid] < nums[mid + 1])
                l = mid + 1;
            else
                r = mid - 1;
        }

        return -1;
    }
};