#pragma once

using ui = unsigned int;

struct Grading
{
    ui a; // grading criteria for A grade
    ui b; // grading criteria for B grade
    ui c; // grading criteria for C grade
    ui d; // grading criteria for D grade
    ui e; // grading criteria for E grade
    ui exam_score;
    // constant member function to find and return final grade based on grading criteria and exam score
    char find_grade() const;
};
