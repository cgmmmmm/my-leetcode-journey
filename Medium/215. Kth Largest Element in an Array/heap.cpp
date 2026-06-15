class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::priority_queue<int> maxHeap;
        for (int num : nums) maxHeap.push(num);

        while (k-- > 1) maxHeap.pop();
        
        return maxHeap.top();
    }
};

// runtime: O(N + KlogN)
// memory: O(N) auxiliary