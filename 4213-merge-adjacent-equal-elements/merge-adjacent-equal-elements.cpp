class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        stack<long long> st;

        for(int &num : nums){
            long long curr = num;

            while(!st.empty() && st.top() == curr){
                curr += st.top();
                st.pop();
            }
            st.push(curr);
        }
        vector<long long> result;

        while(!st.empty()){
            result.push_back(st.top());
            st.pop();

        }

        reverse(result.begin(),result.end());
        return result;

    }
};