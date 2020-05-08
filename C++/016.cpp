#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());  //先排序
        int res = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < nums.size(); i++) {
            int l = i + 1;//左指针
            int r = nums.size() - 1;//右指针
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (abs(sum - target) < abs(res - target)) {
                    res = sum;
                }
                if (sum > target) {
                    r--;
                } else if (sum < target) {
                    l++;
                } else {
                    return sum;//等于target直接输出
                }
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums = {-1, 2, 1, -4};
    int target       = 1;
    cout << s.threeSumClosest(nums, target);
    return 0;
}