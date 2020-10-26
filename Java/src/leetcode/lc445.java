package leetcode;

import java.util.Deque;
import java.util.LinkedList;

/**
 * @author zzf
 * @date 2020/10/18
 */
public class lc445 {

    public class ListNode {
        int val;
        ListNode next;

        ListNode(int x) {
            val = x;
        }
    }

    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        // 使用栈就可以在不反转链表的情况下进行加法计算
        Deque<Integer> a = new LinkedList<>();
        Deque<Integer> b = new LinkedList<>();
        while (l1 != null) {
            a.push(l1.val);
            l1 = l1.next;
        }
        while (l2 != null) {
            b.push(l2.val);
            l2 = l2.next;
        }
        ListNode ans = null;
        int carry = 0;
        while (!a.isEmpty() || !b.isEmpty()) {
            int p = a.isEmpty() ? 0 : a.pop();
            int q = b.isEmpty() ? 0 : b.pop();
            int x = p + q + carry;
            ListNode t = new ListNode(x % 10);
            carry = x / 10;
            t.next = ans;
            ans = t;
        }
        if (carry != 0) {
            ListNode t = new ListNode(carry);
            t.next = ans;
            ans = t;
        }
        return ans;
    }
}
