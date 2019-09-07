#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> res;
        int length = nums.size();
        sort(nums.begin(), nums.end());  //先排序
        for (int i = 0; i < length; i++) {
            if (nums[i] > 0) {
                break;
            }
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int l = i + 1;
            int r = length - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == 0) {
                    res.push_back({nums[i], nums[l], nums[r]});
                    while (l < r && nums[l] == nums[l + 1]) {
                        l++;  //去重
                    }
                    while (l < r && nums[r] == nums[r - 1]) {
                        r--;  //去重
                    }
                    l++;
                    r--;
                } else if (sum < 0) {
                    l++;
                } else if (sum > 0) {
                    r--;
                }
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums        = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> res = s.threeSum(nums);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < 3; j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}