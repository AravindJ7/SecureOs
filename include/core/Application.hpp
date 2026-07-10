#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <vector>

#include "device/Device.hpp"

class Application
{
public:

    void run();

private:

    std::vector<Device> devices;

    Device selectedDevice;

    bool deviceSelected = false;

    void initialize();

    void scanDevices();

    void selectDevice();

    void showDeviceHealth();

    void eraseDevice();

    void shutdown();
};

#endif