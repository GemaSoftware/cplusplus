#include "week5.h"
using namespace std;

int main(int argc, char** argv){
    student student;
    create_student_cli(&student);
    print_student(&student);
}