#include "grading.hpp"

char find_grade(const Grading &g)
{
    if (g.exam_score >= g.a)
        return 'A';
    else if (g.exam_score >= g.b)
        return 'B';
    else
        return 'F';
    // FIXME - add remaining grading rules
}