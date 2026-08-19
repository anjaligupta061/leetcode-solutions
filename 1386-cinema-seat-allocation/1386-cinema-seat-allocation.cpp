class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& arr){
        unordered_map<int, set<int>> mpp;
        for(auto x : arr){
            mpp[x[0]].insert(x[1]);
        }

        int cnt = ((n-mpp.size())*2);
        for(auto &x : mpp){
            int row = x.first;
            set<int> &seats = x.second;
            bool left = true;
            bool right = true;
            bool middle = true;
            for(int i=2;i<=5;i++){
                if(seats.count(i)){
                    left = false;
                    break;
                }
            }
            for(int i=4;i<=7;i++){
                if(seats.count(i)){
                    middle = false;
                    break;
                }
            }
            for(int i=6;i<=9;i++){
                if(seats.count(i)){
                    right = false;
                    break;
                }
            }
            if(left && right) cnt+=2;
            else if(left || right || middle) cnt+=1;
        }
        return cnt;
    }
};