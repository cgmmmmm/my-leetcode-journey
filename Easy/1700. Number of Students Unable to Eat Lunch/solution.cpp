class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = sandwiches.size();

        std::queue<int> q(students.begin(), students.end());
        
        int zeros=0, ones=0;
        for (int pref : students)
        {
            if (!pref) zeros++;
            else ones++; 
        }

        int j=0;
        while (j < n)
        {
            if (!zeros && sandwiches[j] == 0 || !ones && sandwiches[j] == 1)
                break;

            int pref = q.front();
            if (pref == sandwiches[j])
            {
                if (pref == 0) zeros--;
                else ones--;
                j++;
                q.pop();
            }
            else
            {
                q.push(pref);
                q.pop();
            }
        }

        return zeros + ones;
    }
};