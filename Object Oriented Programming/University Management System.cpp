#include <iostream>
using namespace std;

class Person {
private:
    string name;
    int age;
public:
    Person(string Name, int Age) : name(Name), age(Age) {}
    Person() {}

    string get_name() const { return name; }
    int get_age() const { return age; }
};

class Qualification {
public:
    string degree;
    int experience;

    Qualification(string Degree, int Experience) : degree(Degree), experience(Experience) {}
    Qualification() {}
};

class Teacher : public Person {
public:
    Qualification qualification;

    Teacher(string Name, int Age, string Degree, int Experience) : Person(Name, Age), qualification(Degree, Experience) {}
    Teacher() : Person(), qualification() {}

    string get_degree() const { return qualification.degree; }
    int get_experience() const { return qualification.experience; }
};

class Student : public Person {
private:
    int student_ID;

public:
    Student(string Name, int Age, int studentID) : Person(Name, Age), student_ID(studentID) {}
    Student() : Person() {}

    int get_student_ID() const { return student_ID; }
};

class Course {
private:
    string course_name;
    int course_code;

public:
    Course(string Name, int Code) : course_name(Name), course_code(Code) {}
    Course() {}

    string get_course_name() const { return course_name; }
    int get_course_code() const { return course_code; }
};

class Department {
private:
    string department_name;
    Teacher teachers[10];
    Student students[10];
    Course courses[10];
    int teacher_count, student_count, course_count;

public:
    Department(string Name) : department_name(Name), teacher_count(0), student_count(0), course_count(0) {}
    Department() {}

    string get_department_name() const { return department_name; }

    void add_teacher(const Teacher& teacher) {
        if (teacher_count < 10) {
            teachers[teacher_count++] = teacher;
        } else {
            cout << "ERROR: Maximum teacher limit reached!" << endl;
        }
    }

    void add_student(const Student& student) {
        if (student_count < 10) {
            students[student_count++] = student;
        } else {
            cout << "ERROR: Maximum student limit reached!" << endl;
        }
    }

    void add_course(const Course& course) {
        if (course_count < 10) {
            courses[course_count++] = course;
        } else {
            cout << "ERROR: Maximum course limit reached!" << endl;
        }
    }

    void display_department_info() const {
        cout << "Department: " << department_name << endl;
        cout << "Teachers: " << endl;
        for (int i = 0; i < teacher_count; i++) {
            cout << teachers[i].get_name() << " | Age: " << teachers[i].get_age() << " | Degree: " << teachers[i].get_degree() << " | Experience: " << teachers[i].get_experience() << endl;
        }

        cout << "Students: " << endl;
        for (int i = 0; i < student_count; i++) {
            cout << students[i].get_name() << " | Age: " << students[i].get_age() << " | Student ID: " << students[i].get_student_ID() << endl;
        }

        cout << "Courses: " << endl;
        for (int i = 0; i < course_count; i++) {
            cout << courses[i].get_course_name() << " | Code: " << courses[i].get_course_code() << endl;
        }
    }
};

class University {
private:
    string university_name;
    Department departments[10];
    int department_count;

public:
    University(string Name) : university_name(Name), department_count(0) {}
    University() {}

    void add_department(const Department& department) {
        if (department_count < 10) {
            departments[department_count++] = department;
        } else {
            cout << "ERROR: Maximum department limit reached!" << endl;
        }
    }

    void display_university_info() const {
        cout << "University Name: " << university_name << endl;
        for (int i = 0; i < department_count; i++) {
            departments[i].display_department_info();
            cout << endl;
        }
    }

    void main_menu() {
        int choice, department_choice;
        Department department;
        Teacher teacher;
        Student student;
        Course course;

        do {
            cout << "\nUniversity Management System" << endl;
            cout << "1. Add Department" << endl;
            cout << "2. Manage Department" << endl;
            cout << "3. Display University Info" << endl;
            cout << "4. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1: {
                    string department_name;
                    cout << "Enter department name: ";
                    cin.ignore();
                    getline(cin, department_name);
                    department = Department(department_name);
                    add_department(department);
                    break;
                }
                case 2: {
                    if (department_count == 0) {
                        cout << "No departments available." << endl;
                        break;
                    }

                    cout << "Select a department to manage:" << endl;
                    for (int i = 0; i < department_count; i++) {
                        cout << i + 1 << ". " << departments[i].get_department_name() << endl;
                    }

                    cin >> department_choice;
                    if (department_choice >= 1 && department_choice <= department_count) {
                        manage_department(departments[department_choice - 1]);
                    } else {
                        cout << "Invalid department choice." << endl;
                    }
                    break;
                }
                case 3:
                    display_university_info();
                    break;
                case 4:
                    break;
                default:
                    cout << "Invalid choice. Please choose again." << endl;
            }
        } while (choice != 4);
    }

    void manage_department(Department& department) {
        int choice;
        do {
            cout << "\nDepartment Management Menu" << endl;
            cout << "1. Add Teacher" << endl;
            cout << "2. Add Student" << endl;
            cout << "3. Add Course" << endl;
            cout << "4. View Department Info" << endl;
            cout << "5. Back" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1: {
                    string name, degree;
                    int age, experience;
                    cout << "Enter teacher name: ";
                    cin.ignore();
                    getline(cin, name);
                    cout << "Enter teacher age: ";
                    cin >> age;
                    cout << "Enter teacher degree: ";
                    cin.ignore();
                    getline(cin, degree);
                    cout << "Enter teacher experience: ";
                    cin >> experience;
                    Teacher teacher(name, age, degree, experience);
                    department.add_teacher(teacher);
                    break;
                }
                case 2: {
                    string name;
                    int age, studentID;
                    cout << "Enter student name: ";
                    cin.ignore();
                    getline(cin, name);
                    cout << "Enter student age: ";
                    cin >> age;
                    cout << "Enter student ID: ";
                    cin >> studentID;
                    Student student(name, age, studentID);
                    department.add_student(student);
                    break;
                }
                case 3: {
                    string courseName;
                    int courseCode;
                    cout << "Enter course name: ";
                    cin.ignore();
                    getline(cin, courseName);
                    cout << "Enter course code: ";
                    cin >> courseCode;
                    Course course(courseName, courseCode);
                    department.add_course(course);
                    break;
                }
                case 4:
                    department.display_department_info();
                    break;
                case 5:
                    break;
                default:
                    cout << "Invalid choice. Please choose again." << endl;
            }
        } while (choice != 5);
    }
};

int main() {
    University university("University of Lahore");
    university.main_menu();
    return 0;
}
