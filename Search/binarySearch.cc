#include<iostream>
#include<vector>

using std::vector;

class BinarySearch {
    // 找到target值，返回对应的下标；未找到则返回-1；
public:

    // 模板1：将left和right均不包含 medium位置.
    int binarySearch_1(vector<int>& nums, int target) {
        int len = nums.size();
        int left = 0, right = len - 1;
        int medium;

        while (left < len && right < len && left < right) {
            medium = left + (right - left) / 2;
            if (nums[medium] < target) {
                left = medium + 1;
            } else if (nums[medium] > target) {
                right = medium - 1;
            } else {
                return medium;
            }
        }
        return -1;
    }

}

