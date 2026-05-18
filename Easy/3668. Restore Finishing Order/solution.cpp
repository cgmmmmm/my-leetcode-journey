class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        vector<int> res;
        std::unordered_set<int> s(friends.begin(), friends.end());

        for (int n : order)
        {
            if (s.count(n)) res.push_back(n);
        }

        return res;
    }
};
