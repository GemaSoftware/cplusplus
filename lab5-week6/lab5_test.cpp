#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest/doctest.h"
#include "lab5.h"

TEST_CASE("Testing LAB5 Functions"){
    double_vector v1{1, 1.5, 3.0};
    double_vector v2{2, 2.1, 7.6};
    double_vector v3{3, 3.0, 4.0};

    SUBCASE("Testing input edge case - empty file"){
        //file name of blank is blank_vectors.txt
        CHECK_THROWS(read_vectors("vectors/blank_vectors.txt"));
    }

    SUBCASE("Testing magnitude calculations"){
        CHECK(vec_magnitude(v1) == doctest::Approx(3.3541)); //sqrt(1.5^2 + 3.0^2)
        CHECK(vec_magnitude(v2) == doctest::Approx(7.8848)); //sqrt(2.1^2 + 7.6&2)
        CHECK(vec_magnitude(v3) == doctest::Approx(5.0)); //sqrt(25)
    };

    SUBCASE("Testing dot product"){
        CHECK(dot_product_vec(v1, v2) == doctest::Approx(25.95));
        CHECK(dot_product_vec(v1, v3) == doctest::Approx(16.5));
        CHECK(dot_product_vec(v2, v3) == doctest::Approx(36.7));
    };

    SUBCASE("Testing cosign angle"){
        CHECK(calc_theta_distance(v1, v2) == doctest::Approx(0.194059));//2
        CHECK(calc_theta_distance(v1, v3) == doctest::Approx(0.179853));//1
        CHECK(calc_theta_distance(v2, v3) == doctest::Approx(0.373912));//3
    }

    SUBCASE("TESTING SORT/SWAP"){
        pair_vector p1{v1, v2, calc_theta_distance(v1, v2)};
        pair_vector p2{v1, v3, calc_theta_distance(v1, v3)};
        pair_vector p3{v2, v3, calc_theta_distance(v2, v3)};

        std::vector<pair_vector> listofVectors;
        listofVectors.push_back(p1);
        listofVectors.push_back(p2);
        listofVectors.push_back(p3);
        sort_pairwise_vectors(listofVectors);
        ///check cos dist sorted.
        CHECK(listofVectors[0].cos_dist < listofVectors[1].cos_dist);
        CHECK(listofVectors[0].cos_dist < listofVectors[2].cos_dist);
        CHECK(listofVectors[1].cos_dist < listofVectors[2].cos_dist);
        ///check pairvise vectors are correct (v1->v3), (v1->v2), (v2->v3)
        CHECK(listofVectors[0].v1.id == v1.id);
        CHECK(listofVectors[0].v2.id == v3.id);

        CHECK(listofVectors[1].v1.id == v1.id);
        CHECK(listofVectors[1].v2.id == v2.id);
        
        CHECK(listofVectors[2].v1.id == v2.id);
        CHECK(listofVectors[2].v2.id == v3.id);
    }
   
}