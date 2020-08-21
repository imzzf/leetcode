package leetcode;

/**
 * @author zzf
 * @date 2020/08/19
 */
public class lc061 {

    public static class ListNode {
        int val;
        ListNode next;

        ListNode(int x) {
            val = x;
        }
    }


    public ListNode rotateRight(ListNode head, int k) {
        if (head == null) {
            return null;
        }
        if (head.next == null) {
            return head;
        }

        //先找到链表尾部
        ListNode tail = head;
        int len = 1;
        for (; tail.next != null; tail = tail.next) {
            ++len;
        }
        tail.next = head;
        k %= len;

        ListNode newtail = head;
        for (int i = 1; i <= len - k - 1; ++i) {
            newtail = newtail.next;
        }
        ListNode newhead = newtail.next;
        newtail.next = null;
        return newhead;
    }
}
