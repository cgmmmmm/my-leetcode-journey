class Solution {
public:
    std::tuple<int, int, int> parseLog(const std::string& log)
    {
        int id=0, status=1, time=0;

        std::string_view view(log);
        auto res1 = std::from_chars(view.data(), view.data() + view.size(), id);
        
        std::string_view remainder(res1.ptr, view.data() + view.size() - res1.ptr);
        if (*(res1.ptr + 1) == 'e') status = 0;

        size_t last_colon = remainder.find_last_of(':');
        const char* time_start = remainder.data() + last_colon + 1;
        const char* time_end = view.data() + view.size();

        auto res2 = std::from_chars(time_start, time_end, time);

        return {id, status, time};
    }

    vector<int> exclusiveTime(int n, vector<string>& logs) 
    {
        // if std::get<1>(tup) == 1 meaning start, else end

        std::vector<int> res(n, 0);
        std::stack<int> stk;
        int prev_time = 0;
        for (const auto& log : logs)
        {
            auto [id, sts, time] = parseLog(log);
            if (sts)
            {
                if (!stk.empty())
                {
                    res[stk.top()] += time - prev_time;
                }
                stk.push(id);
                prev_time = time;
            }
            else
            {
                res[stk.top()] += time - prev_time + 1;
                stk.pop();
                prev_time = time + 1;
            }
        }
        return res;
    }
};