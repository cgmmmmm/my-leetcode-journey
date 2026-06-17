class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        std::vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        std::priority_queue<std::pair<char, int>> max_heap;        
        for (int i=0; i<26; ++i)
        {
            if (freq[i] > 0) 
                max_heap.push({(char)('a' + i), freq[i]});
        }

        std::string res = "";

        while (!max_heap.empty())
        {
            auto [curr_char, curr_count] = max_heap.top();
            max_heap.pop();

            int limit = std::min(curr_count, repeatLimit);
            res.append(limit, curr_char);
            curr_count -= limit;

            if (curr_count > 0)
            {
                if (max_heap.empty()) break;

                auto [next_char, next_count] = max_heap.top();
                max_heap.pop();

                res.push_back(next_char);
                next_count--;

                if (next_count > 0) max_heap.push({next_char, next_count});

                max_heap.push({curr_char, curr_count});
            }
        }

        return res;
    }
};