#include <bits/stdc++.h>
#include <iostream>
using namespace std;

string encrypt(string plainText, int key)
{
  string encryptext = "";
  for (int i = 0; i < plainText.length(); i++)
  {
    // check if character
    if (isalpha(plainText[i]))
    {
      // case upper and lower
      char base = isupper(plainText[i]) ? 'A' : 'a';

      // perform the shif
      char encryption = ((plainText[i] - base + key) % 26) + base;

      encryptext += encryption;
    }
    else{
      encryptext += plainText[i];
    }
  }
  return encryptext;
}

string decrypt(string crypherText, int key)
{
  string decryptText = encrypt(crypherText, 26 - key);
  return decryptText;
}

int main()
{
  string plaintext;
  int key;
  cout << "Enter a plaintext" << endl;
  getline(cin, plaintext);
  cout << "Enter a key" << endl;
  cin >> key;

  string encryptedText = encrypt(plaintext, key);
  cout<<"Encryption Text => " << encryptedText << endl;

  string decryptedText = decrypt(encryptedText, key);
  cout<< "Decryption Text => "<< decryptedText <<endl;
  
  return 0;
}