package Lab_practices.DiffiHellman;
import java.math.BigInteger;
import java.security.SecureRandom;

public class diffihallman {
  public static BigInteger GeneratePrivateKey(){
    SecureRandom rand = new SecureRandom();
    BigInteger privateKey = new BigInteger("1000");
    return new BigInteger(privateKey.bitLength(), rand).mod(privateKey);
  }
  public static void main(String[] args) {
    // Generate p as prime and q as base
    BigInteger p = new BigInteger("5637");
    BigInteger g = new BigInteger("5");

    // Generate Private key
    BigInteger a = GeneratePrivateKey();
    BigInteger b = GeneratePrivateKey();

    // calculate public key
    BigInteger A = g.modPow(a, p);
    BigInteger B = g.modPow(b, p);

    // Exchange public keys (over an insecure channel)

    // Calculate shared secret key for Alice and Bob

    BigInteger secretA = B.modPow(a, p);
    BigInteger secretB = A.modPow(b, p);

    System.out.println("Alice secret key ==> " + secretA);
    System.out.println("Bob secret key ==> " + secretB);
  }
  
}
