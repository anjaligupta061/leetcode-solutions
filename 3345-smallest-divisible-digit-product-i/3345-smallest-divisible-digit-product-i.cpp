class Solution {
public:
    int digitprod(int a){
        int prod = 1;
        while(a>0){
            prod*=a%10;
            a/=10;
        }
        return prod;
    }
    int smallestNumber(int n, int t) {
        for(int i = n;i<=100;i++){
            if(digitprod(i)%t==0){
                return i;
            }
        }
        return -1;
    }
};