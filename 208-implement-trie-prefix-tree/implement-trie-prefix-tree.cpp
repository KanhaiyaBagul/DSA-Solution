class Node{
    public:
    bool endOfWord;
    unordered_map<char , Node*> children;

    Node(){
        endOfWord = false;
    }
};

class Trie {
    Node* root;
public:
    Trie() {
        root = new Node();
        
    }
    
    void insert(string word) {
        Node* temp = root;
        //go through the each word
        for(char ch : word){
            
            if(temp -> children.count(ch) == 0){
                temp -> children[ch] = new Node();
            }
            temp = temp -> children[ch];
        }

       temp -> endOfWord = true;
    }
    
    bool search(string word) {
        Node* temp = root;

        for(char ch : word){
            //if we can't find the charcter return false
            if(temp -> children.count(ch) == 0) return false;

            temp = temp -> children[ch];
        }
        return temp -> endOfWord;
        
    }
    
    bool startsWith(string prefix) {
        Node* temp = root;

        for(char ch : prefix){
            if(temp -> children.count(ch) == 0){
                return false;
            }
            temp = temp -> children[ch];    
        }

        return true;
        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */