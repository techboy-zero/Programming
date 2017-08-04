import java.util.Scanner;
import java.math.BigInteger;

public class ReallyStrange {
	public static void main (String args []) {
			Scanner input = new Scanner (System.in);
			BigInteger n, res;
			BigInteger two = new BigInteger ("2");
			while (input.hasNext()) {
				n = input.nextBigInteger();
				res = n.multiply (n);
				res = res.subtract(n);
				res = res.add (BigInteger.ONE);
				res = res.add (BigInteger.ONE);
				
				if (n.compareTo (BigInteger.ZERO) == 0) {
					System.out.println ("1");
				} else {
					System.out.println (res);
				}
			}
	}
}