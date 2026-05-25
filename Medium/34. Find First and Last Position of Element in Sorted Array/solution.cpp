class Solution {
public:
    int findFirstOccurenceIndex(int l, int r, const int target, const std::vector<int>& nums)
    {
        int firstOccurenceIndex = -1;
        while (l<=r)
        {
            int mid = l + (r - l) / 2;
            if (nums[mid] > target) r = mid-1;
            else if (nums[mid] < target) l = mid+1;
            else
            {
                firstOccurenceIndex = mid;
                r = mid - 1;
            }
        }
        return firstOccurenceIndex;
    }

    int findLastOccurenceIndex(int l, int r, const int target, const std::vector<int>& nums)
    {
        int secondOccurenceIndex = -1;
        while (l<=r)
        {
            int mid = l + (r - l) / 2;
            if (nums[mid] > target) r = mid-1;
            else if (nums[mid] < target) l = mid+1;
            else
            {
                secondOccurenceIndex = mid;
                l = mid + 1;
            }
        }
        return secondOccurenceIndex;
    }

    vector<int> searchRange(vector<int>& nums, int target) 
    {
        int n = nums.size();
        int firstOccurenceIndex = findFirstOccurenceIndex(0, n-1, target, nums);

        if (firstOccurenceIndex == -1) return {-1, -1};

        int secondOccurenceIndex = findLastOccurenceIndex(firstOccurenceIndex, n-1, target, nums);

        return {firstOccurenceIndex, secondOccurenceIndex};
    }
};
