class Solution {
public:
    void recursion(int n, int left,int right,string str,vector<string>&result){
        if(left == n && right == n){
            result.push_back(str);
            return;
        }

        if(left < n){
            recursion(n,left+1,right, str + '(',result);
        }

        if(right < left){
            recursion(n,left,right+1, str + ')',result);
        }

    }
    vector<string> generateParenthesis(int n) {
        int left = 0;
        int right = 0;
        vector<string> result;

        recursion(n,left, right,"",result);

        return result;
        
    }
};