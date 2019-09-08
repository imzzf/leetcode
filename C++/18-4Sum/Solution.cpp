#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int length = nums.size();
        sort(nums.begin(), nums.end());  //先排序
        for (int i = 0; i < length - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < length - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                int l = j + 1;
                int r = length - 1;
                while (l < r) {
                    int sum = nums[i] + nums[j] + nums[l] + nums[r];
                    if (sum == target) {
                        res.push_back({nums[i], nums[j], nums[l], nums[r]});
                        l++;
                        r--;
                        while (l < r && nums[l] == nums[l - 1]) {
                            l++;  //去重
                        }
                        while (l < r && nums[r] == nums[r + 1]) {
                            r--;  //去重
                        }

                    } else if (sum > target) {
                        r--;
                    } else if (sum < target) {
                        l++;
                    }
                }
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums        = {1, 0, -1, 0, -2, 2};
    int target              = -1;
    vector<vector<int>> res = s.fourSum(nums, target);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < 4; j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}