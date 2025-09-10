class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = languages.size();
        
        // Convert to sets for quick lookup
        vector<unordered_set<int>> langSet(m+1);
        for (int i = 0; i < m; i++) {
            for (int lang : languages[i]) {
                langSet[i+1].insert(lang);
            }
        }
        
        // Step 1: Find problematic users
        unordered_set<int> problematic;
        for (auto &f : friendships) {
            int u = f[0], v = f[1];
            bool canCommunicate = false;
            for (int lang : langSet[u]) {
                if (langSet[v].count(lang)) {
                    canCommunicate = true;
                    break;
                }
            }
            if (!canCommunicate) {
                problematic.insert(u);
                problematic.insert(v);
            }
        }
        
        // If no problematic friendships, return 0
        if (problematic.empty()) return 0;

        // Step 2: For each language, count coverage among problematic users
        int res = INT_MAX;
        for (int lang = 1; lang <= n; lang++) {
            int count = 0;
            for (int user : problematic) {
                if (langSet[user].count(lang)) {
                    count++;
                }
            }
            res = min(res, (int)problematic.size() - count);
        }
        
        return res;
    }
};
