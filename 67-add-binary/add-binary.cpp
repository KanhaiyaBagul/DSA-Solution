class Solution {
public:
    string addBinary(string a, string b) {

        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        string ans = "";
        int carry = 0;

        for(int i = 0; i < max(a.size(),b.size()); i++){
            int first = (i < a.size() ? a[i] - '0' : 0);
            int second = (i < b.size() ? b[i] - '0' : 0);

            int total = first + second + carry;


            ans.push_back((total % 2) + '0' );

            carry = total / 2;

        }

        if(carry != 0){
            ans.push_back('1');
        }

        reverse(ans.begin(),ans.end());
        return ans;


        
        
    }
};