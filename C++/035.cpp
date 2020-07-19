#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
   public:
    int searchInsert(vector<int>& nums, int target) {
        //二分法
        int n   = nums.size();
        int l   = 0;
        int r   = n - 1;
        int ans = n;
        while (l <= r) {
            int mid = ((r - l) >> 1) + l;
            if (target <= nums[mid]) {
                ans = mid;
                r   = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};

int main() {
    return 0;
}