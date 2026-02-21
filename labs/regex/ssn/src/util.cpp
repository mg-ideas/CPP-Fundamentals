#include <string>
#include <regex>
#include "../includes/util.hpp"

std::string util::find_email(const std::string &text)
{
    std::regex email_regex("[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}");
    std::smatch email_match;
    if (std::regex_search(text, email_match, email_regex))
    {
        return email_match.str();
    }
    return "";
}

std::string util::find_social(const std::string &text)
{
    std::regex social_regex("\\d{3}-\\d{2}-\\d{4}");
    std::smatch social_match;
    if (std::regex_search(text, social_match, social_regex))
    {
        return social_match.str();
    }
    return "";
}

// FIXME - add function definition for find_credit_card function