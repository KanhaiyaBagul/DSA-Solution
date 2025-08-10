class Solution {
public:
    bool reorderedPowerOf2(int n) {
        if(n < 0) return false;
        string s = to_string(n);

        sort(s.begin() , s.end());//sort the given number

        for(int i = 0; i < 32; i++){
            long long p = 1LL << i;//this 1LL means it is 1 which is of the long long Data type
            string combo = to_string(p);
            sort(combo.begin() , combo.end());
            if(s == combo) return true;
        }

        return false;

        
    }
};