class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        int carry = 0;

        for(int i = 0; i < max(a.size(),b.size()); i++){
            
            int digit1 = (i < a.size()) ? a[i] - '0' : 0;
            int digit2 = (i < b.size() ? b[i] - '0' : 0);
            
            int total = digit1 + digit2 + carry;
            ans.push_back(char(total % 2 + '0'));

            carry = total /2;
   
         }
         if(carry != 0){
            ans.push_back('1');

         }
         reverse(ans.begin(),ans.end());

         return ans;
        
    }
};