package offer;

/**
 * @author zzf
 * @date 2020/08/08
 */
public class of24 {

    public static class ListNode {
        int val;
        ListNode next;

        ListNode(int x) {
            val = x;
        }
    }

    public static class Solution {
        /**
         * prev/curr/next分别记录前序/当前/后序结点
         * 在改变curr->next时单链表会断，必须先记录下curr->next
         */
        public ListNode reverseList(ListNode head) {
            ListNode prev = null;
            ListNode curr = head;
            ListNode next;
            while (curr != null) {
                next = curr.next;
                curr.next = prev;
                prev = curr;
                curr = next;
            }
            return prev;
        }
    }
}
