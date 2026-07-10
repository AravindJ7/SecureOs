cmake_minimum_required(VERSION 3.16)

project(SecureEraseOS)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(
    secureos
    src/device/DeviceInfoReader.cpp
    src/erase/EraseManager.cpp
    src/device/TransportDetector.cpp
    src/health/SMARTInfo.cpp
    src/health/SMARTReader.cpp
    src/erase/EraseMethod.cpp
    src/erase/EraseExecutor.cpp
    src/device/Device.cpp
    src/health/SMARTParser.cpp
    src/health/HealthManager.cpp
    src/device/DeviceClassifier.cpp
    src/device/DeviceManager.cpp
    src/device/DeviceScanner.cpp
    src/main.cpp
    src/core/Application.cpp
)