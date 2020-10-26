package leetcode;

import java.util.PriorityQueue;
import java.util.Queue;

/**
 * @author zzf
 * @date 2020/10/23
 */
public class lc023 {

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

    public ListNode mergeKLists(ListNode[] lists) {
        if (lists.length == 0) {
            return null;
        }
        return helper(lists, 0, lists.length - 1);
    }

    public ListNode helper(ListNode[] lists, int l, int r) {
        if (l == r) {
            return lists[l];
        }
        int mid = l + ((r - l) >> 1);
        return merge(helper(lists, l, mid), helper(lists, mid + 1, r));
    }

    public ListNode merge(ListNode a, ListNode b) {
        ListNode dummy = new ListNode(0);
        ListNode pre = dummy;
        while (a != null && b != null) {
            if (a.val < b.val) {
                pre.next = a;
                a = a.next;
            } else {
                pre.next = b;
                b = b.next;
            }
            pre = pre.next;
        }
        pre.next = a == null ? b : a;
        return dummy.next;
    }


    ///////////////////////
    public ListNode mergeKLists2(ListNode[] lists) {
        if (lists.length == 0) {
            return null;
        }
        Queue<ListNode> q = new PriorityQueue<>((a, b) -> {
            return a.val - b.val;
        });
        for (ListNode list : lists) {
            if (list != null) {
                q.offer(list);
            }
        }
        ListNode dummy = new ListNode(0);
        ListNode pre = dummy;
        while (!q.isEmpty()) {
            ListNode t = q.poll();
            pre.next = t;
            if (t.next != null) {
                q.offer(t.next);
            }
            pre = pre.next;
        }
        return dummy.next;
    }

}
