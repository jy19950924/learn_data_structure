//
// Created by dell on 9/4/2022.
//
/**
* 题目要求：输入字符串
 *  1. 进行排序
 *  2. 稳定
 *  3. 不处理其他字符
 *
 * 解：采用归并排序。由于快速排序为非稳定算法。需要移动数组内容，影响性能。
 *
 *  思路1:
 *      1. 采用归并排序时，在merge时，根据help数组的位置来区分非英文字符。
 *      2. 如果i位置为非英文字符，则将非字符放入help对应位置处。
 *      3. 如果i位置为英文字符，则选择左右两部分中最小英文字母放入。
 *          易错点0：判断p1,p2两个指针数值大小后，才寻找英文字母，会产生问题点是：判断时走的双边路径，但是后面找到英文字母后，发现其实已经是单边。
 *          解决方案：
 *              1. 在判断i位置不能放置非英文字母后，需要判断左右两部分的指针p1,p2指向变量，此时是否仍为英文字母。
 *                  如果不是，则需要找到距离p1，p2两个指针最近的英文字母。

*/

#include "../../public.h"

int compare(const char &ch1, const char &ch2) {
    if ((ch1 >= 'a' && ch1 <= 'z' && ch2 >= 'a' && ch2 <= 'z') ||
        (ch1 >= 'A' && ch1 <= 'Z' && ch2 >= 'A' && ch2 <= 'Z')) {
        return ch1 - ch2;
    } else if (ch1 >= 'a' && ch1 <= 'z') {
        return (ch1 - 'a') - (ch2 - 'A');
    } else {
        return (ch1 - 'A') - (ch2 - 'a');
    }
}

bool isFlag(const char &n) {
    if ((n >= 'a' && n <= 'z') || (n >= 'A' && n <= 'Z')) {
        return false;
    }
    return true;
}

// -------- merge sort
void merge(string &s, int L, int M, int R) {
    int len = R - L + 1;
    string help = string(len, 0);

    int p1 = L;
    int p2 = M;
    int i = 0;
    while (i < len) {
        if (isFlag(s[i + L])) {
            help[i++] = s[i + L];
        } else {
            while (isFlag(s[p1]) && (p1 < M)) p1++;
            while (isFlag(s[p2]) && (p2 <= R)) p2++;
            if (p1 < M && p2 <= R) {
                if (compare(s[p1], s[p2]) <= 0) {
                    // 说明left <= right, 将小的数字推入help中
                    help[i++] = s[p1++];
                } else {
                    help[i++] = s[p2++];
                }
            } else if (p1 < M) {

                help[i++] = s[p1++];
            } else {
                help[i++] = s[p2++];
            }
        }


    }
    s.replace(L, help.size(), help);
}

void process(string &s, int L, int R) {
    if (L >= R)return;

    int M = L + (R - L + 1) / 2;

    process(s, L, M - 1);
    process(s, M, R);
    merge(s, L, M, R);
}

string mergeSort(string s) {
    string res = s;
    process(res, 0, res.size() - 1);
    return res;
}
// ---------- merge sort end

string stringSort(string s) {
    return mergeSort(s);

}

int main() {
    //          0123456789A123456789B123456789C123456789D123456789
    string s = "A Famous Saying: Much Ado About Nothing (2012/8).";
    string res = stringSort(s);
    string target = "A aaAAbc dFgghh: iimM nNn oooos Sttuuuy (2012/8).";
    if (res == target)
        cout << "True" << endl;
    else
        cout << "False" << endl;
    return 0;
}

