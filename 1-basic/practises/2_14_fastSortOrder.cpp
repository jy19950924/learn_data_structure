//
// Created by dell on 9/3/2022.
//
#include "../../public.h"

/**
 * 快速排序，同时，可以通过0，1控制排序升序和降序.
 * 采用递归的方法来实现
 *
 * 细节点1 :
 *      设置left和right时,如果采用如下所示方法，容易出现只有两个元素时的死循环。
 *      a   b   c   d   e   f   g   h
 *      ^                           ^
 *      |                           |
 *      cur                         flag
 *      left                        right
 *      解决方法：如果采用如下方式，就可以解决这个问题
 *          a   b   c   d   e   f   g   h
 *      ^   ^                           ^
 *      |   |                           |
 *      left|                           right
 *          cur                         flag
 *
 * 细节点2：
 *      在分析降序和升序时,在不改变left,right以及cur和flag指针位置前提下，分析升降序逻辑：
 *      desc：
 *          flag < cur : left ,cur
 *          flag > cur : right,cur
 *      asc:
 *          flag > cur : left,cur
 *          flag < cur : right,cur
 *      所以，综合考虑，在判断逻辑时，将 flag == cur逻辑放到else if 中，这样只需要改变 if中逻辑含义，else中逻辑也会同步发生变化。
 *      也就不需要同时修改 flag>cur对应逻辑和flag<cur的逻辑。
 * @return
 */

void partition(vector<int> &arr, int begin, int end, bool desc) {
    if (begin >= end)
        return;

    int left = begin - 1;
    int flag = end;
    int right = end;
    int cur = begin;
    while (cur < right) {
        bool isAsc = !desc ? arr[flag] > arr[cur] : arr[flag] < arr[cur];
        if (isAsc) {
            swap(arr[cur++], arr[++left]);
        } else if (arr[flag] == arr[cur]) {
            cur++;
        } else {
            swap(arr[--right], arr[cur]);
        }
    }
    swap(arr[right], arr[flag]);

    partition(arr, begin, left, desc);
//    left+1,right
    partition(arr, right + 1, end, desc);
}

vector<int> fastSort(vector<int> arr, bool desc) {
    int len = arr.size();
    vector<int> res = arr;
    partition(res, 0, len - 1, desc);
    return res;
}

int main() {
    vector<int> arr = {2, 3, 55, 645, 334, 56, 74, 7, 99, 0};
    vector<int> res = fastSort(arr, true);
    for (const auto i: res) {
        cout << i << ' ';
    }
    cout << endl;
    return 0;
}

