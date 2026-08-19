class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        vector<int> dp(target+1, -1);
        dp[0]=0;
        for(int num: nums){
            for(int j=target;j>=num;j--){
                if(dp[j-num]!=-1){
                    dp[j] = max(dp[j], 1+ dp[j-num]);
                }
            }
        }
        return dp[target];
    }
};