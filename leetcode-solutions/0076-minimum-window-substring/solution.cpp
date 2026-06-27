class Solution {
public:
    string minWindow(string s, string t) {

        // If impossible to form the window
        if (s.empty() || t.empty() || s.length() < t.length())
            return "";

        // Frequency array for ASCII characters.
        // map[c] = how many more of character c we still NEED.
        vector<int> map(128, 0);

        // Number of characters still needed.
        // Initially we need every character of t.
        int count = t.length();

        // Sliding window pointers
        int start = 0;
        int end = 0;

        // Length of best window found
        int minLen = INT_MAX;

        // Starting index of best window
        int startIndex = 0;

        // Store frequency of every character in t.
        for(char c : t)
            map[c]++;

        // Expand the window
        while(end < s.length()) {

            /*
                s[end] is entering the window.

                If map[s[end]] > 0,
                this character was actually needed.

                So we reduce count.

                Then decrement map because this character
                is now inside the window.
            */

            if(map[s[end++]]-- > 0)
                count--;

            /*
                If count == 0,
                every required character is present.
            */

            while(count == 0) {

                // Update minimum answer
                if(end - start < minLen) {
                    minLen = end - start;
                    startIndex = start;
                }

                /*
                    Remove s[start] from the window.

                    First increase its frequency.

                    If its old value was 0,
                    removing it makes the window invalid.

                    Example:
                    Needed exactly one A.
                    Window currently has exactly one A.

                    Removing it means
                    we now need one A again.

                    Therefore increase count.
                */

                if(map[s[start++]]++ == 0)
                    count++;
            }
        }

        if(minLen == INT_MAX)
            return "";

        return s.substr(startIndex, minLen);
    }
};
