#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool containsDuplicate(vector<int>& nums) {
    int n = nums.size();
    bool duplicate = false;
    unordered_set<int> num_set;

    for (int num : nums) {
        if(num_set.count(num) > 0)
            return true;
        num_set.insert(num);
    }
    return false;
}

int main() {
    vector<int> nums;

    // test case 1
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(1);
    cout << "Test case 1: " << endl;
    cout << "1, 2, 3, 1" << endl;
    cout << bool(containsDuplicate(nums)) << endl;

    // test case 2
    cout << endl;
    nums.clear();
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    cout << "Test case 2: " << endl;
    cout << "1, 2, 3, 4" << endl;
    cout << bool(containsDuplicate(nums)) << endl;

    // test case 3
    cout << endl;
    nums.clear();
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(4);
    nums.push_back(2);
    cout << "Test case 3: " << endl;
    cout << "1, 1, 1, 3, 3, 4, 3, 2, 4, 2" << endl;
    cout << bool(containsDuplicate(nums)) << endl;

    return 0;
}