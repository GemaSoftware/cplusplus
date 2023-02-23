#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest/doctest.h"
#include "week5.h"

TEST_CASE("Student Application Test"){
    //init students
    student student1;
    student student2;
    student student3;

    //init the vectors
    //Can use these vectors later when testing other modules.
    std::vector<int> hw_grades_1;
    hw_grades_1.push_back(0);

    std::vector<int> hw_grades_2;
    hw_grades_2.push_back(100);
    hw_grades_2.push_back(100);
    hw_grades_2.push_back(100);
    
    std::vector<int> hw_grades_3;
    hw_grades_3.push_back(50);
    hw_grades_3.push_back(75);
    hw_grades_3.push_back(80);

    //Create the students
    create_student(&student1, 0, "Test", 50, 75, hw_grades_1);
    create_student(&student2, 1, "Agron", 100, 100, hw_grades_2);
    create_student(&student3, 2, "John", 60, 93, hw_grades_3);
    CHECK(student1.id == 0);
    CHECK(student2.id == 1);
    CHECK(student3.id == 2);

    //test the getters/setters
    student student4;
    create_student(&student4, 3, "Test", 50, 75, hw_grades_1);
    CHECK(get_student_midterm(&student1) == 50);
    CHECK(get_student_midterm(&student2) == 100);
    CHECK(get_student_midterm(&student3) == 60);
    CHECK(get_student_midterm(&student4) == 50);
    set_student_midterm(&student4, 65);
    CHECK(get_student_midterm(&student4) == 65);
    

    //test average homework scores
    CHECK(compute_student_average_homework(&student1) == 0.0);
    CHECK(compute_student_average_homework(&student2) == 100.0);
    CHECK(compute_student_average_homework(&student3) == doctest::Approx(68.333));

    //test size of hw grades arrays
    CHECK(student1.hw_grades.size() == 1);
    CHECK(student2.hw_grades.size() == 3);
    CHECK(student3.hw_grades.size() == 3);

    //test the total class score.
    CHECK(compute_total_class_score(&student1) == doctest::Approx(37.5));
    CHECK(compute_total_class_score(&student2) == doctest::Approx(100.0));
    CHECK(compute_total_class_score(&student3) == doctest::Approx(73.2333)); // 18 + 27.9 + 27.3 = 73.2333

    
};
