package Lab_practices.MD5;
import java.math.BigInteger;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.Scanner;


public class md5 {
    public static void main(String[] args) {
      Scanner in = new Scanner(System.in);
      System.out.println("Enter a message to hash : ");
      String message = in.nextLine();

      try {
        MessageDigest md = MessageDigest.getInstance("MD5");

        byte[] hashBytes = md.digest(message.getBytes());

        StringBuilder hexString = new StringBuilder();

        for(byte hashByte : hashBytes){
          String hex = Integer.toHexString(0xFF &hashByte);
          if(hex.length() == 1){
            hexString.append('0');
          }
          hexString.append(hex);

        }
        System.out.println("Md5 hash : " + hexString.toString());
      } catch (NoSuchAlgorithmException e) {
        e.printStackTrace();
      }
    }
}

