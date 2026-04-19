// To count as a valid pair of indices:
// 1. nums2 idx (j) >= nums1 idx (i)
// 2. nums2 elements must be >= nums1 elements 

// return the maximum distance between all valid pair of indices,
// where the distance of the pair is measured by (j - i)

class Solution {
public:
    int binarySearch(int start, int end, int initialValue, std::vector<int>& nums2) {
        int ret = start;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (initialValue > nums2[mid])
            {
                end = mid - 1;
            }
            else
            {   
                start = mid + 1;
            }
        }
        return (ret == start) ? -1 : start-1;
    }

    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int res = 0;
        int end = nums2.size()-1;

        for (int i=0; i<nums1.size(); i++)
        {
            int j = binarySearch(i, end, nums1[i], nums2);
            if (j != -1) {
                res = std::max(res, j-i);
            }
        }

        return res;
    }
};
