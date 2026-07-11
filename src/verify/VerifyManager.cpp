#include "verify/VerifyManager.hpp"

#include <iostream>

#include "verify/VerifyEngine.hpp"

void VerifyManager::start(
    const Device& device)
{
    std::cout
        << "\n=================================\n";

    std::cout
        << " Verification\n";

    std::cout
        << "=================================\n\n";

    std::cout
        << "Selected Device\n\n";

    std::cout
        << device.model
        << "\n";

    std::cout
        << device.path
        << "\n\n";

    VerifyEngine engine;

    VerifyResult result =
        engine.verify(device);

    std::cout
        << "Status            : "
        << (result.success ? "PASS" : "FAIL")
        << "\n";

    std::cout
        << "Verified          : "
        << result.verifiedPercent
        << "%\n";

    std::cout
        << "Message           : "
        << result.message
        << "\n";

    std::cout
        << "Details           : "
        << result.details
        << "\n";
}