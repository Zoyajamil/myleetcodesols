// LeetCode: Stamping The Sequence
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        vector<int> res;
        int n = target.size(), m = stamp.size();
        bool changed = true;
        vector<bool> visited(n, false);
        int stars = 0;

        while (stars < n) {
            bool done = false;
            for (int i = 0; i <= n - m; ++i) {
                if (!visited[i] && canReplace(target, stamp, i)) {
                    stars += doReplace(target, m, i);
                    visited[i] = true;
                    done = true;
                    res.push_back(i);
                    if (stars == n) break;
                }
            }
            if (!done) return {};
        }
        reverse(res.begin(), res.end());
        return res;
    }

private:
    bool canReplace(const string& t, const string& s, int pos) {
        for (int i = 0; i < (int)s.size(); ++i) {
            if (t[i + pos] != '*' && t[i + pos] != s[i]) return false;
        }
        return true;
    }

    int doReplace(string& t, int m, int pos) {
        int cnt = 0;
        for (int i = 0; i < m; ++i) {
            if (t[i + pos] != '*') {
                t[i + pos] = '*';
                cnt++;
            }
        }
        return cnt;
    }
};

