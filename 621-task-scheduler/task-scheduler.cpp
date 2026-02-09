class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        unordered_map<char,int> free;//store the next min seat number for the character
        unordered_map<char,int> freq;//store freq
        priority_queue<pair<int,char>> pq;
        //calculate the freq
        for(char ch : tasks){
            freq[ch]++;
            free[ch] = 1;
        }

        //insert freq in pq
        for(auto &p : freq){
            pq.push({p.second,p.first});
        }

        int seat = 1;// start with seat from 1

        while(!pq.empty()){
            //this vector is for storing the elemen in heap , in here we try to arrange all elements pq so insted of poping all the element we store in here
            vector<pair<int,char>> pulled;
            while(!pq.empty()){
                auto [freq, child] = pq.top();
                pq.pop();

                if(free[child] <= seat){//if the character is being place with in the seat then 
                    free[child] = seat + n + 1;//next min possible seat
                    if(freq > 1){//if it is not zero then  push back to the heap
                        pq.push({freq-1,child});
                    }
                    break;
                }else{
                    //if the top element is not placed in seat then pop it out and store it in the pulled vectro 
                    pulled.push_back({freq,child});
                }
            }
            //after all that put back the pop element 
            for(int i = 0; i < pulled.size(); i++){
                pq.push(pulled[i]);
            }

            seat++;//increment the seat

        }
        return seat - 1;


        
    }
};