using ll = long long;

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();

        // spells[i] * potions[j] >= success
        std::vector<int> pairs(n, 0);
        std::sort(potions.begin(), potions.end());

        for (int i=0; i<n; ++i)
        {
            int l = 0;
            int r = m-1;
            int mid;
            int pivotIdx = m;
            while (l <= r)
            {
                mid = l + (r - l) / 2;
                ll product = (ll) potions[mid] * spells[i];
                if (product >= success)
                {
                    pivotIdx = mid;
                    r = mid-1;
                }
                else
                    l = mid+1;

            }

            pairs[i] = m - pivotIdx;
        }

        return pairs;
    }
};