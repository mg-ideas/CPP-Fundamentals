#include "grading.hpp"

char Grading::find_grade() const
{
    if (this->exam_score >= this->a)
        return 'A';
    else if (this->exam_score >= this->b)
        return 'B';
    else
        return 'F';
    // FIXME - add remaining grading rules
}