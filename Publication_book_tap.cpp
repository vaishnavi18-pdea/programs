#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class Publication {
protected:
    string title;
    float price;

public:
    Publication() : title(""), price(0.0f) {}

    void input() {
        cout << "Enter title: ";
        cin.ignore(); 
        getline(cin, title);
        cout << "Enter price: ";
        cin >> price;
        if (price < 0) throw invalid_argument("Price cannot be negative.");
    }

    void display() const {
        cout << "Title: " << title << endl;
        cout << "Price: $" << price << endl;
    }

    void reset() {
        title = "";
        price = 0.0f;
    }
};

class Book : public Publication {
private:
    int pageCount;

public:
    Book() : pageCount(0) {}

    void input() {
        try {
            Publication::input();
            cout << "Enter page count: ";
            cin >> pageCount;
            if (pageCount < 0) throw invalid_argument("Page count cannot be negative.");
        } catch (const exception &e) {
            cerr << "Error: " << e.what() << endl;
            reset(); 
        }
    }

    void display() const {
        Publication::display();
        cout << "Page Count: " << pageCount << endl;
    }

    void reset() {
        Publication::reset();
        pageCount = 0;
    }
};

class Tape : public Publication {
private:
    float playingTime;

public:
    Tape() : playingTime(0.0f) {}

    void input() {
        try {
            Publication::input();
            cout << "Enter playing time (in minutes): ";
            cin >> playingTime;
            if (playingTime < 0) throw invalid_argument("Playing time cannot be negative.");
        } catch (const exception &e) {
            cerr << "Error: " << e.what() << endl;
            reset(); 
        }
    }

    void display() const {
        Publication::display();
        cout << "Playing Time: " << playingTime << " minutes" << endl;
    }

    void reset() {
        Publication::reset();
        playingTime = 0.0f;
    }
};

int main() {
    Book book;
    Tape tape;

    cout << "Enter details for book:" << endl;
    book.input();
    cout << "\nEnter details for tape:" << endl;
    tape.input();

    cout << "\nDisplaying details of book:" << endl;
    book.display();
    cout << "\nDisplaying details of tape:" << endl;
    tape.display();

    return 0;
}