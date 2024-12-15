#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct PersonalRecord {
    string name;
    string dob; 
    string telephoneNumber;

    PersonalRecord(string n, string d, string t) : name(n), dob(d), telephoneNumber(t) {}
};

void displayRecord(const PersonalRecord &record) {
    cout << "Name: " << record.name << ", DOB: " << record.dob << ", Telephone: " << record.telephoneNumber << endl;
}

bool compareRecordsByName(const PersonalRecord &a, const PersonalRecord &b) {
    return a.name < b.name;
}

PersonalRecord* searchRecordByName(vector<PersonalRecord> &records, const string &name) {
    for (auto &record : records) {
        if (record.name == name) {
            return &record;  
        }
    }
    return nullptr;  
}

int main() {
    vector<PersonalRecord> records;

    records.push_back(PersonalRecord("vedant", "1990-03-15", "123-456-7890"));
    records.push_back(PersonalRecord("vaishnavi", "1985-08-20", "987-654-3210"));
    records.push_back(PersonalRecord("Isha", "2000-06-25", "555-123-4567"));
    records.push_back(PersonalRecord("Pranjal", "1992-01-10", "222-333-4444"));

    sort(records.begin(), records.end(), compareRecordsByName);

    cout << "Sorted Records by Name:\n";
    for (const auto &record : records) {
        displayRecord(record);
    }

    string nameToSearch = "vedant";
    PersonalRecord* foundRecord = searchRecordByName(records, nameToSearch);

    if (foundRecord) {
        cout << "\nFound record for " << nameToSearch << ":\n";
        displayRecord(*foundRecord);
    } else {
        cout << "\nRecord for " << nameToSearch << " not found.\n";
    }

    return 0;
}