/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Compare{
public:
    bool operator()(ListNode* a, ListNode* b){
        return a->val > b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode* ,vector<ListNode*> , Compare> pq; //minheap

        //insert all heads into the heap
        for(int i=0;i<lists.size();i++){
            if(lists[i]!=NULL) pq.push(lists[i]);
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;
        //heap se smallest node nikalna
        while(!pq.empty()){
            ListNode* curr = pq.top();
            pq.pop();
            //add to the list
            tail->next = curr;
            tail = curr;
            // Agar next node hai to heap me daalo
            if (curr->next != NULL) {
                pq.push(curr->next);
            }
        }
        return dummy->next;
    }
};