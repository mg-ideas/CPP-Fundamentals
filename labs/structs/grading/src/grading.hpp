#pragma once

using ui = unsigned int;

struct Grading
{
    ui a;
    ui b;
    ui c;
    ui d;
    ui e;
    ui exam_score;
    char final_grade;
};
char find_grade(const Grading &);
