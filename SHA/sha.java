package Lab_practices.SHA;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.Scanner;

public class sha {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    
    System.out.println("Enter the message ");
    String message = in.nextLine();
    in.close();

    try{
      MessageDigest md = MessageDigest.getInstance("SHA-256");

      byte[] hashBytes = md.digest(message.getBytes());
      StringBuilder hexString = new StringBuilder();

      for(byte hashByte: hashBytes){
        String hex = Integer.toHexString(0xFF &hashByte);
        if(hex.length() == 1){
          hexString.append('0');
        }
        hexString.append(hex);
      }
      System.out.println("SHA : " + hexString);
    }
    catch(NoSuchAlgorithmException e){
      e.printStackTrace();
    }
  }
  
}
