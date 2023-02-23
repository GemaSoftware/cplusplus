#include "student.h"

void create_student_cli(student* student)
{
    //Only using this namespace in function scope.
    using namespace std;
    //Will have sanity checks on all input and exceptions for bad characters.
    // temp value to store all intermediate inputs.
    int studentID;
    string studentName;
    int midtermGrade;
    int finalGrade;
    vector<int> hw_grades;

    cout << "Please enter the student ID: ";
    cin >> studentID;
    if(studentID < 0 || cin.fail()) throw string("Invalid input detected");
    cin.ignore();

    cout << "Please enter the student name: ";
    getline(cin, studentName);
    if(studentName.length() <= 0) throw string("Invalid String Entered.");
    cin.ignore();

    cout << "Please enter the student midterm grade: ";
    cin >> midtermGrade;
    if(midtermGrade < 0 || cin.fail()) throw string("Invalid input detected");
    cin.ignore();

    cout << "Please enter the student final grade: ";
    cin >> finalGrade;
    if(finalGrade < 0 || cin.fail()) throw string("Invalid input detected");
    cin.ignore();

    cout << "Enter a homework score: (CTRL-D to finish)";
    int temp;
    while(cin >> temp){
        if(cin.fail() || temp < 0) {
            cout << "Invalid Score Entered." << endl;
            cout << "Enter a homework score: (CTRL-D to finish)" << endl;
            continue;
        } else {
            hw_grades.push_back(temp);
        }
    }
    create_student(student, studentID, studentName, midtermGrade, finalGrade, hw_grades);
}

//mainly used for unit testing. Makes inputing data easier.
void create_student(student* student, int id, std::string name, int midtermGrade, int finalGrade, std::vector<int> hw_grades)
{
    set_student_id(student, id);
    set_student_name(student, name);
    set_student_midterm(student, midtermGrade);
    set_student_final(student, finalGrade);
    set_student_hw_grades(student, hw_grades);
}

void set_student_id(student* student, int id)
{
    student->id = id;
}

int get_student_id(student* student)
{
    return student->id;
}

void set_student_name(student* student, std::string name)
{
    student->name = name;
}

std::string get_student_name(student* student)
{
    return (student->name.length() > 0) ? student->name : "NULL";
}

void set_student_midterm(student* student, int grade)
{
    student->midtermGrade = grade;
}

int get_student_midterm(student* student)
{
    return student->midtermGrade;
}

void set_student_final(student* student, int grade)
{
    student->finalGrade = grade;
}

int get_student_final(student* student)
{
    return student->finalGrade;
}

std::vector<int> get_student_hw_grades(student* student)
{
    return student->hw_grades;
}

void set_student_hw_grades(student* student, std::vector<int> hw_grades)
{
    student->hw_grades = hw_grades;
}

void add_student_hw_grade(student* student, int hw_grade)
{
    student->hw_grades.push_back(hw_grade);
}
