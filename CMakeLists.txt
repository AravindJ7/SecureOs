cmake_minimum_required(VERSION 3.16)

project(SecureEraseOS)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(
    secureos

    # ==========================
    # Core
    # ==========================
    src/main.cpp
    src/core/Application.cpp

    # ==========================
    # Device
    # ==========================
    src/device/Device.cpp
    src/device/DeviceManager.cpp
    src/device/DeviceScanner.cpp
    src/device/DeviceInfoReader.cpp
    src/device/DeviceClassifier.cpp
    src/device/TransportDetector.cpp

    # ==========================
    # Health
    # ==========================
    src/health/SMARTInfo.cpp
    src/health/SMARTReader.cpp
    src/health/SMARTParser.cpp
    src/health/HealthManager.cpp

    # ==========================
    # Executor
    # ==========================
    src/executor/CommandResult.cpp
    src/executor/CommandRunner.cpp

    # ==========================
    # Erase
    # ==========================
    src/erase/EraseMethod.cpp
    src/erase/EraseExecutor.cpp
    src/erase/EraseManager.cpp

    # ==========================
    # Verify
    # ==========================
    src/verify/VerifyResult.cpp
    src/verify/VerifyEngine.cpp
    src/verify/VerifyManager.cpp
)