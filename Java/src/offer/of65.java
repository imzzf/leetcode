package offer;

/**
 * @author zzf
 * @date 2020/09/09
 */
public class of65 {

    public int add(int a, int b) {
        int sum, carry;
        while (b != 0) {
            sum = a ^ b;
            carry = (a & b) << 1;
            a = sum;
            b = carry;
        }
        return a;
    }
}
