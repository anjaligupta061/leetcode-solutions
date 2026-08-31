class Solution {
public:
    bool check(int mid, vector<int>& weights, int days){
        int count = 1;
        int m = mid;
        int n = weights.size();

        for(int i=0;i<n;i++){
            if(m >= weights[i]){
                m-= weights[i];
            }
            else{
                count++;
                m = mid;
                m-= weights[i];
            }
        }

        return count<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        // Your code goes here

        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        int minCapacity = high;

        while(low <= high){
            int mid = low + (high - low)/2;

            if(check(mid, weights, days)){
                minCapacity = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return minCapacity;
    }
};