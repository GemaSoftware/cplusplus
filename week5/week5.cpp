#include "week5.h"

void print_student(student* student)
{
    using namespace std;
    cout << endl;
    printf("%s recieved a %d on their midterm and a %d on their final.\n", student->name.c_str(), student->midtermGrade, student->finalGrade);
    printf("Their average homework grade was a %.2f.\n", compute_student_average_homework(student));
    printf("%s's Final class grade: %.2f\n", student->name.c_str(), compute_total_class_score(student));
}

double compute_total_class_score(student* student)
{
    double x = compute_student_average_homework(student);
    return 0.3*student->midtermGrade + 0.3*student->finalGrade + 0.4*x;
}

double compute_student_average_homework(student* student)
{
    return compute_vector_average(student->hw_grades);
}

double compute_vector_average(std::vector<int> const& intlist){
    double hw_average = 0.0;
    for(auto x : intlist){
        hw_average += x;
    }
    hw_average = hw_average / intlist.size();

    return hw_average;
}



