import java.io.*;
import java.util.Scanner;
import java.math.*;

public class poj3181
{
    public static void main(String[] args)
    {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        int k = s.nextInt();
        BigInteger[] dp = new BigInteger[n + 1];
        dp[0] = BigInteger.ONE;
        for (int i = 1; i <= n; ++i)
            dp[i] = BigInteger.ZERO;
        for (int i = 1; i <= k; i += 1)
            for (int j = i; j <= n; j += 1)
                dp[j] = dp[j].add(dp[j - i]);
        System.out.println(dp[n]);
    }
}
