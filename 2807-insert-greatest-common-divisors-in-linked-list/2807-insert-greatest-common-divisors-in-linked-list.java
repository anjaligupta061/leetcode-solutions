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
    public int gcd(int a, int b){
        while(b!=0){
            int rem = a%b;
            a=b;
            b=rem;
        }
        return a;
    }
    public ListNode insertGreatestCommonDivisors(ListNode head) {
        if(head == null || head.next == null) return head;
        ListNode temp = head;
        while(temp.next != null){
            int a = temp.val;
            int b = temp.next.val;
            int res = gcd(a, b);
            ListNode nextNode = temp.next;
            ListNode node = new ListNode(res);
            temp.next = node;
            node.next = nextNode;
            temp = nextNode;
        }

        return head;
    }
}