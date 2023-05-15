#include <algorithm>
#include <iostream>
#include <vector>

class QuickSort {
public:
  QuickSort(std::vector<int> &nums) { _Process(nums, 0, nums.size() - 1); }

private:
  void _Process(std::vector<int> &nums, int L, int R) {
    if (L > R) // 递归时,入参会做减法,所以要校验L和R位置
      return;
    int head = L, tail = R;
    _Partition(nums, L, R);

    _Process(nums, head, L - 1);
    _Process(nums, R + 1, tail);
  }
  // 分组.  [Head,Left) [Left,Right] (Right,Tail]
  void _Partition(std::vector<int> &nums, int &L, int &R) {
    int T = R; // target
    int C = L; // current

    while (C < R) {
      if (nums[C] < nums[T]) {
        std::swap(nums[C++], nums[L++]);
      } else if (nums[C] > nums[T]) {
        std::swap(nums[--R], nums[C]);
      } else {
        C++;
      }
    }
    std::swap(nums[R], nums[T]);
  }
};

int main() {
  std::vector<int> data = {5, 5, 2, 6, 4, 3, 5, 7, 4, 4};
  QuickSort q(data);

  for (auto ele : data) {
    std::cout << ele << " ";
  }
  std::cout << std::endl;
  return 0;
}
