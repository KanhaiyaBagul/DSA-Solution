class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        int five = 0 , ten = 0;

        
        for(int i = 0; i < n; i++){
            int curr = bills[i];
            //if we have five
            if(curr == 5){
                five++;
            }else if(curr == 10){
                //if we have 10 present 
                if(five){
                    five--;//five reduce by 1
                    ten++;//increase by 1
                }else{
                    return false;
                }
               
            }else{
                if(five && ten){
                    five--;
                    ten--;
                }else if(five >= 3){
                    five = five - 3;
                }else{
                    return false;
                }
            }
        }
        return true;
        
    }
};