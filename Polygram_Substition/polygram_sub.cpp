#include <bits/stdc++.h>
#include <iostream>
using namespace std;

string encrypt(string plaintext, map<string, string>& sub){
  string entext = "";
  int ploysize = sub.begin()->first.length();

  for(int i = 0; i < plaintext.length(); i += ploysize){
    string plainGrp = plaintext.substr(i, ploysize);
    entext += sub[plainGrp]; 
  }
  return entext;
}

string decrypt(string cipher, map<string , string>& sub){
  string decryptTxt;
  int polysize = sub.begin()->first.length();
  for(int i = 0; i < cipher.length(); i += polysize){
    string subCipher = cipher.substr(i, polysize);
    for(auto& m : sub){
      if(m.second == subCipher){
        decryptTxt += m.first;
      }
    }
  }
  return decryptTxt;
}


int main()
{
  string plaintext;
  map<string, string> subMap;
  subMap["ABC"] = "XYZ";
  subMap["DEF"] = "LMN";
  subMap["XYZ"] = "ABC";

  cout<<"Enter a PlainText"<<endl;
  getline(cin, plaintext);

  string encryptionText = encrypt(plaintext, subMap);
  string decryptionText = decrypt(encryptionText, subMap);

  cout << "Encryption => " << encryptionText << endl;
  cout << "Decryption => " << decryptionText << endl;
  
  return 0;
}