class Solution {
public:

    void combination(vector<int>&candidates , int target,int start , int sum,vector<int> &temp,vector<vector<int>>& result){
        if(sum == target){
            result.push_back(temp); // this final case it gives the solution
            return;
        }

        if(sum > target){
            return;//This  base case is use to not run unnecessaraly if sum > tartet it is use less to us
        }

        for(int i = start; i < candidates.size(); i++){
            
            temp.push_back(candidates[i]);//It keep track of which element is selected
            combination(candidates,target,i,sum + candidates[i],temp,result);//Recuresive call with what we have been computed til now
            
            temp.pop_back(); // after find the possible value it is use to backtrack other values
        }

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> result;
        int sum = 0;
        combination(candidates, target , 0 , sum, temp, result);  // Start form 0
        return result;
        
    }
};