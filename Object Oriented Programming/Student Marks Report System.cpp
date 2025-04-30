#include <iostream>
using namespace std;

const int NUM_STUDENTS = 5;

class Student {
private:
    string name;
    int id;
public:
    void set_name_and_id(const string& Name, int ID) {
        name = Name;
        id = ID;
    }
    string get_name() const { return name; }
    int get_id() const { return id; }
};

class Subject {
private:
    string subj1, subj2, subj3;
public:
    void set_subjects(const string& st1, const string& st2, const string& st3) {
        subj1 = st1;
        subj2 = st2;
        subj3 = st3;
    }
    string get_subj1() const { return subj1; }
    string get_subj2() const { return subj2; }
    string get_subj3() const { return subj3; }
};

class Marks {
private:
    int mark1, mark2, mark3;
public:
    void set_mark(int m1, int m2, int m3) {
        mark1 = m1;
        mark2 = m2;
        mark3 = m3;
    }
    int get_mark1() const { return mark1; }
    int get_mark2() const { return mark2; }
    int get_mark3() const { return mark3; }
    int get_total() const { return mark1 + mark2 + mark3; }
};

class Grade {
public:
    char get_grade(int mark) const {
        return (mark >= 80) ? 'A' :
               (mark >= 70) ? 'B' :
               (mark >= 60) ? 'C' :
               (mark >= 50) ? 'D' : 'F';
    }

    char get_total_grade(int total_mark) const {
        return (total_mark >= 240) ? 'A' :
               (total_mark >= 210) ? 'B' :
               (total_mark >= 180) ? 'C' :
               (total_mark >= 150) ? 'D' : 'F';
    }
};

class Comments {
public:
    string get_comment(char grade) const {
        switch (grade) {
            case 'A': return "Excellent performance.";
            case 'B': return "Very good.";
            case 'C': return "Good. Can improve.";
            case 'D': return "Needs improvement.";
            default:  return "Poor performance.";
        }
    }
};

int main() {
    Student students[NUM_STUDENTS];
    Subject subject;
    Marks marks[NUM_STUDENTS];
    Grade grade;
    Comments comments;

    subject.set_subjects("Calculus", "PF", "COAL");

    for (int i = 0; i < NUM_STUDENTS; i++) {
        string name;
        int sapId, mark1, mark2, mark3;

        cout << "\nEnter student name " << i + 1 << ": ";
        cin >> name;

        cout << "Enter SAP ID " << i + 1 << ": ";
        cin >> sapId;

        students[i].set_name_and_id(name, sapId);

        cout << "Enter marks for " << subject.get_subj1() << ": ";
        cin >> mark1;

        cout << "Enter marks for " << subject.get_subj2() << ": ";
        cin >> mark2;

        cout << "Enter marks for " << subject.get_subj3() << ": ";
        cin >> mark3;

        marks[i].set_mark(mark1, mark2, mark3);
    }

    cout << "\n\n===== Student Result Report =====\n";

    for (int i = 0; i < NUM_STUDENTS; i++) {
        cout << "\nStudent Name: " << students[i].get_name();
        cout << "\nSAP ID: " << students[i].get_id();

        cout << "\n" << subject.get_subj1() << ": " << marks[i].get_mark1();
        cout << "\tGrade: " << grade.get_grade(marks[i].get_mark1());
        cout << "\tComment: " << comments.get_comment(grade.get_grade(marks[i].get_mark1()));

        cout << "\n" << subject.get_subj2() << ": " << marks[i].get_mark2();
        cout << "\tGrade: " << grade.get_grade(marks[i].get_mark2());
        cout << "\tComment: " << comments.get_comment(grade.get_grade(marks[i].get_mark2()));

        cout << "\n" << subject.get_subj3() << ": " << marks[i].get_mark3();
        cout << "\tGrade: " << grade.get_grade(marks[i].get_mark3());
        cout << "\tComment: " << comments.get_comment(grade.get_grade(marks[i].get_mark3()));

        cout << "\nTotal Marks: " << marks[i].get_total();
        cout << "\nOverall Grade: " << grade.get_total_grade(marks[i].get_total());
        cout << "\n-------------------------------";
    }

    return 0;
}

