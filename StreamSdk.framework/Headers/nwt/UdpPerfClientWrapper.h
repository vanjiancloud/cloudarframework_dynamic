// Copyright (c) 2014-2016, NVIDIA CORPORATION.  All rights reserved.
//
// NVIDIA CORPORATION and its licensors retain all intellectual property
// and proprietary rights in and to this software, related documentation
// and any modifications thereto.  Any use, reproduction, disclosure or
// distribution of this software and related documentation without an express
// license agreement from NVIDIA CORPORATION is strictly prohibited.


#pragma once

#include <stdint.h>
#include <stdlib.h>
#include <string>

#define PROFILE_NAME_LEN 20

// \brief Struct representing connection test info.
typedef struct NwtCapabilityInfo_t
{
    char profileName [PROFILE_NAME_LEN];
    uint32_t bandwidth;               // Measured bandwidth in b/s
    uint64_t latency;                 // Measured latency ms (UDP RTT)
    double   frameLoss;               // Measured how many frames were lost/dropped in %
    uint32_t frameJitter;             // The 99th percentile of the measured jitter with the concept of frames in ms


    // The following values are the thresholds that the test uses in determining whether clients are capable of streaming
    // They are outputs from the test as they are communicated by the associated server
    // The 'Limit' values are the thresholds we use to determine if we should gate clients from streaming
    // The 'Recommended' values are the thresholds for which we advertise would deliver an optimal streaming experience

    uint32_t bandwidthLimit;          // Minimum tolerable bandwidth required for streaming in b/s
    uint32_t bandwidthRecommended;    // Recommended bandwidth for streaming in b/s
    uint64_t latencyLimit;            // Maximum tolerable (UDP RTT) latency required for streaming in ms
    uint64_t latencyRecommended;      // Recommended latency for streaming in ms
    double   frameLossLimit;          // Maximum tolerable frame loss required for streaming expressed as a %
    double   frameLossRecommended;    // Recommended frame loss for streaming expressed as a %
    uint32_t frameJitterLimit;        // Maximum tolerable 99th percentile frame jitter required for streaming in ms %
    uint32_t frameJitterRecommended;  // Recommended 99th percentile frame jitter for streaming in ms
} NwtCapabilityInfo;

typedef struct NwtStreamProfiles_t
{
    NwtStreamProfiles_t() : profileMask(0), bitrateList(""), durationList("") { }
    uint32_t profileMask;
    std::string bitrateList;
    std::string durationList;
} NwtStreamProfiles;

// \brief Result codes for functions in UdpPerfClientWrapper.
typedef enum NwtResult_t
{
    NWT_R_SUCCESS = 0,
    NWT_R_ERROR,
    NWT_R_INVALID_PARAM,             // Invalid parameter error
    NWT_R_UNINITIALIZED,             // Network tester uninitialized error
    NWT_R_INITIALIZE_ERROR,          // Initialization error
    NWT_R_LOCAL_ENDPOINT_ERROR,      // Error in retrieving the local endpoint
    NWT_R_EXTERNAL_ENDPOINT_ERROR,   // Error in retrieving the external endpoint
    NWT_R_PINGPONG_ERROR,            // Error in ping-pong
    NWT_R_STREAMING_ERROR,           // Error in streaming
} NwtResult;

// \brief Network tester callback data type.
typedef enum NwtCallbackDataType_t
{
    NWT_TYPE_ERROR = 1,              // Error while running network test
    NWT_TYPE_BANDWIDTH_ESTIMATE,     // Bandwidth estimate result
    NWT_TYPE_HOLEPUNCH_RESULT,       // Hole punch result
    NWT_TYPE_NETWORKTEST_RESULT,     // Network test result
}NwtCallbackDataType;

// \brief Network tester callback data.
typedef struct NwtCallbackData_t
{
    NwtCallbackDataType type;                 // Type of callback
    union Data_t
    {
        NwtResult         result;             // If type is NWT_TYPE_ERROR, this field will have the error
                                              // If type is NWT_TYPE_HOLEPUNCH_RESULT, this field will indicate whether hole punch passed/failed
        NwtCapabilityInfo nwtCapabilityInfo;  // If type is NWT_TYPE_NETWORKTEST_RESULT, this field will have the network test result
    } Data;
    NwtStreamProfiles profiles;
} NwtCallbackData;

// \brief Network tester callback function pointer
// \param - void            *userContext : User context
// \param - NwtCallbackData &data        : Callback data
typedef void NetworkTesterCallback_t(void*, const NwtCallbackData&);

// Forward declaration
class UdpPerfClient;

//
// \brief Network Tester Client Class
// Usage:
//     initialize(networkTesterCb, cbContext);                \\Initialize network tester on client
//     getClientEndpoints(localEndpoint, localEndpointSize,
//                 externalEndpoint, externalEndpointSize);   \\Get local and external client endpoints
//
//     Provide the client endpoint(local/external depending
//     on whether it is local or external roaming) to the
//     server via the network test init request.
//     https://<serverip>:<serverport>/networktest?uniqueid=<uniqueID>&command=init&udpport=<clientNetworkTestingPort>
//         &clientip=<clientIP>                               \\Initialize network tester on server
//
//     Extract the authToken, serverIP and serverPortList from the network test init response.
//     The authToken should be sent along with the start and stop network test request to the server.
//
//     start(serverIP, serverPortList, serverPostListLength); \\Start network tester on the client, this is an asynchronous call
//
//     estimatedBandwidth is supplied to the client via NetworkTesterCallback_t.
//
//     Provide the estimatedBandwidth to the server via the network test start request.
//     https://<serverip>:<serverport>/networktest?uniqueid=<uniqueID>&command=start&udpport=<clientNetworkTestingPort>
//         &clientip=<clientIP>&authtoken=<authToken>
//         &bandwidth=<estimatedBandwidth>                    \\Start network tester on the server
//
//     After network testing is done the results are supplied to the client via NetworkTesterCallback_t.
//     uninitialize();                                        \\Uninitialize the Network Tester on the client.
//
//     Note:
//         getResults() function can be used to get the network test results.
//         stop() function on the client and/or sending a stop network test request to the server can be used to stop the network testing.
//         server stop request : https://<serverip>:<serverport>/networktest?uniqueid=<uniqueID>&command=stop&udpport=<clientNetworkTestingPort>
//                                   &clientip=<clientIP>&authtoken=<authToken>
//         The appropriate authentication information(certificate/sessionID) should be provided with all requests to the server.
class UdpPerfClientWrapper
{
public:
    UdpPerfClientWrapper();
    ~UdpPerfClientWrapper();

    // \brief Initialize the network tester
    // \param - networkTesterCb : Callback function pointer. Will be called on error or info
    // \param - cbContext       : Callback data
    // \return
    // NWT_R_INITIALIZE_ERROR - initializing network tester failed
    // NWT_R_SUCCESS          - initialize succeeded
    // \remarks
    // This function should be used to initialize the client side network tester
    NwtResult initialize(NetworkTesterCallback_t* networkTesterCb, void* cbContext);

    // \brief Getter for external client endpoints
    // \param - externalEndpoint     : Output parameter which contains the client external endpoint
    // \param - externalEndpointSize : Size of externalEndpoint
    // \return
    // NWT_R_UNINITIALIZED           - network tester not initialize
    // NWT_R_INVALID_PARAM           - localEndpoint or externalEndpoint is NULL
    // NWT_R_EXTERNAL_ENDPOINT_ERROR - error in getting the external endpoint
    // NWT_R_LOCAL_ENDPOINT_ERROR    - error in getting the local endpoint
    // NWT_R_SUCCESS                 - getting client endpoints succeeded
    // \remarks
    // This function should be used to get the external client endpoints
    // For local scenario the client should provide its local endpoint to the server in networktest init/start/stop request
    // For roaming scenario the client should provide its external endpoint to the server in networktest init/start/stop request
    NwtResult getClientEndpoints(char* externalEndpoint, size_t externalEndpointSize);

    // \brief Getter for local port used
    int getLocalPort();

    // \brief Starts network tester
    // \param - serverCandidates     : Server against which network has to be tested
    // \return
    // NWT_R_UNINITIALIZED - network tester not initialize
    // NWT_R_SUCCESS       - starting network tester succeeded
    // \remarks
    // This function should be called to start the client side network tester. This is an asynchronous call
    // This function calculates the estimated bandwidth. This bandwidth is provided via the NetworkTesterCallback_t
    // The client should send this bandwidth estimate to the server in the networktest start request
    // After the network testing is over the results are provided to the client via the NetworkTesterCallback_t
    NwtResult start(const std::string& serverCandidates);

    // \brief Stops network tester
    // \return
    // NWT_R_UNINITIALIZED - network tester not initialize
    // NWT_R_ERROR         - error in stopping network tester
    // NWT_R_SUCCESS       - stopping network tester succeeded
    // \remarks
    // This function can be used to stop the client side network tester
    NwtResult stop();

    // \brief Getter of network testing results
    // \param - baseNetworkCapabilityInfo : Output parameter which contains the network testing results
    // \return
    // NWT_R_UNINITIALIZED - network tester not initialize
    // NWT_R_INVALID_PARAM - baseNetworkCapabilityInfo is NULL
    // NWT_R_ERROR         - error in getting network testing results
    // NWT_R_SUCCESS       - getting network tester result succeeded
    // \remarks
    // This function can be used to get the network test results
    NwtResult getResult(NwtCapabilityInfo* nwtCapabilityInfo);

    // \brief Uninitializes network tester
    // \return
    //  User Context
    // \remarks
    // This function can be used to uninitialize the client side network tester
    void* uninitialize();

private:
    bool                     m_initialized;   // Indicates whether network tester is initialized
    UdpPerfClient*           m_UdpPerfClient; // Pointer to UdpPerfClient
    NetworkTesterCallback_t* m_infoCallback;  // Network tester info callback
    void*                    m_userContext;   // callback context

    // disallow copy constructor and assignment operator
    UdpPerfClientWrapper( const UdpPerfClientWrapper & );
    UdpPerfClientWrapper &operator=( const UdpPerfClientWrapper & );
};
