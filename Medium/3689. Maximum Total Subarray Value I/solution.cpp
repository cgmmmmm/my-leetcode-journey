using ll = long long;

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        ll mx = *max_element(nums.begin(), nums.end());
        ll mn = *min_element(nums.begin(), nums.end());

        return (mx - mn) * k;
    }
};