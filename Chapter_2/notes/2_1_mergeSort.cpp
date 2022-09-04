//
// Created by dell on 9/4/2022.
//
#include "../../public.h"

/**
 * 归并排序
 *  1. 思路
 *      首先，将arr两部分进行排序
 *      其次，将两部分进行比较后，较小数字放在help数据中。如果相同，则拷贝左侧部分值
 *
 *      相对于选择排序快速的原因，是因为比较行为没有被浪费而是变成了有序的序列。
 * @return
 */
void merge(vector<int> &arr, int L, int M, int R) {
//   进入此函数，说明 begin，end范围应该是符合的
    int len = R - L + 1;
    vector<int> help(len, 0);
    int p1 = L;
    int p2 = M;
    int i = 0;
    while (p1 < M && p2 <= R) {
        help[i++] = arr[p1] > arr[p2] ? arr[p2++] : arr[p1++];
    }

    while (p1 < M) {
        help[i++] = arr[p1++];
    }
    while (p2 <= R) {
        help[i++] = arr[p2++];
    }

    for (int j = 0; j < len; j++) {
        arr[L + j] = help[i];
    }
}

void process(vector<int> &arr, int begin, int end) {
    if (begin >= end) return;

    int L = begin;
    int R = end;
    int M = begin + (end - begin + 1) / 2;

    process(arr, L, M - 1);
    process(arr, M, R);
    merge(arr, L, M, R);
}


vector<int> mergeSort(vector<int> arr) {
    vector<int> res = arr;
    int len = res.size();
    process(res, 0, len - 1);
    return res;
}

int main() {
    vector<int> arr = {3, 44, 56, 7, 545, 66, 778, 88, 88, 99, 121};
    vector<int> res = mergeSort(arr);
    for (const auto i: res) {
        cout << i << ' ';
    }
    cout << endl;
    return 0;
}
