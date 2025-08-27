class Solution {
public:
    bool checkValidString(string s) {
        // Edge case: if the string starts with ')' it can never be valid
        if (s[0] == ')') return false;

        // `min` = minimum possible number of open '(' brackets
        // `max` = maximum possible number of open '(' brackets
        int min = 0, max = 0;

        // Traverse the string character by character
        for (int i = 0; i < s.size(); i++) {

            if (s[i] == '(') {
                // '(' always increases both min and max (one more open bracket)
                min++;
                max++;
            } 
            else if (s[i] == ')') {
                // ')' always decreases both min and max (closes one open bracket)
                min--;
                max--;
            } 
            else { // s[i] == '*'
                // '*' can act as:
                // - ')' → min decreases
                // - '(' → max increases
                // - empty → no effect (covered by keeping min and max as a range)
                min--;
                max++;
            }

            // min can't go below 0 because we can't have negative open brackets
            if (min < 0) min = 0;

            // If max < 0, it means we had more ')' than '(' possible
            // -> invalid sequence
            if (max < 0) return false;
        }

        // At the end, if min == 0, there exists a valid configuration
        // of '*' replacements that makes the string balanced
        return (min == 0);
    }
};
