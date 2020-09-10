package offer;

import java.util.Deque;
import java.util.LinkedList;

/**
 * @author zzf
 * @date 2020/09/08
 */
public class of09 {

    /**
     * 两个栈a和b
     * 入队列时加入a栈即可
     * 由于队列先进先出，b为空时将a中的元素依次出栈入b，此时b出栈的顺序即是队列的出队顺序
     * 而b不为空时，b的顶部即是队列头部，a的顶部即是队列尾部
     * 需要出队列时只需将b依次出栈
     */
    class CQueue {

        //不推荐用Stack类
        Deque<Integer> a;

        Deque<Integer> b;

        public CQueue() {
            a = new LinkedList<>();
            b = new LinkedList<>();
        }

        public void appendTail(int value) {
            a.push(value);
        }

        public int deleteHead() {
            if (b.isEmpty()) {
                if (a.isEmpty()) {
                    return -1;
                }
                while (!a.isEmpty()) {
                    b.push(a.pop());
                }
            }
            return b.pop();
        }
    }


}
