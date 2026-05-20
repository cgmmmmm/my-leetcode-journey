class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) 
    {
        std::unordered_set<int> seen;
        std::vector<int> C(A.size(), 0);
        int not_common_cnt = 0;

        for (int i=0; i<A.size(); ++i)
        {
            if (A[i] != B[i]) not_common_cnt++;
            if (!seen.empty() && seen.count(A[i])) not_common_cnt--;
            if (!seen.empty() && seen.count(B[i])) not_common_cnt--;

            C[i] = i+1 - not_common_cnt;
            seen.insert(A[i]);
            seen.insert(B[i]);
        }

        return C;
    }
};
