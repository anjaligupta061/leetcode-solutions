class Solution {
public:
    long long power(long long a, long long b, long long mod){
        int ans = 1;
        while(b>0){
            if(b%2==1){
                ans = (ans*a)%mod;
            }
            a = (a*a)%mod;
            b/=2;
        }
        return ans;
    }
    int countGoodNumbers(long long n) {
        long long MOD = 1000000007;
        long long even = (n+1)/2;
        long long odd = n/2;
        long long x = power(5,even,MOD);
        long long y = power(4,odd,MOD);
        return (x*y)%MOD;
    }
};