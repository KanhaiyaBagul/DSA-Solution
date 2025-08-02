class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> totalCount;
        map<int, int> count1, count2;
        int n = basket1.size();

        // Step 1: Count frequencies in both baskets and total
        for (int fruit : basket1) {
            count1[fruit]++;
            totalCount[fruit]++;
        }
        for (int fruit : basket2) {
            count2[fruit]++;
            totalCount[fruit]++;
        }

        // Step 2: Check if making baskets equal is possible
        for (auto& [fruit, freq] : totalCount) {
            if (freq % 2 != 0) {
                return -1; // Impossible if any fruit occurs odd number of times
            }
        }

        // Step 3: Find extra fruits in each basket
        //2 → 3 - 1 = +2  → extra in basket1 → add one 2 to extra1
        //1 → 0 - 2 = -2  → extra in basket2 → add one 1 to extra2
        vector<int> extra1, extra2;
        for (auto& [fruit, freq] : totalCount) {
            int diff = count1[fruit] - count2[fruit];
            if (diff > 0) {
                for (int i = 0; i < diff / 2; ++i)
                    extra1.push_back(fruit);
            } else if (diff < 0) {
                for (int i = 0; i < (-diff) / 2; ++i)
                    extra2.push_back(fruit);
            }
        }

        // Step 4: Sort extra fruits for greedy swap
        sort(extra1.begin(), extra1.end());                   // Ascending
        sort(extra2.begin(), extra2.end(), greater<int>());  // Descending

        // Step 5: Find the minimum fruit in all baskets (for 2-swap trick)
        int minFruit = min(*min_element(basket1.begin(), basket1.end()),
                           *min_element(basket2.begin(), basket2.end()));

        // Step 6: Calculate the total minimum cost
        long long totalCost = 0;
        for (int i = 0; i < extra1.size(); ++i) {
            int f1 = extra1[i];
            int f2 = extra2[i];
            totalCost += min(min(f1, f2), 2 * minFruit);
        }

        return totalCost;
    }
};
