#include<queue>

using namespace std;


vector<int> CreateMonotonQueue(vector<int>& nums, int wlen) {
    deque<int> que;
    // 初始化窗口
    for (int i = 0;i < wlen;i++) {
        while (!que.empty() && nums[i] >= nums[que.back()]) {
            que.pop_back();
        }
        que.push_back(i);
    }

    vector<int> res = { nums[que.front()] };

    for (int i = wlen;i < nums.size();i++) {
        // 将i节点插入,i节点插入时会将比i小的值全部弹出
        while (!que.empty() && nums[i] >= nums[que.back()]) {
            que.pop_back();
        }
        que.push_back(i);
        // 如果头节点已经不在窗口节点时，弹出front节点
        if (que.front() < i - wlen + 1) {
            que.pop_front();
        }
        res.push_back(nums[que.front()]);
    }
    return res;
}