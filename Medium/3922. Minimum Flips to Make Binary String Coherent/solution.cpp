class Solution {
public:
    int minFlips(string s) 
    {
        // 4 types of coherent string
        // ALL ZEROS: 0000
        // ALL ONES: 1111
        // ONLY ONE ONE's: 1000, 0100, 0010, 0001
        // EXACTLY TWO ONE'S IN THE EDGES: 1001

        int n = s.size();
        if (n < 3) return 0;
        
        bool edges = (s[0] == '1' && s[n-1] == '1');
        int zeroCount = 0;
        int oneCount = 0;
        
        for (int i=0; i<s.size(); ++i)
        {
            if (s[i] == '1') oneCount++;
            else zeroCount++;
        }

        if (oneCount == 0 || oneCount == 1) return 0;
        
        if (edges)
        {
            if (zeroCount > oneCount - 2) return oneCount-2;
            else return zeroCount;
        }
        else
        {
            if (zeroCount >= oneCount) return oneCount-1;
            else return zeroCount;
        }

        return 0;
    }
};