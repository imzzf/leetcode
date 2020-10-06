package leetcode;

import java.util.LinkedList;
import java.util.Queue;

/**
 * @author zzf
 * @date 2020/09/18
 */
public class lc225 {

    //两个队列实现
    class MyStack {

        Queue<Integer> a;
        Queue<Integer> b;

        public MyStack() {
            a = new LinkedList<>();
            b = new LinkedList<>();
        }

        public void push(int x) {
            a.offer(x);
            while (!b.isEmpty()) {
                a.offer(b.poll());
            }
            Queue<Integer> t = a;
            a = b;
            b = t;
        }

        public int pop() {
            return b.poll();
        }

        public int top() {
            return b.peek();
        }

        public boolean empty() {
            return b.isEmpty();
        }
    }

    //一个队列实现
    class MyStack2 {

        Queue<Integer> q;

        public MyStack2() {
            q = new LinkedList<>();
        }

        public void push(int x) {
            int n = q.size();
            q.offer(x);
            for (int i = 0; i < n; ++i) {
                q.offer(q.poll());
            }
        }

        public int pop() {
            return q.poll();
        }

        public int top() {
            return q.peek();
        }

        public boolean empty() {
            return q.isEmpty();
        }
    }
}
