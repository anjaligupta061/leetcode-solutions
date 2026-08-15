class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n = nums.size();
        set<int> st;
        for(int x : nums) {
            st.insert(x);
        }
        if(st.size() < 3) {
            return *prev(st.end());
        }
        while(st.size() > 3) {
            st.erase(st.begin());
        }
        return *st.begin();
    }
};