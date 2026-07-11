#ifndef VERIFY_ENGINE_HPP
#define VERIFY_ENGINE_HPP

#include "device/Device.hpp"
#include "verify/VerifyResult.hpp"

class VerifyEngine
{
public:

    VerifyResult verify(
        const Device& device);
};

#endif