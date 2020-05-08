#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) return 0;
        int ans = 0;
        for (int i = 1; i < len; i++) {
            if (nums[i] == nums[i - 1]) {
                nums[ans] = nums[i];
            } else {
                ans++;
                nums[ans] = nums[i];
            }
        }
        return ans + 1;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 1, 2, 2, 3, 3, 3, 4};
    cout << s.removeDuplicates(nums) << endl;
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    return 0;
}