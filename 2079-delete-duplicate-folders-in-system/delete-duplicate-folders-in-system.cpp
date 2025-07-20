class Solution {
public:
    struct TrieNode {
        string name;
        unordered_map<string, TrieNode*> children;
        string serial;  // serialized subtree
        bool toDelete = false;
    };

    TrieNode* root;
    unordered_map<string, vector<TrieNode*>> duplicates;

    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        root = new TrieNode();

        // Step 1: Build Tree
        for (auto& path : paths) {
            TrieNode* cur = root;
            for (auto& folder : path) {
                if (!cur->children.count(folder)) {
                    cur->children[folder] = new TrieNode();
                    cur->children[folder]->name = folder;
                }
                cur = cur->children[folder];
            }
        }

        // Step 2: Serialize subtrees
        serialize(root);

        // Step 3: Mark duplicates
        for (auto& [_, nodes] : duplicates) {
            if (nodes.size() > 1) {
                for (auto node : nodes) {
                    node->toDelete = true;
                }
            }
        }

        // Step 4: DFS to collect valid paths
        vector<vector<string>> result;
        vector<string> current;
        collect(root, current, result);
        return result;
    }

    string serialize(TrieNode* node) {
        if (node->children.empty()) return "";

        vector<pair<string, string>> serializedChildren;
        for (auto& [name, child] : node->children) {
            string sub = serialize(child);
            serializedChildren.push_back({name, sub});
        }

        // Sort to ensure uniqueness regardless of insertion order
        sort(serializedChildren.begin(), serializedChildren.end());

        string serial;
        for (auto& [name, sub] : serializedChildren) {
            serial += "(" + name + sub + ")";
        }

        node->serial = serial;
        duplicates[serial].push_back(node);
        return serial;
    }

    void collect(TrieNode* node, vector<string>& path, vector<vector<string>>& result) {
        for (auto& [name, child] : node->children) {
            if (child->toDelete) continue;
            path.push_back(name);
            result.push_back(path);
            collect(child, path, result);
            path.pop_back();
        }
    }
};
