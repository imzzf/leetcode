package leetcode;

/**
 * @author zzf
 * @date 2020/10/18
 */
public class lc019 {

    public class ListNode {
        int val;
        ListNode next;

        ListNode() {
        }

        ListNode(int val) {
            this.val = val;
        }

        ListNode(int val, ListNode next) {
            this.val = val;
            this.next = next;
        }
    }

    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode dummy = new ListNode(0, head);
        ListNode a = head;
        for (int i = 0; i < n; ++i) {
            a = a.next;
        }
        ListNode b = dummy;
        while (a != null) {
            a = a.next;
            b = b.next;
        }
        b.next = b.next.next;
        return dummy.next;
    }
}
