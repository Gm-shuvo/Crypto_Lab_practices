#include <bits/stdc++.h>
using namespace std;

string encryptMsg(string msg){
    ifstream input("./senderPad.txt");
    string keyword , cipherText;
    int i;

    getline(input,keyword);
    input.close();

    if(keyword.size() < msg.size()){
        cout<<"!! pad msg length < orginal msg length !! please update one time pad."<<endl;
        exit(0);
    }

    ofstream output("./senderPad.txt");

    for(i = 0 ; i < msg.size() ; i++){
        if(islower(msg[i]))
            cipherText += ((msg[i]-'a') + (keyword[i]-'a')) % 26 + 'a';
        else 
            cipherText += msg[i];
    }

    for(;i<keyword.size();i++)
        output.put(keyword[i]);

    output.close();
    return cipherText;
}

string decryptMsg(string encMsg){
    ifstream input("./receiverPad.txt");
    string keyword , plainText;
    int i;

    getline(input,keyword);
    input.close();

    ofstream output("./receiverPad.txt");

    for(i = 0 ; i < encMsg.size() ; i++){
        if(islower(encMsg[i]))
            plainText += ((encMsg[i]-'a') - (keyword[i]-'a') + 26) % 26 + 'a';
        else 
            plainText += encMsg[i];
    }

    for(;i<keyword.size();i++)
        output.put(keyword[i]);

    output.close();
    return plainText;
}
int main(){
    string msg , encMsg , decMsg;
    ifstream in("./input.txt",ios::in);

    getline(in,msg);
    
    cout<<"Input Text: "<<msg<<endl;

    encMsg = encryptMsg(msg);
    cout<<"CipherText: "<<encMsg<<endl;

    decMsg = decryptMsg(encMsg);
    cout<<"PlainText: "<<decMsg<<endl;

    in.close();
    return 0;
}