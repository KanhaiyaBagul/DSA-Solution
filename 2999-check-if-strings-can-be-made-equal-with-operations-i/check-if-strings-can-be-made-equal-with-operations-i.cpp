class Solution {
public:
    bool canBeEqual(string s1, string s2) {

        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                string temp = s1;
                if(i) swap(temp[0],temp[2]);
                if(j) swap(temp[1],temp[3]);

                if(temp == s2) return true;
            }
        }
        
         
        return false;
    }
};