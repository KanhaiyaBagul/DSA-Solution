class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        using P  = pair<int,pair<int,int>>;
        priority_queue<P> pq;
        vector<vector<int>> result;

        int n = nums1.size();
        int m = nums2.size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int a = nums1[i];
                int b = nums2[j];
                int sum = a + b;
               
                if(pq.size() < k){//if element is less than k 
                    pq.push({sum,{a,b}}); 
                }else if(!pq.empty() && pq.top().first > (a + b)){//if we found the new sum and it is less than the top element then pop the top and inser the curr sum with  a and b
                    pq.pop();
                    pq.push({sum,{a,b}});
                }else{//after that we get the greater element , no need of that , we can't find any less sum 
                    break;
                }
            }
        }

        while(!pq.empty()){

            auto e = pq.top().second;
            pq.pop();
            result.push_back({e.first,e.second});
        }
        
        return result;



        
    }
};