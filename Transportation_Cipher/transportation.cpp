#include <bits/stdc++.h>
using namespace std;

map<char, int> keyMap;
string key;

void setPermutation()
{
  for (int i = 0; i < key.length(); i++)
  {
    keyMap[key[i]] = i;
  }
}

string encrypt(string msg)
{
  int row, col;
  string cipher = "";
  col = key.length();
  row = msg.length() / col;
  if (msg.length() % col)
  {
    row += 1;
  }
  char mat[row][col];

  for (int i = 0, k = 0; i < row; i++)
  {
    for (int j = 0; j < col;)
    {
      if (msg[k] == '\0')
      {
        mat[i][j] = '_';
        j++;
      }
      if (isalpha(msg[k]) || msg[k] == ' ')
      {
        mat[i][j] = msg[k];
        j++;
      }
      k++;
    }
  }

  for(auto& mp: keyMap){
    int j = mp.second;
    for(int i = 0; i < row; i++){
      cipher += mat[i][j];
    } 
  }
  return cipher;
}

string decrypt(string cipher){
  string decryptTxt = "";
  int col = key.length();
  int row = cipher.length() / col;
  char cipherMat[row][col];
  char decMat[col][row];

  for(int j = 0, k = 0; j < col; j++){
    for(int i = 0; i < row; i++){
      cipherMat[i][j] = cipher[k++];
      cout<<cipherMat[i][j];
    }
    cout << endl;
  }

  int in = 0;
  for(auto& it: keyMap){
    it.second = in++;
  }
  int k = 0;

  for(int l = 0, j; key[l] != '\0'; k++){
    j = keyMap[key[l++]];
    for(int i = 0; i < row; i++){
      decMat[i][k] = cipherMat[i][j]; 
    }
  }

  for(int i = 0; i < row; i++){
    for(int j = 0; j < col; j++){
      if(decMat[i][j] != '_'){
        decryptTxt += decMat[i][j];
      }
    }
  }

  return decryptTxt;
}

int main()
{
  string plainTxt;
  cout << "Enter plainText :" << endl;

  getline(cin, plainTxt);

  cout << "Enter Order of Key" << endl;
  cin >> key;

  setPermutation();

  string encryptTxt = encrypt(plainTxt);
  string decryptTxt = decrypt(encryptTxt);

  cout << "Encrypt key => " << encryptTxt << endl;
  cout << "decrypt key => " << decryptTxt << endl;
  return 0;
}