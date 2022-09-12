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

class Node {
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val) : val(_val), next(nullptr), random(nullptr) {
//        val = _val;
//        next = NULL;
//        random = NULL;
    }
};


class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        /**
         * 根据x值对链表进行partition
         * 技巧：多指针
         */
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
            head = head->next;
        }

        // 将三段链表进行首尾相接。 此时需要判断各段是否存在。
        if (highHead != nullptr && equalHead != nullptr && smallHead != nullptr) {
            equalTail->next = highHead;
            smallTail->next = equalHead;
            highTail->next = nullptr;
            return smallHead;
        } else if (smallHead == nullptr && equalHead != nullptr && highHead != nullptr) {
            equalTail->next = highHead;
            highTail->next = nullptr;
            return equalHead;
        } else if (equalHead == nullptr && smallHead != nullptr && highHead != nullptr) {
            smallTail->next = highHead;
            highTail->next = nullptr;
            return smallHead;
        } else if (highHead == nullptr && smallHead != nullptr && equalHead != nullptr) {
            smallTail->next = equalHead;
            equalTail->next = nullptr;
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

    Node *copyRandomList(Node *head) {
        /**
         *  细节点1：
         *      a. 不可以在连接random关系时，进行拆分，因为可能存在向后指向的情况。
         *      如果后面节点存在指向该节点的情况，则可能可能会无法找到拷贝节点。
         */
//        1. 拷贝所有节点
        Node *tHead = head;
        while (tHead != nullptr) {
            Node *copyNode = new Node(tHead->val);
            copyNode->next = tHead->next;
            tHead->next = copyNode;
            tHead = tHead->next->next;
        }
//        2. 二次遍历连接random关系
        tHead = head;
        while (tHead != nullptr) {
            Node *copyNode = tHead->next;
            if (tHead->random == nullptr)
                copyNode->random = nullptr;
            else
                copyNode->random = tHead->random->next;
            tHead = tHead->next->next;
        }
//        3. 分离节点
        Node *copyHead = new Node(-1);
        Node *copyTail = copyHead;
        tHead = head;
        while (tHead != nullptr) {
            Node *copyNode = tHead->next;
            Node *nextNode = tHead->next->next;

            tHead->next = nextNode;

            copyTail->next = copyNode;
            copyTail = copyTail->next;

            tHead = tHead->next;
        }
        return copyHead->next;
    }
};

void showNodeList(Node *nodeTail) {
    while (nodeTail != nullptr) {
        int randValue = (nodeTail->random == nullptr) ? -1 : nodeTail->random->val;
        cout << nodeTail->val << "->" << randValue << endl;
        nodeTail = nodeTail->next;
    }
}

int testPartitionList() {
    vector<int> vals = {1, 4, 3, 2, 5, 2};
    ListNode *head = new ListNode(vals[0]);
    ListNode *tail = head;
    for (int i = 1; i < vals.size(); i++) {
        tail->next = new ListNode(vals[i]);
        tail = tail->next;
    }
    Solution sl = Solution();
    ListNode *res = sl.partition(head, 3);

    while (res != nullptr) {
        cout << res->val << "->";
        res = res->next;
    }
    cout << endl;
    return 0;
}

int testCopyRandomList() {
    array<array<int, 2>, 5> arr =
            {
                    array{7, -1},
                    array{13, 0},
                    array{11, 4},
                    array{10, 2},
                    array{1, 0}
            };
    vector<Node *> nodeList(arr.size(), nullptr);
    for (int i = 0; i < arr.size(); i++) {
        Node *node = new Node(arr[i][0]);
        nodeList[i] = node;
    }
    for (int i = 0; i < arr.size(); i++) {
        nodeList[i]->next = nodeList[i + 1];
        if (i == arr.size() - 1) {
            nodeList[i]->next = nullptr;
        }
        if (arr[i][1] == -1) {
            nodeList[i]->random = nullptr;
        } else {
            nodeList[i]->random = nodeList[arr[i][1]];
        }
    }

    Node *nodeHead = nodeList[0];
    Node *nodeTail = nodeHead;
    showNodeList(nodeHead);
    cout<< "=========== copy =============="<<endl;
    Solution s = Solution();
    Node *res = s.copyRandomList(nodeHead);
    showNodeList(res);

    return 0;
}


int main() {
    testCopyRandomList();
}