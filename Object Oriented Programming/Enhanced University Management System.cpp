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

    void set_age(int newAge) {
        age = newAge;
    }
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

    int get_student_ID() { return student_ID; }

    void update_details(int newAge, int newStudentID) {
        set_age(newAge);  
        student_ID = newStudentID;
    }
};

class Course {
private:
    string course_name;
    int course_code;

public:
    Course(string Name, int Code) : course_name(Name), course_code(Code) {}
    Course() {}

    string get_course_name() { return course_name; }
    int get_course_code() { return course_code; }
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

    string get_department_name() { return department_name; }

    void add_teacher(Teacher teacher) {
        if (teacher_count < 10) {
            teachers[teacher_count] = teacher;
            teacher_count++;
        } else {
            cout << "ERROR: Maximum limit to add teacher records reached!" << endl;
        }
    }

    void add_student(Student student) {
        if (student_count < 10) {
            students[student_count] = student;
            student_count++;
        } else {
            cout << "ERROR: Maximum limit to add student records exceeded!" << endl;
        }
    }

    void add_course(Course course) {
        if (course_count < 10) {
            courses[course_count] = course;
            course_count++;
        } else {
            cout << "ERROR: Maximum limit to add course records reached!" << endl;
        }
    }

    void display_department_info() {
        cout << "Department: " << department_name << endl;
        cout << "Teachers: " << endl;
        for (int i = 0; i < teacher_count; i++) {
            cout << teachers[i].get_name() << "\tAge: " << teachers[i].get_age()
                 << "\tDegree: " << teachers[i].get_degree() << "\tExperience: " << teachers[i].get_experience() << endl;
        }

        cout << "Students: " << endl;
        for (int i = 0; i < student_count; i++) {
            cout << students[i].get_name() << "\tAge: " << students[i].get_age()
                 << "\tStudent ID: " << students[i].get_student_ID() << endl;
        }

        cout << "Courses: " << endl;
        for (int i = 0; i < course_count; i++) {
            cout << courses[i].get_course_name() << "\tCode: " << courses[i].get_course_code() << endl;
        }
    }

    Teacher* search_teacher_by_name(string name) {
        for (int i = 0; i < teacher_count; i++) {
            if (teachers[i].get_name() == name) {
                return &teachers[i];
            }
        }
        return nullptr;
    }

    Student* search_student_by_ID(int studentID) {
        for (int i = 0; i < student_count; i++) {
            if (students[i].get_student_ID() == studentID) {
                return &students[i];
            }
        }
        return nullptr;
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

    void add_department(Department department) {
        if (department_count < 10) {
            departments[department_count] = department;
            department_count++;
        } else {
            cout << "ERROR: Maximum limit to add department records reached!" << endl;
        }
    }

    void display_university_info() {
        cout << "University: " << university_name << endl;
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
            cout << "\nUniversity Main Menu" << endl;
            cout << "1. Add Department" << endl;
            cout << "2. Manage Department" << endl;
            cout << "3. Display University Info" << endl;
            cout << "4. View All Departments" << endl;
            cout << "5. Search Teacher by Name" << endl;
            cout << "6. Update Student Details" << endl;
            cout << "7. Exit" << endl;
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
                case 4: {
                    cout << "Departments in the University: " << endl;
                    for (int i = 0; i < department_count; i++) {
                        cout << i + 1 << ". " << departments[i].get_department_name() << endl;
                    }
                    break;
                }
                case 5: {
                    string teacher_name;
                    cout << "Enter teacher name to search: ";
                    cin.ignore();
                    getline(cin, teacher_name);

                    Teacher* found_teacher = nullptr;
                    for (int i = 0; i < department_count; i++) {
                        found_teacher = departments[i].search_teacher_by_name(teacher_name);
                        if (found_teacher != nullptr) break;
                    }

                    if (found_teacher) {
                        cout << "Teacher Found: " << found_teacher->get_name() << "\tAge: " << found_teacher->get_age()
                             << "\tDegree: " << found_teacher->get_degree() << "\tExperience: " << found_teacher->get_experience() << endl;
                    } else {
                        cout << "Teacher not found!" << endl;
                    }
                    break;
                }
                case 6: {
                    int studentID, newAge, newStudentID;
                    cout << "Enter student ID to update: ";
                    cin >> studentID;

                    Student* student_to_update = nullptr;
                    for (int i = 0; i < department_count; i++) {
                        student_to_update = departments[i].search_student_by_ID(studentID);
                        if (student_to_update != nullptr) break;
                    }

                    if (student_to_update) {
                        cout << "Enter new age: ";
                        cin >> newAge;
                        cout << "Enter new student ID: ";
                        cin >> newStudentID;
                        student_to_update->update_details(newAge, newStudentID);
                        cout << "Student details updated successfully!" << endl;
                    } else {
                        cout << "Student not found!" << endl;
                    }
                    break;
                }
                case 7:
                    break;
                default:
                    cout << "Invalid choice. Please choose again." << endl;
            }
        } while (choice != 7);
    }

    void manage_department(Department& department) {
        int choice;
        do {
            cout << "Department Management Menu" << endl;
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
                    cout << "Enter teacher experience (in years): ";
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
