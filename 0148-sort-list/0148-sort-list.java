/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode findMiddle(ListNode head) {
        if(head==null || head.next==null) return head;
        ListNode slow = head;
        ListNode fast = head.next;

        while(fast!=null && fast.next!=null){
            slow = slow.next;
            fast = fast.next.next;
        }

        return slow;
    }

    public ListNode mergeTwoSortedLinkedLists(ListNode l1, ListNode l2){
        ListNode dummyNode = new ListNode(-1);
        ListNode temp = dummyNode;

        while(l1 != null && l2 != null){
            if(l1.val <= l2.val){
                temp.next = l1;
                l1 = l1.next;
            }
            else{
                temp.next = l2;
                l2 = l2.next;
            }
            temp = temp.next;
        }

        if(l1 != null) temp.next = l1;
        else temp.next = l2;

        return dummyNode.next;
    }
    public ListNode sortList(ListNode head) {
        if(head == null || head.next == null) return head;

        //Find middle
        ListNode middle = findMiddle(head);

        //Right half
        ListNode right = middle.next;

        //Break the list
        middle.next = null;

        //Left half
        ListNode left = head;

        // Recursively sort both halves
        left = sortList(left);
        right = sortList(right);

        return mergeTwoSortedLinkedLists(left, right);
    }
}