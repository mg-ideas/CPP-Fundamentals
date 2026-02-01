#include "dig.h"

double dig::calculate_rate_per_worker(int n_workers, int h_hours, int x_cubic_meters)
{
    return static_cast<double>(x_cubic_meters) / (n_workers * h_hours);
}

double dig::calculate_time_needed(int m_workers, double rate_per_worker, int y_cubic_meters)
{
    return 0.0; // FIXME11: implement the function to calculate time needed
}