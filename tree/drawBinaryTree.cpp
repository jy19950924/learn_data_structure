#include <string>
#include <deque>

using namespace std;

struct Floor {
    deque<string> lines;
    int width;
    int height;
    int dist;  // 水平距离
    Floor(deque<string> v_lines, int i_width, int i_height, int i_dist)
        : lines(v_lines), width(i_width), height(i_height), dist(i_dist){};
};

Floor draw(TreeNode *root)
{
    if (root->left == nullptr && root->right == nullptr) {
        string s_val = to_string(root->val);
        deque<string> lines = {s_val};
        int width = s_val.size();
        Floor floor = Floor(lines, width, 1, width / 2);
        return floor;
    }
    if (root->left == nullptr) {
        Floor right = draw(root->right);

        string s_val = to_string(root->val);
        string s_nodeFloor = s_val + string("_", right.dist) + string("_", right.width - right.dist);
        // 计算s_flagFloor 时-1是减去\\的值
        string s_flagFloor = string(" ", s_val.size() + right.dist) + "\\" + string(" ", right.width - right.dist - 1);
        for (int i = 0; i < right.lines.size(); i++) {
            right.lines[i] = string(" ", s_val.size()) + right.lines[i];
        }
        right.width += s_val.size();
        right.height += 2;
        right.dist = s_val.size() / 2;
        right.lines.push_front(s_flagFloor);
        right.lines.push_front(s_nodeFloor);
        return right;
    }
    if (root->right == nullptr) {
        Floor left = draw(root->left);

        string s_val = to_string(root->val);
        string s_nodeFloor = string(" ", left.dist + 1) + string("_", left.width - left.dist - 1) + s_val;
        string s_flagFloor = string(" ", left.dist) + "/" + string(" ", left.width - left.dist - 1 + s_val.size());
        for (int i = 0; i < left.lines.size(); i++) {
            left.lines[i] += string(" ", s_val.size());
        }
        left.width = left.width + s_val.size();
        left.height += 2;
        left.dist = left.dist + s_val.size() / 2;
        left.lines.push_front(s_flagFloor);
        left.lines.push_front(s_nodeFloor);
        return left;
    }
    Floor left = draw(root->left);
    Floor right = draw(root->right);
    string s_val = to_string(root->val);
    string s_nodeFloor = string(" ", left.dist + 1) + string("_", left.width - left.dist - 1) + s_val +
                         string("_", right.dist) + string(" ", right.width - right.dist);
    string s_flagFloor = string(" ", left.dist) + "/" + string(" ", left.width - left.dist - 1) +
                         string(" ", s_val.size()) + string(" ", right.dist) + "\\" +
                         string(" ", right.width - right.dist - 1);
    int index = 0;
    while (index < left.lines.size()) {
        if (index < right.lines.size()) {
            left.lines[index] += string(" ", s_val.size()) + string(" ", right.width);
        } else {
            left.lines[index] = left.lines[index] + string(" ", s_val.size()) + right.lines[index];
        }
        index++;
    }
    string s_spaceLeft = string(" ", left.width);
    while (index < right.lines.size()) {
        left.lines.push_back(s_spaceLeft + string(" ", s_val.size()) + right.lines[index]);
        index++;
    }
    left.width = left.width + s_val.size() + right.width;
    left.height = left.height > right.height ? (left.height + 2) : (right.height + 2);
    left.dist = left.width + (s_val.size()) / 2;

    return left;
}

int main()
{
    int data[] = {1, 2, 3};
    int len = sizeof(data) / sizeof(int);

    Tree *ptree = new Tree(data, len);

    deque<string> que = {"nice"};
    // Floor floor = Floor(que, 1, 2, 3);
    Floor floor = draw(ptree->root);

    for (int i = 0; i < floor.lines.size(); i++) {
        cout << floor.lines[i] << endl;
    }
    return 0;
}
