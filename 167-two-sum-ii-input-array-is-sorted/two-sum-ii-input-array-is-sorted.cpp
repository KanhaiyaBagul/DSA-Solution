class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        vector<int> result;
        int start = 0;
        int end = n - 1;
        while(start < end){
            int sum = numbers[start] + numbers[end];
            if(sum == target){
                result.push_back(start + 1);
                result.push_back(end + 1);
                break;
                return result;
            }else if(sum < target){
                start++;
            }else{
                end--;
            }

        }
        return result;
        
    }
};