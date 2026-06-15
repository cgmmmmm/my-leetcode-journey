class MedianFinder {
private:
    std::vector<int> nums;
public:
    MedianFinder() {}
    
    void addNum(int num) {
        auto it = std::lower_bound(nums.begin(), nums.end(), num);
        nums.insert(it, num);
    }
    
    double findMedian() {
        int n = nums.size();
        if (n==1) return nums[0];
        
        int mid = (n-1) / 2;
        if (n%2==0) return (nums[mid] + nums[mid+1]) / 2.0;
        return nums[mid];
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */