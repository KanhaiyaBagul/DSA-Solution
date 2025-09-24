class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string ans = "";
        if(numerator == 0){
            return "0";
        }

        if((long long)numerator * (long long)denominator < 0){//if any of is negative
            ans = ans + "-";
        }
        
        long long num = labs(numerator);
        long long den = labs(denominator);

        long long q = num / den;//calculate questiont
        long long r = num % den;//calculate remainder
        ans = ans + to_string(q);//inser the questiont

        if(r == 0){//if completely divided then return ans 
            return ans;
        }

        ans += ".";
        unordered_map<long long, int> mp;//this is use to store the remainder and use to inset the "("
        while(r != 0){
            if(mp.count(r)){//if any remainder is repeat then find the index where it occure first and add the "(" and also for the last ")"
                ans.insert(mp[r],"(");
                ans += ")";
                break;
            }
            mp[r] = ans.size();

            r *= 10;
            int digit = r / den;
           
            ans += to_string(digit);
            r = r % den;
            
        }

        return ans;
        
    }
};