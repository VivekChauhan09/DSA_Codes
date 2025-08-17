#include<bits/stdc++.h>
using namespace std;

// Recursive function to find the length of the LCS between two strings
int lcs(string &s1, string &s2, int m, int n) {
    
    if (m == 0 || n == 0)
        return 0;
    
    // If the characters at the current positions are equal,
    // include this character in the LCS and move to the next characters
    if (s1[m - 1] == s2[n - 1])
        return 1 + lcs(s1, s2, m - 1, n - 1);
    
    // If the characters are not equal, recursively explore two possibilities:
    // 1. Exclude the last character of the first string
    // 2. Exclude the last character of the second string
    else
        return max(lcs(s1, s2, m - 1, n), lcs(s1, s2, m, n - 1));
}

int main() {
    // Input two strings
    string s1, s2;
    cin >> s1 >> s2;
    
    // Get the lengths of the strings
    int m = s1.size();
    int n = s2.size();
    
    // Calculate the length of the LCS using the recursive function
    int ans = lcs(s1, s2, m, n);
    
    // Output the result
    cout << "Max LCS length: " << ans;
    return 0;
}
