import java.util.Scanner;
import java.math.BigInteger;

public class Krakovia {
	public static void main (String args []) {
			Scanner input = new Scanner (System.in);
			int n;
			int f;
			int kase = 0;
			BigInteger m;
			BigInteger tot;
			
			while (input.hasNext()) {
				n = input.nextInt ();
				f = input.nextInt ();
				if (n == 0 && f == 0) break;
				tot = BigInteger.ZERO;
				for (int i = 1; i <= n; i++) {
					m = input.nextBigInteger ();
					tot = tot.add (m);
				}
				
				System.out.println ("Bill #" + (++kase) + " costs " + tot + ": each friend should pay " + (tot.divide (BigInteger.valueOf (f))));
				System.out.println ();
			}
	}
}