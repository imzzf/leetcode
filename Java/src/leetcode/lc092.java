package leetcode;

/**
 * @author zzf
 * @date 2020/10/17
 */
public class lc092 {

    public class ListNode {
        int val;
        ListNode next;

        ListNode(int x) {
            val = x;
        }
    }

    public ListNode reverseBetween(ListNode head, int m, int n) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode pre = dummy;
        ListNode cur = head;
        for (int i = 0; i < m - 1; ++i) {
            pre = pre.next;
        }
        cur = pre.next;
        ListNode next = cur.next;
        for (int i = 0; i < n - m; ++i) {
            cur.next = next.next;
            next.next = pre.next;
            pre.next = next;
            next = cur.next;
        }
        return dummy.next;
    }
}
