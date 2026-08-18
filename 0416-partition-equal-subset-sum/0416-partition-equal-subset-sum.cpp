class Solution {
public:
    bool subset(int i, vector<int> &nums, int target, vector<vector<int>>& dp){
        if(target==0) return true;
        if(i==nums.size() || target < 0) return false;
        if(dp[i][target]!=-1) return dp[i][target] == 1;
        bool skip = subset(i+1, nums, target, dp);
        bool pick = subset(i+1, nums, target-nums[i],dp);
        bool result = skip || pick;
        dp[i][target] = result? 1:0;
        return result;
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int ele: nums) sum+=ele;
        if(sum%2!=0) return false;
        int target = sum/2;
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        return subset(0,nums,target,dp);
    }
};