package Lab_practices.RSA;
import java.math.BigInteger;
import java.util.*;

public class rsa {
  public byte[] encryption(String M, BigInteger e, BigInteger n){
    // M into bytes
    BigInteger m = new BigInteger(M.getBytes());

    // Compute the cipher c = m^e mod n
    byte[] c = m.modPow(e, n).toByteArray();

    // convert byte to string to print
    String x = Arrays.toString(c);
    System.out.println("Cipher ==> " + x);
    return c;
  }


  public String decryption(BigInteger d, byte[] c, BigInteger n){
    BigInteger cp = new BigInteger(c);

    BigInteger dMsg = cp.modPow(d, n);

    String decrypt = new String(dMsg.toByteArray());
    return decrypt;    
  }

  public static void main(String[] args) {
    // 1. chosing two random prime number
    int bitLength = 128;
    Random rand = new Random();
    BigInteger p = BigInteger.probablePrime(bitLength, rand);
    BigInteger q = BigInteger.probablePrime(bitLength, rand);

    // 2. calculate n = p * q
    BigInteger n = p.multiply(q);

    // 3. calculate phi = (p - 1) * (q - 1)
    BigInteger phi = p.subtract(BigInteger.ONE).multiply(q.subtract(BigInteger.ONE));

    // 4. calculate such "e" is co-prime to phi
    BigInteger e = BigInteger.valueOf(65537);

    // 5. check e is less than n and gcd of e, phi is not equla to one
    while(e.compareTo(n) == -1 && e.gcd(phi).compareTo(BigInteger.ONE) != 0){
      e.add(BigInteger.ONE);
    }

    // 6. compute d where (d * e) mod phi = 1 or d = e mod^-1 phi
    BigInteger d = e.modInverse(phi);

    System.out.println("Public Key ==> " + e + "," + n);
    System.out.println("Private Key ==> " + d + "," + n);

    //Input message

    Scanner in = new Scanner(System.in);
    System.out.println("Enter the message ==> ");
    String message = in.nextLine();
    in.close();

    rsa obj = new rsa();

    byte[] cipher = obj.encryption(message, e, n);

    String decryptMsg = obj.decryption(d, cipher, n);

    System.out.println("Decrypt Msg ==> " + decryptMsg);

  }
  
}
