//
// Created by dell on 9/6/2022.
//
/**
*   桶排序：包括 计数排序 基数排序
 *   基数排序：
 *      1.步骤：
 *          根据个位数字来放入桶里
 *          从中依次弹出元素
 *          根据十位数字来放入桶里
 *          从中依次弹出元素
 *          。。。
 *      2.思路
 *          (1).如果i位不一致时，则在根据i位入bucket时，依旧会按照0~9的顺序来弹出。
 *          (2).在对i位入bucket时，i,i+1,i+2...均相等的数的相对位置已经位有序。
 *
 *          022，021，032，031，001，100
*/
#include "../../public.h"

vector<int> bucketSort(vector<int> arr, int L, int R, int digit) {
    int radix = 10;
    for (int i = 0; i < digit; i++) {
        vector<int> count(radix, 0);
        vector<int> help(arr.size(), 0);
        for (int j: arr) {
            int bit = (j / int(pow(radix, i))) % radix;
            count[bit]++;
        }
        for (int j = 1; j < radix; j++) {
            count[j] = count[j] + count[j - 1];
        }
        for (int j = R; j >= L; j--) {
            int bit = (j / int(pow(radix, i))) % radix;
            help[count[bit]-- - 1] = arr[j];
        }
        arr = help;
    }
    return arr;
}