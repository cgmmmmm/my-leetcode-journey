class Solution {
public:
    int lastStoneWeight(vector<int>& stones) 
    {
        std::priority_queue<int> max_heap;
        for (int w : stones)
            max_heap.push(w);

        while (max_heap.size() > 1)
        {
            int w1 = max_heap.top();
            max_heap.pop();
            int w2 = max_heap.top();
            max_heap.pop();

            int diff = std::abs(w1 - w2);
            if (diff) 
                max_heap.push(diff);
        }

        return (max_heap.empty()) ? 0 : max_heap.top();
    }
};