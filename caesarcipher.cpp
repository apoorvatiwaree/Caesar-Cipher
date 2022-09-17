#include <iostream>

using namespace std;

int main()
{
    int choice;
    cout <<"--------CAESAR-CIPHER-ENCRYPTOR-DECRYPTOR---------\nPick your preferred option\n1. Encryption\n2. Decryption\nEnter choice(1,2): ";
    cin >> choice;
    cin.ignore();

    if (choice == 1){
        string msg;
        cout << "\nMessage can only be alphabetic";
        cout << "\nEnter message: ";
        getline(cin, msg);

        int key;
        cout << "\nEnter key (0-25): ";
        cin >> key;
        cin.ignore();

        string encryptedText = msg;

        for (int i = 0; i < msg.size(); i ++){
            if(msg[i]==32){
                continue; 
                } 
                else{
                if((msg[i] + key) > 122){
                    int temp = (msg[i] + key) - 122;
                    encryptedText[i] = 96 + temp;
                } 
                else if (msg[i] + key > 90 && msg[i] <= 96){
                    int temp = (msg[i] + key) - 90;
                    encryptedText[i] = 64 + temp;
                } 
                else{
                    encryptedText[i] += key;
                }
            } 
        } 
        cout <<"\nEncrypted Message: "<<encryptedText;

    } 
    else if(choice == 2){
        string encpMsg;
        cout <<"\nMessage can only be alphabetic";
        cout <<"\nEnter encrypted text: ";
        getline(cin, encpMsg);

        int dcyptKey;
        cout <<"\nEnter key (0-25): ";
        cin >> dcyptKey;
        cin.ignore();
        string decryptedText = encpMsg;

        for (int i = 0; i < encpMsg.size(); i++){
            if(encpMsg[i]==32){
                continue; 
            } else {
                if((encpMsg[i] - dcyptKey) < 97 && (encpMsg[i] - dcyptKey) > 90){
                    int temp = (encpMsg[i] - dcyptKey) + 26;
                    decryptedText[i] = temp;
                } else if((encpMsg[i] - dcyptKey) < 65){
                    int temp = (encpMsg[i] - dcyptKey) + 26;
                    decryptedText[i] = temp;
                } else {
                    decryptedText[i] = encpMsg[i] - dcyptKey;
                }
            }
        }

        cout <<"\nDecrypted Message: " << decryptedText << endl;

    } else {
        cout <<"Invalid choice";
    }
    return 0;

}