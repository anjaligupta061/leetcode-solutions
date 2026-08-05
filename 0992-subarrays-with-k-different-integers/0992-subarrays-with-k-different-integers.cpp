class Solution {
public:
    int atmost(vector<int>& nums, int k){
        int left = 0;
        int count = 0;
        unordered_map<int, int> mpp;
        for(int right = 0; right < nums.size(); right++){
            if(mpp[nums[right]]==0) k--;
            mpp[nums[right]]++;
            while(k<0){
                mpp[nums[left]]--;
                if(mpp[nums[left]]==0) k++;
                left++;
            }
            count +=  right-left+1;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums, k)-atmost(nums,k-1);
    }
};