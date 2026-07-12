class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) 
    {
        int n = arr.size();
        if (n == 0) return {};

        std::vector<std::pair<int, int>> tmp;
        tmp.reserve(n);
        for (int i=0; i<n; ++i)
            tmp.push_back({arr[i], i});

        std::sort(tmp.begin(), tmp.end(), [](std::pair<int, int>& a, std::pair<int, int>& b){
            return a.first < b.first;
        });

        std::vector<int> res(n);
        res[tmp[0].second] = 1;
        int rank = 1;
        for (int i=1; i<n; ++i)
        {
            if (tmp[i].first == tmp[i-1].first)
                res[tmp[i].second] = rank;
            else
                res[tmp[i].second] = ++rank;
        }

        return res;
    }
};