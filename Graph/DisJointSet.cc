#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>

class DisJointSet {
  std::map<int, int> persons;
  std::set<int> leaders;
  std::map<int, std::set<int>> groups;

public:
  DisJointSet(const std::vector<std::vector<int>> &connects) {
    for (int i = 0; i < connects.size(); i++) {
      for (int j = 0; j < connects[0].size(); j++) {
        if (connects[i][j] == 0)
          continue;

        auto leftLeader = Find(i);
        auto rightLeader = Find(j);
        if (leftLeader != rightLeader) {
          Union(leftLeader, rightLeader);
        }
      }
    }
  }

  int Find(int target) noexcept {
    auto it = persons.find(target);
    if (it == persons.end()) {
      persons.insert({target, target});
      leaders.insert(target);
      groups.insert({target, std::set<int>{target}});
      return target;
    }
    return it->second;
  }
  int Union(int leftLeader, int rightLeader) noexcept {
    auto itLeftSet = groups.find(leftLeader);
    std::set<int> leftSet = itLeftSet->second;
    std::set<int> rightSet = groups.find(rightLeader)->second;
    // update persons
    for (const int ele : rightSet) {
      auto it = persons.find(ele);
      if (it != persons.end()) {
        it->second = leftLeader;
      }
    }
    // update groups
    std::set<int> t_set;
    std::set_union(leftSet.begin(), leftSet.end(), rightSet.begin(),
                   rightSet.end(), std::inserter(t_set, t_set.begin()));
    itLeftSet->second = t_set;
    // update leaders
    auto itRightLeader = leaders.find(rightLeader);
    if (itRightLeader != leaders.end()) {
      leaders.erase(itRightLeader);
    }

    return leftLeader;
  }
  int Count() { return leaders.size(); }
};

int main() {
  std::vector<std::vector<int>> data = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
  DisJointSet djset(data);
  std::cout << djset.Count() << std::endl;
  return 0;
}
