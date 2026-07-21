class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();

        std::vector<std::pair<double, int>> v(n);
        for (int i=0; i<n; ++i)
        {
            double ratio = static_cast<double>(wage[i]) / quality[i];
            v[i] = {ratio, quality[i]};
        }

        std::sort(v.begin(), v.end(), [](const auto& a, const auto& b){
            return a.first < b.first;
        });

        std::priority_queue<int> max_heap;
        double q_sum = 0;
        double min_cost = DBL_MAX;
        for (int i=0; i<n; ++i)
        {
            double r_peak = v[i].first;
            q_sum += v[i].second;
            max_heap.push(v[i].second);
            
            if (max_heap.size() > k)
            {
                q_sum -= max_heap.top();
                max_heap.pop();
            }

            if (max_heap.size() == k)
                min_cost = std::min(min_cost, r_peak * q_sum);
        }

        return min_cost;
    }
};