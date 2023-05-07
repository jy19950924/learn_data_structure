#include<iostream>
#include<vector>
#include<tuple>
#include<cassert>

using std::vector;
using std::tuple;

class BinarySearch {
    // 找到target值，返回对应的下标；未找到则返回-1；
public:

    // 模板1：将left和right均不包含 medium位置.
    int binarySearch_1(const vector<int>& nums, int target) {
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

    int binarySearch_2(const vector<int>& nums, int target) {
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
};


int main() {
    vector<tuple<vector<int>, int, int>> samples = {
        {{-1,0,3,5,9,12}, 9, 4},
        {{-1,0,3,5,9,12},2,-1}
    };

    BinarySearch sole;
    for (const auto sample : samples) {
        assert(sole.binarySearch_2(std::get<0>(sample), std::get<1>(sample)) == std::get<2>(sample));
        assert(sole.binarySearch_1(std::get<0>(sample), std::get<1>(sample)) == std::get<2>(sample));
    }

    return 0;
}


