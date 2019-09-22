#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size();
        int ans = 0;
        for (int i = 0; i < len; i++) {
            if (nums[i] != val) {
                nums[ans] = nums[i];
                ans++;
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums = {5, 6, 2, 7, 8, 3, 6, 7, 3, 0};
    int val          = 6;
    cout << s.removeElement(nums, val) << endl;
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    return 0;
}