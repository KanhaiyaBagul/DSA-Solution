class Solution {
public:
    int count = 0;
    string result = "";

    void solve(int n, int k, string current){
        if(current.size() == n){
            count ++;
            if(count == k){
                result = current;
            }
            return;
        }

        for(char ch : {'a','b','c'}){
            if(current.empty() || current.back() != ch){
                current = current + ch;
                solve(n,k,current);
                current.pop_back();
            }
        }
    }
    string getHappyString(int n, int k) {
        solve(n,k,"");
        return result;

        
    }
};