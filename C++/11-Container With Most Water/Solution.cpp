#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int maxArea(vector<int>& height) {
        int max = 0;
        int l   = 0;
        int r   = height.size() - 1;
        while (l < r) {
            int cur = (height[l] < height[r] ? height[l] : height[r]) * (r - l);
            max     = max > cur ? max : cur;
            //两侧指针向内移动时
            //短的一侧移动可能使面积增大
            //而高侧若移动，即使中间有很长的线，面积也会受限于短侧线长
            //
            if (height[l] < height[r]) {
                l++;

            } else {
                r--;
            }
        }
        return max;
    }
};