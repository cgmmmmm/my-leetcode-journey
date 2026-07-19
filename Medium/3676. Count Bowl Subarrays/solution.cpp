using ll = long long;

class Solution {
public:
    long long bowlSubarrays(vector<int>& nums) 
    {
        // while curr > ms.top(), ms.pop() and keep track of the ms.top() as prev
        // if prev < curr and prev < the new ms.top(), then its a bowl

        ll res = 0;

        std::stack<int> ms; // monotonic stack
        for (int num : nums)
        {
            while (!ms.empty() && num > ms.top())
            {
                int prev = ms.top();
                ms.pop();
                if (!ms.empty() && prev < num && prev < ms.top())
                    res++;
            }

            ms.push(num);
        }

        return res;
    }
};