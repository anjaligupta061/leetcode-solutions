class Solution {
public:
    long long coincount(int i, vector<int>& coins, int amount, vector<vector<long long>>& dp){
        if(i==coins.size()){
            if(amount==0) return 0;
            else return INT_MAX;
        }
        if(dp[i][amount]!=-1) return dp[i][amount];
        long long skip = coincount(i+1,coins,amount,dp);
        if(amount-coins[i]<0) return dp[i][amount]=skip;
        long long pick = 1 + coincount(i,coins,amount-coins[i],dp);
        return dp[i][amount] = min(skip,pick);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<long long>> dp(n, vector<long long>(amount+1, -1));
        long long ans = coincount(0,coins,amount, dp);
        if(ans>=INT_MAX) return -1;
        return(int) ans;
    }
};