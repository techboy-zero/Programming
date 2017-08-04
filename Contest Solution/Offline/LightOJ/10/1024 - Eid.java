import java.util.Scanner;
import java.math.BigInteger;
import static java.lang.System.*;

public class Main
{
    static boolean status[]=new boolean[10001];
    static int  primes[]=new int[4100],counter[]=new int[4100],indx;

    static void sieve()
    {
        primes[indx++]=2;

        for (int i=3; i<10001; i+=2)
        {
            if (status[i]!=false)   continue;

            primes[indx++]=i;

            for (int j=i*i; j<10001; j+=2*i)
                status[j]=true;
        }
    }

    public static void main(String args[])
    {
        sieve();

        Scanner input=new Scanner(System.in);

        int t=input.nextInt();

        for (int i=1; i<=t; i++)
        {
            int n=input.nextInt();
            int cnt=0;

            for (int j=1; j<=n; j++)
            {
                int num=input.nextInt();

                for (int k=0; primes[k]*primes[k]<=num; k++)
                {
                    while (num%primes[k]==0)
                    {
                        num/=primes[k]; cnt++;
                    }

                    if (cnt>counter[k]) counter[k]=cnt;

                    cnt=0;
                }

                if (num>1)
                {
                    for (int k=0; primes[k]<=num; k++)
                        if (primes[k]==num)
                        {
                            if (counter[k]==0)  counter[k]++;

                            break;
                        }
                }
            }

            BigInteger lcm=BigInteger.ONE;

            for (int j=0; j<indx; j++)
            {
                for (int k=1; k<=counter[j]; k++)
                    lcm=lcm.multiply(BigInteger.valueOf(primes[j]));

                counter[j]=0;
            }

            System.out.println("Case "+i+": "+lcm);

            gc();
        }
    }

}
