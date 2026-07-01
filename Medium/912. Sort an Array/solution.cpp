class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
        for (int num : nums)
            pq.push(num);

        std::vector<int> res;
        while (!pq.empty())
        {
            res.push_back(pq.top());
            pq.pop();
        }

        return res;
    }
};