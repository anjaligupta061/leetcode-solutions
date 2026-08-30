class Solution {
public:
    bool possible(vector<int>& arr, int days, int m, int k){
        int n = arr.size();
        int cnt = 0;
        int bouquets = 0;
        for(int i=0;i<n;i++){
            if(arr[i] <= days){
                cnt++;

                if(cnt==k){
                    bouquets++;
                    cnt = 0;
                }
            }
            else{
                cnt = 0;
            }
        }
        return bouquets >= m;
    }
    int minDays(vector<int>& arr, int m, int k) {
        int n = arr.size();
        int total = 1LL*m*k;

        if(total > n) return -1;

        int mn = *min_element(arr.begin(),arr.end());
        int mx = *max_element(arr.begin(), arr.end());

        int low = mn;
        int high = mx;
        int ans = -1;

        while(low <= high){
            int mid = low + (high - low)/2;
            if(possible(arr, mid, m, k)){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};