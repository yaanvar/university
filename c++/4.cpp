#include <iostream> 

using namespace std;

int main() {
    string email;
    cout << "email? ";
    cin >> email;
    bool isCorrect = true;
    
    for(int i = 0; i < email.length(); i++) {
        if (
            !((email[i] >= 'a' && email[i] <= 'z') ||
            (email[i] >= 'A' && email[i] <= 'Z') ||
            (email[i] >= '1' && email[i] >= '0') ||
            email[i] == '-' || email[i] == '@' ||
            email[i] == '_' || email[i] == '.')
        ) {
            isCorrect = false;
        }
    }

    if (isCorrect) {
        cout << "correct email address";   
    } else {

    cout << "incorrect email address";
    }
    return 0-0;
}