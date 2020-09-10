package leetcode;

/**
 * @author zzf
 * @date 2020/09/09
 */
public class lc208 {

    class Trie {

        class TireNode {

            //当前结点是否为一个字符串的结束
            private boolean isEnd;

            //指向下一个可能字符的所有链接
            TireNode[] next;

            public TireNode() {
                isEnd = false;
                next = new TireNode[26];
            }
        }

        private TireNode root;

        public Trie() {
            root = new TireNode();
        }

        public void insert(String word) {
            TireNode node = root;
            //从root开始
            for (char c : word.toCharArray()) {
                //该字符是否在next中
                if (node.next[c - 'a'] == null) {
                    node.next[c - 'a'] = new TireNode();
                }
                node = node.next[c - 'a'];
            }
            //此时可以表示一个单词
            node.isEnd = true;
        }

        public boolean search(String word) {
            TireNode node = root;
            for (char c : word.toCharArray()) {
                node = node.next[c - 'a'];
                if (node == null) {
                    return false;
                }
            }
            return node.isEnd;
        }

        public boolean startsWith(String prefix) {
            TireNode node = root;
            for (char c : prefix.toCharArray()) {
                node = node.next[c - 'a'];
                if (node == null) {
                    return false;
                }
            }
            return true;
        }
    }
}
