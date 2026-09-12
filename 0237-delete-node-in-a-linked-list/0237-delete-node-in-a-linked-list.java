/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public void deleteNode(ListNode target) {
        target.val = target.next.val;
        target.next = target.next.next;
        //copy the value next to the target then move the pointer to that next position
    }
}