class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> ans(num_people, 0);
        int give = 1;
        int i = 0;
        while (candies > 0) {
            int curr = min(give, candies);
            ans[i % num_people] += curr;
            candies -= curr;
            give++;
            i++;
        }
        return ans;
    }
};