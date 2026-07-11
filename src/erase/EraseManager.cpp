#include "erase/EraseManager.hpp"

#include <iostream>

#include "erase/EraseExecutor.hpp"
#include "erase/EraseMethod.hpp"

void EraseManager::start(const Device& device)
{
    std::cout
        << "\n=================================\n";

    std::cout
        << " Secure Erase\n";

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

    EraseMethod method =
        EraseMethod::NONE;

    if(device.type == DeviceType::NVME_SSD)
    {
        std::cout
            << "1. NVMe Sanitize\n";

        std::cout
            << "2. NVMe Format\n";

        std::cout
            << "3. Cancel\n\n";

        int choice;

        std::cout
            << "Choice : ";

        std::cin >> choice;

        if(choice == 1)
            method = EraseMethod::NVME_SANITIZE;

        else if(choice == 2)
            method = EraseMethod::NVME_FORMAT;

        else
            return;
    }
    else if(device.type == DeviceType::HDD)
    {
        std::cout
            << "1. Software Overwrite\n";

        std::cout
            << "2. Cancel\n\n";

        int choice;

        std::cout
            << "Choice : ";

        std::cin >> choice;

        if(choice == 1)
            method = EraseMethod::SOFTWARE_OVERWRITE;

        else
            return;
    }
    else
    {
        std::cout
            << "No erase method available.\n";

        return;
    }

    std::string confirm;

    std::cout
        << "\nWARNING!\n";

    std::cout
        << "All data will be destroyed.\n";

    std::cout
        << "Type YES to continue : ";

    std::cin
        >> confirm;

    if(confirm != "YES")
    {
        std::cout
            << "\nCancelled.\n";

        return;
    }

    EraseExecutor executor;


    CommandResult result =
    executor.preview(
        device,
        method);

std::cout
    << "\n"
    << result.output
    << "\n";

    std::cout
    << "\nPreview completed successfully.\n";
}