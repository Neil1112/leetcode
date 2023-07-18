#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// function that calculates the edit distance between two strings
// using dynamic programming - tabulation
// returns - edit distance between the two strings
 int minDistance(string word1, string word2) {
    int word1_size = word1.size();
    int word2_size = word2.size();
    // tabulation method
    vector<vector<int>> dp_table(word1_size + 1, vector<int>(word2_size + 1, 0));

    // table initialisation
    for (int i = 0; i <= word1_size; i++) {
        dp_table[i][0] = i;
    }
    for (int j = 0; j <= word2_size; j++) {
        dp_table[0][j] = j;
    }

    for (int i = 1; i <= word1_size; i++) {
        for (int j = 1; j <= word2_size; j++) {
            // if the characters are the same, then use the previous diagonal value
            if (word1[i-1] == word2[j-1]) {
                dp_table[i][j] = dp_table[i-1][j-1];
            }
            // else take the min of [i-1][j], [i][j-1] and [i-1][j-1] and add 1
            else {
                dp_table[i][j] = min(min(dp_table[i-1][j], dp_table[i][j-1]), dp_table[i-1][j-1]) + 1;
            }
        }           
    }

    return dp_table[word1_size][word2_size];
}


int main() {
    string word1, word2;

    // test case 1
    word1 = "horse";
    word2 = "ros";
    cout << "Test case 1: " << endl;
    cout << "Word 1: " << word1 << endl;
    cout << "Word 2: " << word2 << endl;
    cout << "Edit distance: " << minDistance(word1, word2) << endl;

    // test case 2
    word1 = "intention";
    word2 = "execution";
    cout << endl;
    cout << "Test case 2: " << endl;
    cout << "Word 1: " << word1 << endl;
    cout << "Word 2: " << word2 << endl;
    cout << "Edit distance: " << minDistance(word1, word2) << endl;

    return 0;
}