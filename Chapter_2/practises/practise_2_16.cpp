//
// Created by dell on 9/5/2022.
//
#include "../../public.h"

/**
 *  思路1：
 *      排序后，利用双指针比较两个数组之间的差异即可。
 * @param arr
 * @return
 */

int unorderedArraySort(vector<int> arr) {
    vector<int> help = arr;
    sort(help.begin(), help.end());

    int L = 0;
    int R = arr.size() - 1;
    int res = 0;
    while (L < R && (arr[L] == help[L] || arr[R] == help[R])) {
        L = arr[L] == help[L] ? (L + 1) : (L);
        R = arr[R] == help[R] ? (R - 1) : (R);
    }
    if (L == R)
        return res;

    return R - L + 1;
//    如果相等，则说明无最小排序情况
}

int main() {
    vector<int> arr = {1, 5, 3, 4, 2, 6, 7};

}