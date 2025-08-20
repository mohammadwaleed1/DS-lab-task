#include <iostream>
#include <cstring>
using namespace std;

class exam {
private:
    char* date;
    char* name;
    int* score;
public:
    exam(const char* n, const char* d, int sc) {
        date = new char[strlen(d) + 1];
        strcpy(date, d);

        name = new char[strlen(n) + 1];
        strcpy(name, n);

        score = new int(sc);
    }

    void setter(const char* n, const char* d, int sc) {
        strcpy(date, d);
        strcpy(name, n);
        *score = sc;
    }

    ~exam() {
        delete[] date;
        delete[] name;
        delete score;
    }

    void display() const {
        cout << "name: " << name << endl;
        cout << "date: " << date << endl;
        cout << "score: " << *score << endl;
    }
};

int main() {
    exam exam1("waheed", "22-01-2025", 90);

    cout << "Original Object:\n";
    exam1.display();

    // Shallow copy (default copy constructor)
    exam exam2 = exam1;

    cout << "\nCopied Object (Shallow Copy):\n";
    exam2.display();

    return 0;
}
