class Solution {
public:
    long long calculateTotalHours(vector<int>& piles, int speed){
        long long totalHours = 0;
        int n = piles.size();
        for(int i=0;i<n;i++){
            totalHours += ceil((double)piles[i]/speed);
        }
        return totalHours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = high;
        while(low<=high){
            int mid = low + (high - low)/2;
            long long res = calculateTotalHours(piles, mid);
            if(res <= h){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};