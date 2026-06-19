class Solution {
    public int largestAltitude(int[] gain) {
        int res=0, alt=0;
        for (int g : gain)
        {
            alt += g;
            res = (alt > res) ? alt : res; 
        }
        return res;
    }
}