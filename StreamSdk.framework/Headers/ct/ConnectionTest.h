// Copyright (c) 2016-2022, NVIDIA CORPORATION.  All rights reserved.
//
// NVIDIA CORPORATION and its licensors retain all intellectual property
// and proprietary rights in and to this software, related documentation
// and any modifications thereto.  Any use, reproduction, disclosure or
// distribution of this software and related documentation without an express
// license agreement from NVIDIA CORPORATION is strictly prohibited.

#pragma once

#include <base/MjolnirDefines.h>
#include <base/NvNetworkClasses.h>
#include <base/NvThreadingClasses.h>
#include <util/CompilerHelpers.h>
#include <atomic>
#include <vector>
#include <string>

class ConnectionTest : public CNvThread
{
public:
    ConnectionTest();
    ~ConnectionTest();

    bool Initialize();
    bool Run(std::string serverCandidates);
    void Stop();

    bool GetLocalAddress(std::string& localAddress);
    bool GetExternalEndpoint(std::string& externalEndpoint);
    std::string GetSuccessIp();

private:
    bool mSucceeded;
    uint16_t mLocalPort;

    CNvMutex mMutex;
    NV_DIAGNOSTIC_PUSH
    NV_DIAGNOSTIC_IGNORE_DEPRECATED
    CNvTimer mStopTimer;
    NV_DIAGNOSTIC_POP
    std::atomic_bool mStop {false};
    NvSocketUdp mSocket;
    NvSocketAddress mExternalEndpoint;
    std::vector<NvSocketAddress> mLocalAddress;
    std::vector<NvSocketAddress> mServerCandidates;

    bool mUniDirectionalHolepunch;
    std::string mSuccessIp;

    void ThreadFunc();
    void RunHolePunching(const char *data, uint16_t length);
    bool ValidateServerCandidate(const NvSocketAddress& serverCandidate);

    static bool StopTimerFunc(void* pData);
    static std::string AddressVectorToString(const std::vector<NvSocketAddress>& addressVector);
};
