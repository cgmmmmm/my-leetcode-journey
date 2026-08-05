class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) 
    {
        int res = 0;
        int runningSum = 0;
        int l = 0;
        for (int r=0; r<arr.size(); ++r)
        {
            if (r-l+1 > k)
            {
                runningSum -= arr[l];
                l++;
            }
            runningSum += arr[r];
            if (r-l+1 == k && (runningSum/k >= threshold)) res++;
        }
        return res;
    }
};