class Solution {
public:
    // int solve(vector<int>& nums, int i , vector<int>& dp){
    //     if(i>=nums.size()) return 0; //base case
    //     if(dp[i]!=-1) return dp[i];
    //     // Take current house
    //     int take = nums[i] + solve(nums, i + 2, dp);
    //     // Skip current house
    //     int skip = solve(nums, i + 1, dp);
    //     // Store answer
    //     dp[i] = max(take, skip);
    //     return dp[i];
    // }
    int rob(vector<int>& nums) {
        int n = nums.size();
        // vector<int> dp(n,-1);
        // return solve(nums, 0 , dp);
        if(n==0) return 0;
        if(n==1) return nums[0];
        vector<int> dp(n);
        dp[0]=nums[0];
        dp[1] = max(nums[0],nums[1]);
        for (int i = 2; i < n; i++) {
            // Take current house
            int take = nums[i] + dp[i - 2];
            // Skip current house
            int skip = dp[i - 1];
            dp[i] = max(take, skip);
        }
        return dp[n - 1];
    }
};