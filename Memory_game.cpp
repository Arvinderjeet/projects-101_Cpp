#include "iostream"
#include "string"
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <limits>

using namespace std;

//todo: add 1 more level [genius] : no idea for that!!

int SCORE = 0;
int HIGH_SCORE = 0;

int generate_value() {
    return rand() % 10;
}

void high_score(int score = 0) {
    if (score > HIGH_SCORE) {
        HIGH_SCORE = score;
    }
    cout << "[ High Score: " << HIGH_SCORE <<" ]"<< endl;
    cout << "[ Your score: " << SCORE <<" ]"<< endl;
    sleep(1);
}

bool check_answer(const string &random_value) {
    string user_input = {};
    cout << "Enter the sequence: ";
    getline(cin, user_input);

    if (user_input != random_value) {
        cout << endl << "You Need some almonds or You're \"BRAINLESS\"\n";
        high_score(SCORE);
        sleep(2);
        SCORE = 0;
        return false;
    }
    cout << "yoo!! correct!!!" << endl;
    SCORE++;
    sleep(1);
    return true;
}

void easy() {
    system("cls");
    sleep(1);
    string random_value;
    while (true) {
        system("cls");
        if(SCORE != 0) high_score(SCORE);
        random_value += to_string(generate_value());
        for (int j = 0; j < random_value.length(); ++j) {
            cout << random_value[j] << " ";
            sleep(1);
        }
        sleep(2);
        system("cls");
        if (!check_answer(random_value)) return;
        system("cls");
    }
}

void intermediate() {
    system("cls");
    sleep(1);
    int no_of_digits = 1;
    while (true) {
        if(SCORE != 0) high_score(SCORE);
        sleep(1);
        system("cls");
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
        system("cls");
    }
}

void hard() {
    system("cls");
    sleep(1);
    int no_of_digits = 1;
    while (true) {
        sleep(1);
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
        system("cls");
        if(SCORE != 0) high_score(SCORE);
        cout << "Menu:\n";
        cout << "1. Easy\n";
        cout << "2. Intermediate\n";
        cout << "3. Hard\n";
        cout << "0. Exit\n";
        int choice;
        while (true) {
            cout << "Enter your choice: ";
            if (cin >> choice && choice >= 0 && choice <= 3) {
                cin.ignore();
                break;
            } else {
                cout << "Invalid input. Try again.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
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
            exit(0);
        }
        system("cls");
    }
}