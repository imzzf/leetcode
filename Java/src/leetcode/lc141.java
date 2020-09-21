package leetcode;

/**
 * @author zzf
 * @date 2020/08/31
 */
public class lc141 {

    class ListNode {
        int val;
        ListNode next;

        ListNode(int x) {
            val = x;
            next = null;
        }
    }

    /**
     * 快慢指针
     * 存在环的时候，且当两个指针都进入环时，以慢指针为参照，
     * 快指针绕一圈后必将与慢指针重合
     * 不存在环时，快指针会先到达链表尾部，指向null
     *
     * @param head
     * @return
     */
    public boolean hasCycle(ListNode head) {
        if (head == null || head.next == null) {
            return false;
        }
        ListNode slow = head;
        ListNode fast = head.next;
        while (slow != fast) {
            if (fast == null || fast.next == null) {
                return false;
            }
            slow = slow.next;
            fast = fast.next.next;
        }
        return true;
    }
}
