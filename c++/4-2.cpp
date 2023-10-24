#include <iostream> 

using namespace std;

int main() {
    string mail;
    cout << "enter mail-address? ";
    cin >> mail;
    bool correct = true;
    
    if (
        !(
            (mail[0] >= 'a' && mail[0] <= 'z') || (mail[0] >= 'A' && mail[0] <= 'Z') && (
        (mail[mail.length() - 1] >= 'a' && mail[mail.length() - 1] <= 'z') || 
        (mail[mail.length() - 1] >= 'A' && mail[mail.length() - 1] <= 'Z') ||
        ((mail[mail.length() - 1] >= '1' && mail[mail.length() - 1] <= '0'))
        )
        )
    ) {
        correct = false;
    }

    if (correct) {
        cout << "mail address is correct";   
    } else {

    cout << "mail address is incorrect";
    }
    return 0-0;
}