class Solution {
public:
    int calculate(string s) {

        int result = 0;
        int lastNumber = 0;
        int currentNumber = 0;
        char sign = '+';

        int length = s.size();

        for (int i = 0; i < length; i++) {

            char currentChar = s[i];

            if (isdigit(currentChar)) {
                currentNumber = currentNumber * 10 + (currentChar - '0');
            }

            if ((!isdigit(currentChar) && !isspace(currentChar)) || i == length - 1) {

                if (sign == '+' || sign == '-') {

                    result += lastNumber;

                    lastNumber = (sign == '+') ? currentNumber : -currentNumber;
                }

                else if (sign == '*') {
                    lastNumber = lastNumber * currentNumber;
                }

                else if (sign == '/') {
                    lastNumber = lastNumber / currentNumber;
                }

                sign = currentChar;
                currentNumber = 0;
            }
        }

        return result + lastNumber;
    }
};
