class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> lastseen(3,-1);
        int cnt = 0;
        int n = s.length();
        for(int i=0;i<n;i++){
            //update the last seen
            lastseen[s[i]-'a']=i;
            // If all three characters ('a', 'b', 'c') have been seen at least once
            if(lastseen[0]!=-1 && lastseen[1]!=-1 && lastseen[2]!=-1){
                cnt+=(1+min({lastseen[0],lastseen[1],lastseen[2]}));
            }
        }
        return cnt;
    }
};