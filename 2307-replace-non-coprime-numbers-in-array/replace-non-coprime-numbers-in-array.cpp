class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<long long> st; // use long long to avoid overflow
        for (long long num : nums) {
            st.push_back(num);
            // keep merging while top two are non-coprime
            while (st.size() > 1) {
                long long a = st.back(); st.pop_back();
                long long b = st.back(); st.pop_back();
                long long g = gcd(a, b);
                if (g == 1) { 
                    st.push_back(b);
                    st.push_back(a);
                    break;
                }
                long long l = (a / g) * b; // compute LCM safely
                st.push_back(l);
            }
        }
        // convert back to int (guaranteed <= 1e8 per constraints)
        vector<int> ans;
        for (auto x : st) ans.push_back((int)x);
        return ans;
    }
};
