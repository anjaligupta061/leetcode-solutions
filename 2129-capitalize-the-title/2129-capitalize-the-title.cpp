class Solution {
public:
    string capitalizeTitle(string title) {
        int n = title.size();
        for(int i = 0;i<n;i++){
            if(title[i]!=' '){
                int start = i;
                while(i<n && title[i]!=' '){
                    i++;
                }
                int len = i - start;
                if(len<=2){
                    for(int j = start;j<i;j++){
                        title[j] = tolower(title[j]);
                    }
                }
                else{
                    title[start] = toupper(title[start]);
                    for(int k = start+1;k<i;k++){
                        title[k] = tolower(title[k]);
                    }
                }
            }
        }
        return title;
    }
};