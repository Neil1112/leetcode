#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// function that returns the indices of the two numbers that add up to the target
// using a hash map to keep track of the numbers that have been seen
// checks if the complement of the current number is in the hash map
// returns - vector of the indices of the two numbers that add up to the target
vector<int> twoSum(vector<int>& nums, int target) {
    // hashmap to store indices
    unordered_map<int, int> hash_map;
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        int complement = target - nums[i];
        // check if complement is there in the hash_map
        if (hash_map.count(complement)) {
            return {i, hash_map[complement]};
        }
        // else add the current element to the hash_map
        hash_map[nums[i]] = i;
    }

    // No solution found
    return {};
}


int main() {
    vector<int> nums;
    int target;

    // test case 1
    nums = {2, 7, 11, 15};
    target = 9;
    cout << "Test case 1: " << endl;
    cout << "Array: ";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    cout << "Target: " << target << endl;
    cout << "Indices of the two numbers that add up to the target: ";
    vector<int> result = twoSum(nums, target);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    // test case 2
    nums = {3, 2, 4};
    target = 6;
    cout << endl;
    cout << "Test case 2: " << endl;
    cout << "Array: ";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    cout << "Target: " << target << endl;
    cout << "Indices of the two numbers that add up to the target: ";
    result = twoSum(nums, target);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    // test case 3
    nums = {3, 3};
    target = 6;
    cout << endl;
    cout << "Test case 3: " << endl;
    cout << "Array: ";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    cout << "Target: " << target << endl;
    cout << "Indices of the two numbers that add up to the target: ";
    result = twoSum(nums, target);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}