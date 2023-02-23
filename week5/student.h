/// This header file will contain all the functions used for the student struct. Includes getters/setters.
#ifndef WEEK5_FUNCS_STUDENT
#define WEEK5_FUNCS_STUDENT
#include <iostream>
#include <vector>
#include <cstdio> //for printf

struct student
{
    int id;
    std::string name;
    int finalGrade;
    int midtermGrade;
    std::vector<int> hw_grades;
};

/// Student Create Function

/// @brief This function will prompt the user for information about a student and return the newly created student.
/// @param student This funciton inputs the address of a student.
void create_student_cli(student* student);

/// @brief This function will return a student struct object with all the values given. Sort of like a default constructor for the function.
/// @param id 
/// @param name 
/// @param midtermGrade 
/// @param finalGrade 
/// @param hw_grades 
/// @return a student struct object.
void create_student(student* student, int id, std::string name, int midtermGrade, int finalGrade, std::vector<int> hw_grades);


///Student Getters/Setters

void set_student_id(student* student, int id);
int get_student_id(student* student);
void set_student_name(student* student, std::string name);
std::string get_student_name(student* student);


/// @brief This will take a student and midterm grade as input and set the midterm grade.
/// @param student 
/// @param grade 
void set_student_midterm(student* student, int grade);

/// @brief This getter function will take a student address and output the midterm grade.
/// @param student 
/// @return mideterm grade of student (int).
int get_student_midterm(student* student);

/// @brief This getter function will take a student address and output the final grade.
/// @param student 
/// @return mideterm grade of student (int).
int get_student_final(student* student);

/// @brief This will take a student and midterm grade as input and set the final grade.
/// @param student 
/// @param grade 
void set_student_final(student* student, int grade);

/// @brief This function will return the current students vector array of student homework grades.
/// @param student 
/// @return the vector array containing the students hw grades.
std::vector<int> get_student_hw_grades(student* student);


/// Student list functions

/// @brief This function will set the hw grades for the student.
/// @param student 
/// @param hw_grades 
void set_student_hw_grades(student* student, std::vector<int> hw_grades);


#endif