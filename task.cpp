#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        int balance = 0;
        for (char c : s) {
            if (c == '(') balance++;
            else balance--;
              if (balance < 0) return false;
        }
        return balance == 0; }
    
    int longestValidParentheses(string s) {
        int n = s.length();
        int maxLen = 0;
    for (int i = 0; i < n; i++) {
            for (int j = i + 2; j <= n; j += 2) { 
                string sub = s.substr(i, j - i);
                if (isValid(sub)) {
                    maxLen = max(maxLen, j - i);
                }
            }
        }
        return maxLen;}
};
int main() 
{

    Solution sol;
    cout<<sol.longestValidParentheses("(()")<<endl;      
    cout<<sol.longestValidParentheses(")(())())")<<endl;    
           
    return 0;
};