class Solution {
public:
    int sumByD(vector<int>& nums, int div){
        int sum = 0;

        for(int num : nums){
            sum+= ceil((double)num / div);
        }

        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();

        if(n > threshold) return -1;
        int low = 1;
        int ans = -1;
        int high = *max_element(nums.begin(), nums.end());

        while(low <= high){
            int mid = low + (high - low)/2;

            if(sumByD(nums, mid) <= threshold){
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