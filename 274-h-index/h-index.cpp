//the question explanation is frame confusing use chat gpt for the explanation
class Solution {
public:
    int hIndex(vector<int>& citations) {
        
        int n = citations.size(); // total paper publish

        sort(citations.begin(), citations.end());
        int maxValue = INT_MIN;

        for (int i = 1; i <= n; i++) {
            int k = 0;
            int j = n - 1;

            while (k <= j) {
                int mid = k + (j - k) / 2;

                if (citations[mid] >= i) {
                    j = mid - 1;
                } else {
                    k = mid + 1;
                }
            }

            if (n - k >= i) {//here we have to return the max value of the h who satisfy the conditon of the numbers
                maxValue = i;
            }
        }
        return maxValue == INT_MIN ? 0 : maxValue;
    }
};