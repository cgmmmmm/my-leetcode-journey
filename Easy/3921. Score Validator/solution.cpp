class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) 
    {
        std::vector<int> res(2, 0);

        for (int i=0; i<events.size(); ++i)
        {
            if (res[1] == 10) break;

            if (events[i] == "W") res[1]++;
            else if (events[i] == "WD" || events[i] == "NB") res[0]++;
            else res[0] += std::stoi(events[i]);
        }

        return res;
    }
};