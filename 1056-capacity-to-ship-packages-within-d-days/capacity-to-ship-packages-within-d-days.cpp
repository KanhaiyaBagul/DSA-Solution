class Solution {
public:
    //this calculate the days for our mid value , the minumum weights
    int calcDays(vector<int>& weights,int mid){
        int currDays = 1;
        int currWeight = 0;
        for(int i = 0; i < weights.size(); i++){

            if(currWeight + weights[i] <= mid){
                currWeight += weights[i];
            }else{
                currDays ++;
                currWeight = weights[i];
            }

        }
        return currDays;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();

        int low = *max_element(weights.begin(),weights.end());//lower value W.R.T the question is the largest value in the weigts
        int high = accumulate(weights.begin(),weights.end(),0);//max Value is the sum of the whole array

        while(low <= high){
            int mid = low + (high - low) / 2;

            int totalDays = calcDays(weights,mid);//this calculate the days for our mid value 

            if(totalDays > days){//if the total days are greater than the actual ones the time taken is less , so for increasing the time we increase the limits of it
                low = mid + 1;
            }else{//reverse for this condition 
                high = mid - 1;
            }
        }
        return low;
        
        
    }
};