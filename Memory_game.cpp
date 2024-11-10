#include "iostream"
#include "string"
#include <cstdlib>
#include <ctime>
#include <unistd.h>

using namespace std;

//todo: add score system
//todo: add high score system
//todo: add 1 more level [genius]
//todo: add timer system
int generate_value() {
    return rand() % 10;
}

bool check_answer(const string &random_value) {
    string user_input = {};
    cout << "Enter the sequence: ";
    getline(cin, user_input);

    if (user_input != random_value) {
        cout << endl << "You Need some almonds or You're \"BRAINLESS\"";
        sleep(2);
        return false;
    }
    cout << "yoo!! correct!!!" << endl;
    sleep(1);
    return true;
}

void easy() {
    string random_value;
    while (true) {
        random_value += to_string(generate_value());
        cout << endl;
        for (int j = 0; j < random_value.length(); ++j) {
            cout << random_value[j] << " ";
            sleep(1);
        }
        sleep(2);
        system("cls");
        if (!check_answer(random_value)) return;
        sleep(1);
        system("cls");
    }
}

void intermediate() {
    int no_of_digits = 1;
    while (true) {
        string random_value;
        for (int i = 1; i <= no_of_digits; ++i) {
            int value = rand() % 10;
            random_value += to_string(value);
            cout << value << " ";
            sleep(1);
        }
        sleep(1);
        if (!check_answer(random_value)) return;
        no_of_digits++;
        random_value.clear();
        system("cls");
    }
}

void hard() {
    int no_of_digits = 1;
    while (true) {
        string random_value;
        for (int i = 1; i <= no_of_digits; ++i) {
            int value = rand() % 10;
            random_value += to_string(value);
            cout << value << " ";
            sleep(1);
            system("cls");
        }
        if (!check_answer(random_value)) return;
        no_of_digits++;
        random_value.clear();
        system("cls");
    }
}

int main() {
    system("cls");
    srand(static_cast<unsigned>(std::time(nullptr)));
    while (true) {
        cout << "Menu:\n";
        cout << "1. Easy\n";
        cout << "2. Intermediate\n";
        cout << "3. Hard\n";
        cout << "0. Exit\n";
        int choice;
        cin >> choice;
        if (choice == 1) {
            easy();
        }
        if (choice == 2) {
            intermediate();
        }
        if (choice == 3) {
            hard();
        }
        if (choice == 0) {
            return 0;
        }
        cout << "invalid input";
        system("cls");
    }
}