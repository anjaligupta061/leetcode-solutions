class Solution {
public:
    string reverseVowels(string s) {
        int n = s.length();
        string ans;
        deque<char> dq;
        for(int i=0;i<n;i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' ||
            s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U'){
                dq.push_back(s[i]);
            }
        }
        reverse(dq.begin(),dq.end());
        for(int i=0;i<n;i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' ||
            s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U'){
                ans+=dq.front();
                dq.pop_front();
            }
            else ans+=s[i];
        }
        return ans;
    }
};