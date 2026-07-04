class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;

        for (int i = 0; i < num.size(); i++) {
            while (!st.empty() && k > 0 && st.top() > num[i]) {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }

        while (k > 0) {
            st.pop();
            k--;
        }

        if (st.empty())
            return "0";

        string res;

        while (!st.empty()) { //pushing elements into res string from stack
            res += st.top();
            st.pop();
        }

        while (!res.empty() && res.back() == '0') { //removes zeroes from the end of result // 460000
            res.pop_back();
        }

        reverse(res.begin(), res.end()); //as stack pushes in reverse order, we reverse back

        if (res.empty())
            return "0";

        return res;
    }
};
