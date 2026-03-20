#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../doctest/doctest.h"
#include "../src/grading.hpp"

TEST_CASE("Test grading")
{
    SUBCASE("Test grade A")
    {
        Grading g1{90, 80, 70, 60, 50, 95};
        CHECK(find_grade(g1) == 'A');
    }

    SUBCASE("Test grade B")
    {
        Grading g2{90, 80, 70, 60, 50, 80};
        CHECK(find_grade(g2) == 'B');
    }

    SUBCASE("Test grade C")
    {
        Grading g3{90, 80, 70, 60, 50, 70};
        CHECK(find_grade(g3) == 'C');
    }

    // FIXME - add more test cases for D, E and F grades
}