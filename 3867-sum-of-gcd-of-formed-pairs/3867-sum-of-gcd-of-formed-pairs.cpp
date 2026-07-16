class Solution {
public:
    int gcd(int a, int b) {
        while (b != 0) {
            int rem = a % b;
            a = b;
            b = rem;
        }
        return a;
    }
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixGcd(n);
        int mx = 0;
        for (int i = 0; i < n; i++) {
            mx = max(mx, nums[i]);
            prefixGcd[i] = gcd(mx, nums[i]);
        }
        sort(prefixGcd.begin(), prefixGcd.end());
        long long ans = 0;
        int i=0;
        int j=n-1;
        while(i<j){
            ans+=gcd(prefixGcd[i],prefixGcd[j]);
            i++;
            j--;
            if(i==j) break;
        }
        return ans;
    }
};