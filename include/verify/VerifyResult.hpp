#ifndef VERIFY_RESULT_HPP
#define VERIFY_RESULT_HPP

#include <string>

class VerifyResult
{
public:

    bool success;

    double verifiedPercent;

    std::string message;

    std::string details;

public:

    VerifyResult();
};

#endif