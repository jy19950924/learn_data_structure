//
// Created by dell on 9/11/2022.
//
#include "../../public.h"

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 *  题目含义：
 *      将 列表根据x值进行划分
 */
class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        if (head == nullptr) return nullptr;
        ListNode *smallHead = nullptr;
        ListNode *smallTail = nullptr;
        ListNode *equalHead = nullptr;
        ListNode *equalTail = nullptr;
        ListNode *highHead = nullptr;
        ListNode *highTail = nullptr;
        // 根据每个元素的大小来进行划分，同时将划分结果放置在对应头尾节点段中，
        //      如果头尾中存在元素，则向尾部挂载；
        //      如果不存在，将该元素为头节点，同时刷新尾节点。
        while (head != nullptr) {
            ListNode *next = head->next;
            if ((head->val) < x) {
                if (smallHead == nullptr) {
                    smallHead = head;
                    smallTail = head;
                } else {
                    smallTail->next = head;
                    smallTail = smallTail->next;
                }
            } else if ((head->val) > x) {
                if (highHead == nullptr) {
                    highHead = head;
                    highTail = head;
                } else {
                    highTail->next = head;
                    highTail = highTail->next;
                }
            } else {
                if (equalHead == nullptr) {
                    equalHead = head;
                    equalTail = head;
                } else {
                    equalTail->next = head;
                    equalTail = equalTail->next;
                }
            }
            head = next;
        }

        // 将三段链表进行首尾相接。 此时需要判断各段是否存在。
        if (highHead != nullptr && equalHead != nullptr && smallHead != nullptr) {
            equalTail->next = highHead;
            smallTail->next = equalHead;
            return smallHead;
        } else if (smallHead == nullptr && equalHead != nullptr && highHead != nullptr) {
            equalTail->next = highHead;
            return equalHead;
        } else if (equalHead == nullptr && smallHead != nullptr && highHead != nullptr) {
            smallTail->next = highHead;
            return smallHead;
        } else if (highHead == nullptr && smallHead != nullptr && equalHead != nullptr) {
            smallTail->next = equalHead;
            return smallHead;
        } else {
            if (smallHead != nullptr)
                return smallHead;
            else if (equalHead != nullptr)
                return equalHead;
            else
                return highHead;
        }
    }
};

int main() {
    vector<int> vals = {1, 4, 3, 2, 5, 2};
    ListNode *head = new ListNode(vals[0]);
    ListNode *tail = head;
    for (int i = 1; i < vals.size(); i++) {
        tail->next = new ListNode(vals[i]);
    }
    Solution sl = Solution();
    ListNode *res = sl.partition(head, 3);

    while (res != nullptr) {
        cout << res->val << "->";
    }
    cout<<endl;
}