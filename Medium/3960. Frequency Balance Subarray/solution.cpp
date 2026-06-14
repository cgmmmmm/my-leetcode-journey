class Solution {
public:
    int getLength(vector<int>& nums) 
    {
        int n = nums.size();
        if (n <= 1) return n;
        
        int maxSize = 1;
        for (int i=0; i<nums.size(); ++i)
        {
            std::unordered_map<int, int> freq;
            std::unordered_map<int, int> freqCount;
            int maxFreq = 0;
            int maxFreqCount = 0;
            for (int j=i; j<nums.size(); ++j)
            {
                int oldFreq = freq[nums[j]];
                freq[nums[j]]++;

                if (oldFreq > 0)
                {
                    freqCount[oldFreq]--;
                    if (oldFreq == maxFreq) maxFreqCount--;
                }
                freqCount[freq[nums[j]]]++;

                if (freq[nums[j]] > maxFreq)
                {
                    maxFreq = freq[nums[j]];
                    maxFreqCount = 1;
                }
                else if (freq[nums[j]] == maxFreq) maxFreqCount++;

                int currSize = j-i+1;
                if (currSize == 1)
                {
                    maxSize = (maxSize < currSize) ? currSize : maxSize;
                    continue;
                }

                int nf = freq.size();
                if (maxFreqCount == nf)
                {
                    if (nf == 1) maxSize = (maxSize < currSize) ? currSize : maxSize;
                }
                else
                {
                    if (maxFreq % 2 == 0 && freqCount[maxFreq/2] == (nf - maxFreqCount))
                        maxSize = (maxSize < currSize) ? currSize : maxSize;
                }
            }
        }
        return maxSize;
    }
};