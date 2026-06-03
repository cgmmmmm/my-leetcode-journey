class Solution {
private:
    int solveFinishTime(vector<int>& start1, vector<int>& duration1, vector<int>& start2, vector<int>& duration2)
    {
        int finish1 = INT_MAX;
        for (int i=0; i<start1.size(); ++i)
        {
            finish1 = min(finish1, start1[i] + duration1[i]);
        }

        int finish2 = INT_MAX;
        for (int j=0; j<start2.size(); ++j)
        {
            finish2 = min(finish2, max(finish1, start2[j]) + duration2[j]);
        }

        return finish2;
    }

public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) 
    {
        // land first
        int finishTime1 = solveFinishTime(landStartTime, landDuration, waterStartTime, waterDuration);

        // water first
        int finishTime2 = solveFinishTime(waterStartTime, waterDuration, landStartTime, landDuration);

        return min(finishTime1, finishTime2);
    }
};