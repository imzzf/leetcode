package leetcode;

/**
 * @author zzf
 * @date 2020/09/18
 */
public class lc160 {

    public class ListNode {
        int val;
        ListNode next;

        ListNode(int x) {
            val = x;
            next = null;
        }
    }


    /**
     * 双指针法
     *
     * @param headA
     * @param headB
     * @return
     */
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        ListNode a = headA;
        ListNode b = headB;
        //定义两个指针
        while (a != b) {
            if (a != null) {
                a = a.next;
            } else {
                //a走到尾部就转到b
                a = headB;
            }
            if (b != null) {
                b = b.next;
            } else {
                //b走到尾部就转到a
                b = headA;
            }
        }
        // 一定有一点是两个指针重合的

        // 当a和b不相交时，指针a经过了a+b，指针b经过了b+a，最终都到达尾部为空，相等跳出循环

        // 当a和b相交时，设最后共同的长度为k，指针a经过了a+(b-k)，指针b经过了b+(a-k)，
        // 必然会在通过同样长度后到达相交点，跳出循环
        return a;
    }

}
