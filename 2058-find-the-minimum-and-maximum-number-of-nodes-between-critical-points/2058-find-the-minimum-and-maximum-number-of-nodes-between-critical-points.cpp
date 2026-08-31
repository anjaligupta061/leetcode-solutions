
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int idx = 1;
        int fdx=-1;
        int sdx=-1;
        ListNode* a = head;
        ListNode* b = head->next;
        ListNode* c = head->next->next;
        if(c==NULL) return {-1,-1};
        int mind=INT_MAX;
        int f=-1;
        int s =-1;
        while(c){
            if(b->val > a->val && b->val > c->val || b->val < a->val && b->val < c->val){
                if(fdx==-1) fdx=idx; //maxd
                else sdx=idx;
                //mind
                f=s;
                s=idx;
                if(f!=-1){
                    int d = s-f;
                     mind=min(mind,d);
                }
            }
            a=a->next;
            b=b->next;
            c=c->next;
            idx++;
        }
        if(sdx==-1) return{-1,-1};
        int maxd = sdx-fdx;
        return {mind,maxd};
    }
};