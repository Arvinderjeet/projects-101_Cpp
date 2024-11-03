#include "iostream"
#include "string"
#include <cstdlib>
#include <ctime>
#include <unistd.h>

using namespace std;

void intermediate() {
    int no_of_digits = 1;
    while (true) {
        string random_value;
        string user_input;
        for (int i = 1; i <= no_of_digits; ++i) {
            int value = rand() % 10;
            random_value += to_string(value);
            cout << value << " ";
            sleep(1);
        }
        system("cls");
        cout << "Enter the sequence: ";
        getline(cin, user_input);
        if (user_input != random_value) {
            cout << endl << "You Need some almonds or You're \"BRAINLESS\"";
            sleep(2);
            return;
        }
        cout << "yoo!! correct!!!" << endl;
        sleep(1);
        no_of_digits++;
        random_value.clear();
        user_input.clear();
        system("cls");
    }
}

int main() {
    srand(static_cast<unsigned>(std::time(nullptr)));
    intermediate();
    return 0;
}