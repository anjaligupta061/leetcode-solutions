class Solution {
public:
    string smallestPalindrome(string s) {
        //frequency count
        vector<int> freq(26,0);
        for(char ch : s){
            freq[ch-'a']++;
        }
        string firsthalf = "";
        char middle = 0;
        //building first half and finding middle character
        for(int i=0;i<26;i++){
            firsthalf.append(freq[i]/2, 'a'+i);
            if(freq[i]%2==1) middle = 'a'+i;
        }
        //building answer
        string ans = firsthalf;
        if(middle) ans+=middle;
        reverse(firsthalf.begin(),firsthalf.end());
        ans+=firsthalf;
        return ans;
    }
};