class MedianFinder {
private:
    // use a max heap to store the lesser half of all added numbers
    // this allows for O(1) lookup to get the maximum element
    std::priority_queue<int> maxH;

    // use a min heap to store the greater half of all added numbers
    // this allows for O(1) lookup to get the minimum element
    std::priority_queue<int, std::vector<int>, std::greater<int>> minH;

public:
    // to get the median of a sorted list of numbers,
    // if list size is even: (maxH size == minH size)
    //   we can add the maximum element of the lesser half,
    //   and the minimum element of the greater half
    // if list size is odd: (maxH size and minH size has a difference of 1)
    //   we take the maximum element of the lesser half if max heap size is greater by one
    //   we take the minimum element of the greater half if min heap size is greater by one

    // TWO conditions must be satisfied for each addNum operation
    // 1. all elements in greater heap must be >= all elements in lesser heap
    // 2. the size difference of two heaps after processing addNum should never exceed 1  

    // we can check the first condition in O(1) time by checking if the max element in lesser heap 
    // is less than or equal to the min element in the greater heap

    MedianFinder() {}
    
    void addNum(int num) {
        maxH.push(num);
        
        minH.push(maxH.top());
        maxH.pop();

        if (maxH.size() < minH.size())
        {
            maxH.push(minH.top());
            minH.pop();
        }
    }
    
    double findMedian() {
        if (maxH.size() > minH.size())
            return maxH.top();
        return (minH.top() + maxH.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */