class Solution {
public:

    void valid(int startIdx, string s, string current,vector<string>& result,int dotCount){
    
        if(startIdx == s .size() && dotCount == 4){ //This is the base condition when we reach the last index and also we have the 4 dots 
            current.pop_back(); //this is to use becaues out FINAL Sol is like "255.255.11.135." to remove the extra do we use the pop fun
            result.push_back(current); // add the possible output to reslut
            return;
        }
        if(dotCount >= 4){// suppose we use more than 4 dots it is not a valid solution so we terminalte the call
            return; 
        }
        
        for(int i = startIdx; i < min(startIdx + 3,(int)s.size()); i++){ // we use for loop for we have to divide the id to total  4 parts ,It is use to divide int 4 parts
            
            string part = s.substr(startIdx,i - startIdx + 1); //We seperate the specific part to check the conditiion

            if(part.size() > 1 && part[0] == '0') continue; /// if out part have any leading ZERO , not a valid sol
            
            if( stoi(part) < 256 ){ // check for part is less than 256
                
                valid(i + 1,s,current + part + '.'  ,result , dotCount + 1); //recuresive call for next possible combinations
                

            }   
        }
    }
    vector<string> restoreIpAddresses(string s) {

        vector<string> result;
        string current = "";//Initialize the current output
        int startIdx = 0;//initilaize the starting index
        int dotCount  = 0;// Initialize the dot count , count the number of dots we have place 
        
    
        valid(startIdx,s,current,result, dotCount);//Call the fun
        return result;//Print the result
        
    }
};