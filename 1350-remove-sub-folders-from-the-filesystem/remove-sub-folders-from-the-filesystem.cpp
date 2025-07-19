class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());  // Step 1: Sort the folder list
        vector<string> result;
        
        for (const string& f : folder) {
            // If result is empty or current folder is NOT a sub-folder of the last added
            if (result.empty() || f.find(result.back() + "/") != 0) {
                result.push_back(f);
            }
        }
        return result;
    }
};