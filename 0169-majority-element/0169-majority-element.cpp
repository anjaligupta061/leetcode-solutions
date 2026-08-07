class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int ele;
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(cnt==0){
                ele = nums[i];
                cnt = 1;
            }else if(ele==nums[i]){
                cnt++;
            }else cnt--;
        }
        int mini = (int)(n/2)+1;
        int cnt1= 0;
        for(int i=0;i<n;i++){
            if(ele==nums[i]) cnt1++;
        }
        if(cnt1>=mini) return ele;
        return -1;
    }
};