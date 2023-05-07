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

        // 不需要判断left和right上下限,因为left<right,其中left只增加,而right只减;
        while (left < right) {
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

    int binarySearch_2(vector<int>& nums, int target) {
        int len = nums.size();
        int left = 0, right = len - 1, medium;

        while (left < right) {
            medium = left + (right - left) / 2;
            if (nums[medium] < target) {
                left = medium + 1;
            } else {
                right = medium;
            }
        }
        return (nums[left] == target) ? (left) : (-1);
    }
}


