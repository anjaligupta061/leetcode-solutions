class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int, int> mp;
        for(int x : nums1){
            mp[x]++;
        }
        for(int x : nums2){
            if(mp.find(x)!=mp.end()){
                ans.push_back(x);
                mp[x]--;
                if(mp[x]==0) mp.erase(x);
            }
        }
        return ans;
    }
};