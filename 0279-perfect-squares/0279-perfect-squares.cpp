class Solution {
public:
    bool isPerfect(int n){
        int root = sqrt(n);
        return root*root == n;
    }
    int numSquares(int n) {
        vector<int> dp(n+1, 0);
        for(int i=1;i<=n;i++){
            if(isPerfect(i)) {
                dp[i] = 1;
            }else{
                int mn = INT_MAX;
                for(int j = 1; j <= i / 2; j++) {
                    int count = dp[j] + dp[i - j];
                    mn = min(mn, count);
                }
                dp[i]=mn;
            }
        }
        return dp[n];
    }
};

//RECURSION
// class Solution {
// public:
//     bool isPerfect(int n) {
//         int root = sqrt(n);
//         return root * root == n;
//     }
//     int minSquares(int n) {
//         if(isPerfect(n))
//             return 1;
//         int mn = INT_MAX;
//         for(int i = 1; i <= n / 2; i++) {
//             int count = minSquares(i) + minSquares(n - i);
//             mn = min(mn, count);
//         }
//         return mn;
//     }
//     int numSquares(int n) {
//         return minSquares(n);
//     }
// };

//RECURSION + MEMORISATION

// class Solution {
// public:
//     bool isPerfect(int n) {
//         int root = sqrt(n);
//         return root * root == n;
//     }
//     int minSquares(int n, vector<int>& dp) {
//         if(isPerfect(n))
//             return 1;
//         if(dp[n] != -1)
//             return dp[n];
//         int mn = INT_MAX;
//         for(int i = 1; i <= n / 2; i++) {
//             int count = minSquares(i, dp)
//                       + minSquares(n - i, dp);
//             mn = min(mn, count);
//         }
//         return dp[n] = mn;
//     }
//     int numSquares(int n) {
//         vector<int> dp(n + 1, -1);
//         return minSquares(n, dp);
//     }
// };