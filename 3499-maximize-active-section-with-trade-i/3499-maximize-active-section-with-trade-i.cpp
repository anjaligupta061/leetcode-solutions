class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        //calculating ones
        int ones = 0;
        for(char ch : s){
            if(ch=='1'){
                ones++;
            }
        }
        //augment
        string t = "1"+s+"1";
        vector<pair<char,int>> blocks;
        int i = 0;
        while(i<t.size()){
            int j = i;
            while(j<t.size() && t[j]==t[i]){
                j++;
            }
            blocks.push_back({t[i],j-i});
            i=j;
        }
        //calculating the best
        int best = 0;
        for(int i=1;i<blocks.size()-1;i++){
            if(blocks[i].first=='1' && blocks[i-1].first=='0' && blocks[i+1].first=='0'){
                best = max(best,blocks[i-1].second+blocks[i+1].second);
            }
        }
        return ones+best;
    }
};