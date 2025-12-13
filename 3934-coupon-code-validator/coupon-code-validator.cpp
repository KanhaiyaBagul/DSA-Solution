class Solution {
public:
    //code validator
    bool isValid(string str){
        if(str.empty()) return false;
        for(char ch : str){
            if(!isalnum(ch)){
                if(ch == '_') continue;
                return false;
            }
        }
        return true;
    }
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {

        vector<pair<int, string>> ans;//store the ans
        //this store the valid businnessLine that should be present in vector busi.Line
        map<string, int> store = {
            {"electronics" ,  0},
            {"grocery" , 1},
            {"pharmacy" , 2},
            {"restaurant" ,  3}
            };

        for(int i = 0; i < code.size(); i++){
            if(isValid(code[i]) && isActive[i] && store.count(businessLine[i])){
                ans.push_back({store[businessLine[i]],code[i]});
            }
        }

        sort(ans.begin(),ans.end());
        vector<string> result;
        for(auto& p : ans){
            
            result.push_back(p.second);
        }
        return result;
        
    }
};