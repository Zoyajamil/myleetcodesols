#include <climits>
#include <string>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.length();
        
        //Skip leading whitespaces
        while (i < n && s[i] == ' ') {
            i++;
        }
        
        //Check sign
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') {
                sign = -1;
            }
            i++;
        }
        
        //Convert digits to number
        long result = 0;  //long to detect overflow
        
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';
            
            //Check overflow before multiplying
            if (result > (INT_MAX - digit) / 10) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }
            
            result = result * 10 + digit;
            i++;
        }
        
        return sign * result;
    }
};

