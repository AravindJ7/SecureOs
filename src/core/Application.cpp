#include "core/Application.hpp"
#include "erase/EraseManager.hpp"
#include <iostream>
#include "verify/VerifyManager.hpp"

#include "device/DeviceManager.hpp"
#include "health/HealthManager.hpp"

void Application::run()
{
initialize();

scanDevices();

selectDevice();

showMainMenu();

shutdown();
}

void Application::initialize()
{
    std::cout
        << "=================================\n";

    std::cout
        << " SecureEraseOS v0.2\n";

    std::cout
        << "=================================\n\n";
}

void Application::scanDevices()
{
    std::cout
        << "Scanning storage devices...\n\n";

    DeviceManager manager;

     devices =
        manager.scanDevices();

    for(const auto& device : devices)
    {
        device.printInfo();

        std::cout << "\n";
    }
}

void Application::showDeviceHealth()
{
    std::cout
        << "=================================\n";

    std::cout
        << " Device Health\n";

    std::cout
        << "=================================\n\n";

    HealthManager manager;

    
    if(!deviceSelected)
    {
        std::cout
        << "\nNo device selected.\n";

        return;
    }

SMARTInfo info =
    manager.readHealth(
        selectedDevice.path);

    std::cout
        << "Temperature      : "
        << info.temperature
        << " C\n";

    std::cout
        << "Available Spare  : "
        << info.availableSpare
        << " %\n";

    std::cout
        << "Percentage Used  : "
        << info.percentageUsed
        << " %\n";

    std::cout
        << "Power Cycles     : "
        << info.powerCycles
        << "\n";

    std::cout
        << "Power On Hours   : "
        << info.powerOnHours
        << "\n";

    std::cout
        << "Unsafe Shutdowns : "
        << info.unsafeShutdowns
        << "\n";

    std::cout
        << "Media Errors     : "
        << info.mediaErrors
        << "\n\n";
}

void Application::shutdown()
{
    std::cout
        << "Application Finished.\n";
}
void Application::selectDevice()
{
    if(devices.empty())
    {
        std::cout
            << "\nNo storage devices found.\n";

        return;
    }

    std::cout
        << "\n=================================\n";

    std::cout
        << " Select Device\n";

    std::cout
        << "=================================\n\n";

    for(size_t i = 0; i < devices.size(); i++)
    {
        std::cout
            << i + 1
            << ". "
            << devices[i].model
            << " ("
            << devices[i].path
            << ")\n";
    }

    std::cout
        << "\nChoice : ";

    int choice;

    std::cin >> choice;

    if(choice < 1 || choice > static_cast<int>(devices.size()))
    {
        std::cout
            << "\nInvalid Selection\n";

        return;
    }

    selectedDevice =
        devices[choice - 1];

    deviceSelected = true;

    std::cout
        << "\nSelected : "
        << selectedDevice.model
        << "\n";
}
void Application::showMainMenu()
{
    while(true)
    {
        int choice;

        std::cout
            << "\n=================================\n";

        std::cout
            << " SecureEraseOS Main Menu\n";

        std::cout
            << "=================================\n\n";

        std::cout
            << "Current Device : "
            << selectedDevice.model
            << "\n\n";

        std::cout
            << "1. Device Information\n";
        std::cout
            << "2. Device Health\n";
        std::cout
            << "3. Secure Erase\n";
        std::cout
            << "4. Verify Erase\n";
        std::cout
            << "5. Generate Report\n";
        std::cout
            << "6. Change Device\n";
        std::cout
            << "7. Exit\n\n";

        std::cout
            << "Choice : ";

        std::cin >> choice;

        switch(choice)
        {
            case 1:
                deviceInformation();
                break;

            case 2:
                showDeviceHealth();
                break;

            case 3:
                eraseDevice();
                break;

            case 4:
                verifyErase();
                break;

            case 5:
                generateReport();
                break;

            case 6:
                changeDevice();
                break;

            case 7:
                return;

            default:
                std::cout
                    << "\nInvalid option.\n";
        }
    }
}
void Application::deviceInformation()
{
    std::cout << "\n";
    selectedDevice.printInfo();
    std::cout << "\n";
}

void Application::eraseDevice()
{
    EraseManager manager;

    manager.start(selectedDevice);
}

void Application::verifyErase()
{
    if(!deviceSelected)
    {
        std::cout
            << "\nNo device selected.\n";

        return;
    }

    VerifyManager manager;

    manager.start(selectedDevice);
}

void Application::generateReport()
{
    std::cout
        << "\nGenerate Report (Coming Soon)\n";
}

void Application::changeDevice()
{
    selectDevice();
}