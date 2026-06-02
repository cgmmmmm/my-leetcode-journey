class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) 
    {
        int landFirstFinishTime = std::numeric_limits<int>::max();

        // if do land first
        for (int i=0; i<landStartTime.size(); ++i)
        {
            int totalLandTime = landStartTime[i] + landDuration[i];
            for (int j=0; j<waterStartTime.size(); ++j)
            {
                int time = (totalLandTime < waterStartTime[j]) ? waterStartTime[j] : totalLandTime;
                time += waterDuration[j];

                landFirstFinishTime = (landFirstFinishTime > time) ? time : landFirstFinishTime; 
            }
        }

        int waterFirstFinishTime = std::numeric_limits<int>::max();

        // if do water first
        for (int i=0; i<waterStartTime.size(); ++i)
        {
            int totalWaterTime = waterStartTime[i] + waterDuration[i];
            for (int j=0; j<landStartTime.size(); ++j)
            {
                int time = (totalWaterTime < landStartTime[j]) ? landStartTime[j] : totalWaterTime;
                time += landDuration[j];

                waterFirstFinishTime = (waterFirstFinishTime > time) ? time : waterFirstFinishTime; 
            }
        }

        return (landFirstFinishTime > waterFirstFinishTime) ? waterFirstFinishTime : landFirstFinishTime;
    }
};