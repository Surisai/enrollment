
///work!
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class Student {
private:
    int studentID;
    char name[100];
    char course[100];

public:
    // Constructors
    Student() : studentID(0) {
        name[0] = '\0';
        course[0] = '\0';
    }

    Student(int id, const char* n, const char* c) : studentID(id) {
        setName(n);
        setCourse(c);
    }

    // Prohibit copy construction and copy assignment
    Student(const Student&) = delete;
    Student& operator=(const Student&) = delete;

    // Setter functions
    void setStudentID(int id) {
        studentID = id;
    }

    void setName(const char* n) {
        strncpy(name, n, sizeof(name) - 1);
        name[sizeof(name) - 1] = '\0'; // Ensure null termination
    }

    void setCourse(const char* c) {
        strncpy(course, c, sizeof(course) - 1);
        course[sizeof(course) - 1] = '\0'; // Ensure null termination
    }

    // Getter functions
    int getStudentID() const {
        return studentID;
    }

    const char* getName() const {
        return name;
    }

    const char* getCourse() const {
        return course;
    }

    // Display function
    void display() const {
        cout << "Student ID: " << studentID << endl;
        cout << "Name: " << name << endl;
        cout << "Course: " << course << endl;
    }

    // Read function
    void read() {
        int id;
        char n[100];
        char c[100];

        cout << "Enter student ID: ";
        cin >> id;
        cin.ignore(); // Ignore remaining newline character

        cout << "Enter student name: ";
        cin.getline(n, sizeof(n));

        cout << "Enter student course: ";
        cin.getline(c, sizeof(c));

        // Directly set the current object's data
        setStudentID(id);
        setName(n);
        setCourse(c);
    }

    // Function to check if student object is empty
    bool isEmpty() const {
        return studentID == 0 && name[0] == '\0' && course[0] == '\0';
    }

};

class AnthropologyClub : public Student {
private:
    int memberID;

public:
    AnthropologyClub() : memberID(0) {}

    void setMemberID(int id) {
        memberID = id;
    }

    void enroll(const Student& s) {
        if (strcmp(s.getCourse(), "Anthropology") == 0) {
            setMemberID(s.getStudentID());
            setName(s.getName());
            setCourse(s.getCourse());
            cout << "Student " << s.getName() << " enrolled in Anthropology Club." << endl;
        } else {
            cout << "Student " << s.getName() << " is not enrolled in Anthropology." << endl;
        }
    }

    void display() const {
        cout << "Member ID: " << memberID << endl;
        Student::display();
    }

    int getMemberID() const {
        return memberID;
    }

    const char* getName() const {
        return Student::getName();
    }

    const char* getCourse() const {
        return Student::getCourse();
    }
};

int main() {
    AnthropologyClub club;
    char more[10];

    do {
        Student s;
        s.read();
        club.enroll(s);

        ofstream outputFile("anthropology_club_members.txt", ios::app);
        if (outputFile.is_open()) {
            outputFile << "Member ID: " << club.getMemberID() << endl;
            outputFile << "Name: " << club.getName() << endl;
            outputFile << "Course: " << club.getCourse() << endl;
            outputFile << "------------------------------------------" << endl;
            outputFile.close();
            cout << "Output written to file." << endl;
        } else {
            cout << "Unable to open file." << endl;
        }

        cout << "Do you want to add another student? (yes/no): ";
        cin >> more;
    } while (strcmp(more, "yes") == 0);

    return 0;
}
