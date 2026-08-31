// the key to solving this problem is:
// track the indices of the smallest nearest bar to the left, calculate boundaries, then multiply the smallest nearest bar and the boundary (for each smallest nearest bar to the left)

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        int n = heights.size();

        int maxArea = INT_MIN;

        std::vector<int> stk;
        stk.reserve(n+1);

        for (int i=0; i<=n; ++i)
        {
            int currh = (i == n) ? 0 : heights[i];
            while (!stk.empty() && heights[stk.back()] >= currh)
            {
                int h = heights[stk.back()];
                stk.pop_back();

                int w = (stk.empty()) ? i : i-stk.back()-1;
                maxArea = std::max(maxArea, h * w);
            }
            stk.emplace_back(i);
        }

        return maxArea;
    }
};

/**
NOTES: below are the approaches tried and failed:
1. naive approach (hit TLE)
2. monotonic stack ((if previous block is less than, pop all prev) && (if next block is less than, pop all prev))
3. greedy ((current potential area < height) ? remove all previous blocks)
4. left to right and right to left pass (greedy, similar to 3)
5. 
*/

/**
Custom testcases:
heights = [5,6,6,6]
heights = [5,7,7,7]
heights = [5,3,6,7,7,7,1]
heights = [5,4,6,7,7,7,1]
heights = [5,3,6,7,3,7,3,7,3,1]
*/