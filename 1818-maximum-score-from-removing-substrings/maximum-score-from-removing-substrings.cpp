class Solution {
public:
    int calculate(string &s, char a, char b, int val) {
        stack<char> st;
        int score = 0;

        for (char c : s) {
            if (!st.empty() && st.top() == a && c == b) {
                st.pop(); // remove the pair
                score += val;
            } else {
                st.push(c);
            }
        }

        // Reconstruct remaining string from stack
        s = "";
        while (!st.empty()) {
            s += st.top();
            st.pop();
        }
        reverse(s.begin(), s.end());
        return score;
    }

    int maximumGain(string s, int x, int y) {
        int totalScore = 0;

        if (x > y) {
            totalScore += calculate(s, 'a', 'b', x); // remove "ab" first
            totalScore += calculate(s, 'b', 'a', y); // then "ba"
        } else {
            totalScore += calculate(s, 'b', 'a', y); // remove "ba" first
            totalScore += calculate(s, 'a', 'b', x); // then "ab"
        }

        return totalScore;
    }
};
