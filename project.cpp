#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

// Student Class
class Student {
public:
    int id;
    string name;
    int age;
    string contact;

    Student(int id, string name, int age, string contact) 
        : id(id), name(name), age(age), contact(contact) {}

    void displayStudent() {
        cout << setw(5) << id << setw(20) << name << setw(5) << age << setw(15) << contact << endl;
    }
};

// Course Class
class Course {
public:
    int courseID;
    string courseName;
    string instructor;

    Course(int courseID, string courseName, string instructor) 
        : courseID(courseID), courseName(courseName), instructor(instructor) {}

    void displayCourse() {
        cout << setw(5) << courseID << setw(20) << courseName << setw(20) << instructor << endl;
    }
};

// Attendance Record Structure
struct Attendance {
    int studentID;
    int courseID;
    string date;
    bool status; // true: present, false: absent
};

// Classroom Management System
class ClassroomManagementSystem {
private:
    vector<Student> students;
    vector<Course> courses;
    vector<Attendance> attendanceRecords;

public:
    // Add a Student
    void addStudent() {
        int id, age;
        string name, contact;
        cout << "Enter Student ID: ";
        cin >> id;
        cin.ignore();
        cout << "Enter Student Name: ";
        getline(cin, name);
        cout << "Enter Student Age: ";
        cin >> age;
        cin.ignore();
        cout << "Enter Student Contact: ";
        getline(cin, contact);
        students.push_back(Student(id, name, age, contact));
        cout << "Student added successfully!\n";
    }

    // Display Students
    void displayStudents() {
        cout << "\nList of Students:\n";
        cout << setw(5) << "ID" << setw(20) << "Name" << setw(5) << "Age" << setw(15) << "Contact" << endl;
        cout << string(50, '-') << endl;
        for (const auto& student : students) {
            student.displayStudent();
        }
    }

    // Add a Course
    void addCourse() {
        int courseID;
        string courseName, instructor;
        cout << "Enter Course ID: ";
        cin >> courseID;
        cin.ignore();
        cout << "Enter Course Name: ";
        getline(cin, courseName);
        cout << "Enter Instructor Name: ";
        getline(cin, instructor);
        courses.push_back(Course(courseID, courseName, instructor));
        cout << "Course added successfully!\n";
    }

    // Display Courses
    void displayCourses() {
        cout << "\nList of Courses:\n";
        cout << setw(5) << "ID" << setw(20) << "Course Name" << setw(20) << "Instructor" << endl;
        cout << string(50, '-') << endl;
        for (const auto& course : courses) {
            course.displayCourse();
        }
    }

    // Record Attendance
    void recordAttendance() {
        int studentID, courseID;
        string date;
        char statusChar;
        bool status;

        cout << "Enter Student ID: ";
        cin >> studentID;
        cout << "Enter Course ID: ";
        cin >> courseID;
        cin.ignore();
        cout << "Enter Date (YYYY-MM-DD): ";
        getline(cin, date);
        cout << "Enter Attendance Status (P for Present, A for Absent): ";
        cin >> statusChar;
        status = (statusChar == 'P' || statusChar == 'p');

        attendanceRecords.push_back({studentID, courseID, date, status});
        cout << "Attendance recorded successfully!\n";
    }

    // Display Attendance Records
    void displayAttendance() {
        cout << "\nAttendance Records:\n";
        cout << setw(10) << "Student ID" << setw(10) << "Course ID" 
             << setw(15) << "Date" << setw(10) << "Status" << endl;
        cout << string(50, '-') << endl;
        for (const auto& record : attendanceRecords) {
            cout << setw(10) << record.studentID << setw(10) << record.courseID
                 << setw(15) << record.date << setw(10) << (record.status ? "Present" : "Absent") << endl;
        }
    }
};

// Main Function
int main() {
    ClassroomManagementSystem cms;
    int choice;

    do {
        cout << "\n===== Classroom Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Add Course\n";
        cout << "4. Display Courses\n";
        cout << "5. Record Attendance\n";
        cout << "6. Display Attendance\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cms.addStudent();
            break;
        case 2:
            cms.displayStudents();
            break;
        case 3:
            cms.addCourse();
            break;
        case 4:
            cms.displayCourses();
            break;
        case 5:
            cms.recordAttendance();
            break;
        case 6:
            cms.displayAttendance();
            break;
        case 0:
            cout << "Exiting the program. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}
