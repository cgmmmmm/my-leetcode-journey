class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        int n = nums.size();
        std::unordered_map<int, int> freq;
        for (int n : nums) freq[n]++;

        struct ElementsFrequency
        {
            int frequency;
            int element;
            bool operator<(const ElementsFrequency& other) const
            {
                return frequency > other.frequency;
            }
        };

        std::vector<ElementsFrequency> v;
        for (const auto& [element, frequency] : freq)
        {
            v.push_back({frequency, element});
        }

        std::nth_element(v.begin(), v.begin() + k, v.end());

        std::vector<int> res;
        res.reserve(k);
        for (int i=0; i<k; ++i)
        {
            res.push_back(v[i].element);
        }

        return res;
    }
};