class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        //Traverse in num
        for(int i=0;i<num.size();i++){
            char digit = num[i];
            while(!st.empty() && k>0 && st.top()>digit){
                st.pop();
                k--;
            }
            st.push(digit);
        }
        //if k is still left st: 1 2 3 4 5 6
        while(!st.empty() && k>0){
            st.pop();
            k--;
        }
        //handling edge cases
        if(st.empty()) return "0";
        //pushing stack elements to res
        string res="";
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        //popping leading zeroes
        while(res.size()>0 && res.back()=='0'){
            res.pop_back();
        }
        //handling edge cases
        if(res.empty()) return "0";
        reverse(res.begin(),res.end()); //4321 -> 1234
        return res;
    }
};