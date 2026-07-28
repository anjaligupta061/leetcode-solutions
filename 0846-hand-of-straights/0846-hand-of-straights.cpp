class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n%groupSize!=0) return false;
        map<int, int> freq;
        for(int x : hand){
            freq[x]++;
        }
        for(auto &it : freq){
            int start = it.first;
            int count = it.second;
            if(count==0) continue;
            for(int card = start; card < start+ groupSize; card++){
                if(freq[card]<count) return false;
                freq[card]-=count;
            }
        }
        return true;
    }
};