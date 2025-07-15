class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n,1);
        vector<int>prefixPro(n,1);
        vector<int>postfixPro(n,1);

        for(int i = 1; i < n; i++){
            prefixPro[i] = prefixPro[i - 1] * nums[i - 1];
            

        }

//         for(int i = n - 2; i >=0; i--)
// {
//     postfixPro[i] = postfixPro[i + 1] * nums[i + 1];
// }    
    int post = 1;    
      for(int i = n - 1; i > 0; i--){
        answer[i] = post * prefixPro[i];
        post *= nums[i];
      }

      answer[0] =  post;

    return answer;
    }
};