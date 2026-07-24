class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        // store deadends in a set for O(1) lookup
        unordered_set<string> dead(deadends.begin(), deadends.end());

        // if starting point itself is a deadend, we can never move
        if (dead.count("0000")) {
            return -1;
        }

        // BFS: each queue element is {current combination, number of moves taken}
        queue<pair<string, int>> q;
        q.push({"0000", 0});

        // track visited combinations so we don't repeat work
        unordered_set<string> visited;
        visited.insert("0000");

        while (!q.empty()) {
            auto [combo, moves] = q.front(); // structured binding, same as .first/.second
            q.pop();

            // found the target, this is the shortest path since it's BFS
            if (combo == target) {
                return moves;
            }

            // try turning each of the 4 wheels, one step forward or backward
            for (int i = 0; i < 4; i++) {
                for (int delta : {-1, 1}) {
                    // wrap around: 0 -> 9 when going down, 9 -> 0 when going up
                    int newDigit = (combo[i] - '0' + delta + 10) % 10;

                    string next = combo;       // copy current combination
                    next[i] = '0' + newDigit;  // change just this one wheel

                    // only move to it if it's not a deadend and we haven't been there
                    if (!dead.count(next) && !visited.count(next)) {
                        visited.insert(next);
                        q.push({next, moves + 1});
                    }
                }
            }
        }

        // exhausted all reachable combinations without hitting target
        return -1;
    }
};

//GAAND FAADUU CODEEEE!!!!!!!!
