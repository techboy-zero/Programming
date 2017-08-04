import java.util.Scanner;
import java.math.BigInteger;

public class WhoSaidCrisis {
	public static void main (String args []) {
			Scanner input = new Scanner (System.in);
			BigInteger a;
			BigInteger b;
			int t;
			t = input.nextInt ();
			while (--t >= 0) {
				a = input.nextBigInteger ();
				b = input.nextBigInteger ();
				System.out.println ((a.subtract (b)));
			}
	}
}