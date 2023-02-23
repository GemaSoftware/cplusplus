#ifndef WEEK5_FUNCS
#define WEEK5_FUNCS
#include "student.h"

/// Student Utility Functions

/// @brief This will compute
/// @param intlist 
/// @return 
double compute_vector_average(std::vector<int> const& intlist);

/// @brief This function takes in the address of a student struct and computes the total class score.
/// @param student 
/// @return a double containing the total class score of the user.
double compute_total_class_score(student* student);

/// Utility Functions

/// @brief This function will return the average of the values in the vector array of ints.
/// @param student The student to compute average homewwork grade
double compute_student_average_homework(student* student);

/// @brief This function will print to STDOUT the student with their grades and their total computed grade.
/// @param student 
void print_student(student* student);



#endif