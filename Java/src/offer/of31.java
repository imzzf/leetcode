package offer;

import java.util.Stack;

/**
 * @author zzf
 * @date 2020/09/08
 */
public class of31 {
    public boolean validateStackSequences(int[] pushed, int[] popped) {
        Stack<Integer> stack = new Stack<>();
        int b = 0;
        for (int p : pushed) {
            stack.push(p);
            //依次入栈
            //如果栈顶有所需出栈的元素，则出栈
            while (!stack.empty() && popped[b] == stack.peek()) {
                stack.pop();
                ++b;
            }
        }
        return stack.empty();
    }
}
