// LeetCode: Decode String
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<int> countSt;
        stack<string> strSt;
        string curr = "";
        int num = 0;

        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            } else if (c == '[') {
                countSt.push(num);
                strSt.push(curr);
                num = 0;
                curr = "";
            } else if (c == ']') {
                int times = countSt.top(); countSt.pop();
                string prev = strSt.top(); strSt.pop();
                string tmp;
                for (int i = 0; i < times; i++) tmp += curr;
                curr = prev + tmp;
            } else {
                curr.push_back(c);
            }
        }
        return curr;
    }
};

