package offer;

/**
 * @author zzf
 * @date 2020/10/16
 */
public class of22 {

    public class ListNode {
        int val;
        ListNode next;

        ListNode(int x) {
            val = x;
        }
    }

    public ListNode getKthFromEnd(ListNode head, int k) {
        ListNode a = head;
        ListNode b = head;
        for (int i = 0; i < k; ++i) {
            b = b.next;
        }
        while (b != null) {
            a = a.next;
            b = b.next;
        }
        return a;
    }
}
