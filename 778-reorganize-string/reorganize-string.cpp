class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> freq;//store the the feq of the element in the string
        //this is for the Heap Implemtation 
        using P = pair<int,char>;
        priority_queue<P> pq;
        //store the freq
        for(char &ch : s){
            freq[ch]++;
        }
        //if one element is present in the whole string , so theire is no chance we can arrange it the desire way
        if(freq.size() < 1){
            return "";
        }

        //this is for finding the right pattern
        for(auto& p : freq){
            pq.push({p.second,p.first});
        }

        string res = "";

        while(!pq.empty()){
            //first get the first element 
            auto p = pq.top();
            pq.pop();
            //if it is the first element 
            if(res.size() == 0 || p.second != res.back()){
                res.push_back(p.second);
                p.first--;
                if(p.first > 0){
                    pq.push(p);
                }
            }else{
                //if the element end of the res and the top element are equal then get the second elemnt and then perform the operation 
                if(pq.empty()) return "";
                auto sec = pq.top();
                pq.pop();

                res.push_back(sec.second);
                sec.first--;
                if(sec.first > 0){
                    pq.push(sec);
                }

                pq.push(p);//in finnaly we push the first element

            }
        }
        return res;
    }
};