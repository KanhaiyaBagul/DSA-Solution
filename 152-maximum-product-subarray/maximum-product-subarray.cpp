class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int product = nums[0];
        int rightproduct = 1;
        int leftproduct = 1;

        for(int i = 0; i < n; i++){
          if(rightproduct == 0) rightproduct = 1;
          if(leftproduct == 0) leftproduct =1 ;

          rightproduct *= nums[i];
          leftproduct *= nums[n - i -1];

          product = max(product ,max(rightproduct,leftproduct));

        }
        return product;
        
    }
};