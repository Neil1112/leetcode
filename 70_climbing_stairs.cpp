#include <iostream>
#include <vector>
using namespace std;

// function that returns the number of ways to climb stairs
// step size - 1 and 2
int climbingStairs(int num_of_stairs) {
    // dp - tablulation method
    vector<int> dp_table(num_of_stairs+1);
    dp_table[0] = dp_table[1] = 1;

    for (int i = 2; i <= num_of_stairs; i++) {
        dp_table[i] = dp_table[i-1] + dp_table[i-2];
    }

    return dp_table[num_of_stairs];
}


int main() {
    int num_of_stairs;

    // test case 1
    num_of_stairs = 2;
    cout << "Test case 1: " << endl;
    cout << "Number of stairs: " << num_of_stairs << endl;
    cout << "Number of ways: " << climbingStairs(num_of_stairs) << endl;

    // test case 2
    cout << endl;
    num_of_stairs = 3;
    cout << "Test case 2: " << endl;
    cout << "Number of stairs: " << num_of_stairs << endl;
    cout << "Number of ways: " << climbingStairs(num_of_stairs) << endl;

    // test case 3
    cout << endl;
    num_of_stairs = 4;
    cout << "Test case 3: " << endl;
    cout << "Number of stairs: " << num_of_stairs << endl;
    cout << "Number of ways: " << climbingStairs(num_of_stairs) << endl;

    return 0;
}