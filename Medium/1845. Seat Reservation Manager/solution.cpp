class SeatManager {
private:
    // min heap for unreserved seat
    std::priority_queue<int, std::vector<int>, std::greater<int>> unreserved;
    int marker;
public:
    SeatManager(int n) { marker = 1; }
    
    int reserve()
    {
        if (!unreserved.empty())
        {
            int seatNumber = unreserved.top();
            unreserved.pop();
            return seatNumber;
        }
        
        int seatNumber = marker;
        marker++;
        return seatNumber;
    }
    
    void unreserve(int seatNumber) 
    {
        unreserved.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */