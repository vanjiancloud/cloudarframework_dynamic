// Copyright (c) 2013-2020, NVIDIA CORPORATION.  All rights reserved.
//
// NVIDIA CORPORATION and its licensors retain all intellectual property
// and proprietary rights in and to this software, related documentation
// and any modifications thereto.  Any use, reproduction, disclosure or
// distribution of this software and related documentation without an express
// license agreement from NVIDIA CORPORATION is strictly prohibited.

/*!
 * THIS IS AUTOMATICALLY GENERATED FILE. DO NOT EDIT.
 * For any modifications, refer NvscClientConfig.xml
 */

#pragma once

#include <nvst/client/AudioRenderer.h>
#include <nvst/client/ClientTypes.h>
#include <nvst/common/SharedTypes.h>
#include <nvst/common/VideoFormat.h>
#include <nvst/common/StreamConfig.h>
#include <nvst/common/StreamInternal.h>
#include <nvst/common/StreamConstants.h>
template <typename T>
struct MetaParams
{
    T min;
    T max;
};

/// Updates on how to enable packet pacing.
typedef enum NvscPacketPacingMode_t
{
    DISABLE_PACKET_PACING = 0,///< Disable packet pacing.
    ENABLE_DYNAMIC_PACKET_PACING = 1,///< Enable packet pacing dynamically.
    FORCE_ENABLE_PACKET_PACING = 2,///< User forced to enable the packet pacing from start of a session.
}NvscPacketPacingMode;


typedef struct NvscPacketPacing_t
{

    uint8_t version;///< Version of the dynamic packet pacing implementation.
    NvscPacketPacingMode mode;///< Specified packet pacing mode

    uint8_t allowFpsBasedToggle;///< Allow dynamic packet pacing toggle based on current streaming FPS.

    uint16_t numGroups;///< The number of groups that a video frame is divided for sending when packet pacing is enabled.

    uint8_t maxTagetGroupCount;///< The maximum number of target group count that can be configured while adjusting the packet pacing config dynamically.

    uint16_t minNumPacketsPerGroup;///< The minimum number of packets per group when packet pacing is enabled.

    uint16_t maxDelayUs;///< The maximum delay in micro seconds that is added to a group of packets after numGroupedPackets in packet pacing are sent in the same video frame.

    uint16_t minNumPacketsFrame;///< The minimum number of packets frame that is required to apply the packet pacing.

    uint8_t minTagetPacketBurst;///< The minimum number of target packet burst that can be configured while adjusting the packet pacing config dynamically.

    uint32_t lossyFramePercMonitorTimeWindowMs;///< The lossy frame percentage monitor time window for enabling the packet pacing dynamically.

    uint16_t lossyFramePercThreshold;///< The lossy frame percentage threshold used for enabling the packet pacing dynamically.

    uint16_t packetLossPercThreshold;///< The packet loss percentage threshold used for enabling the packet pacing dynamically.

    uint16_t enableSmoothTransition;///< The flag controls packet pacing algorithm to allow smooth transition of packet pacing.

    uint16_t pacingToggleFpsLower;///< When packet pacing toggle based on FPS enabled, current FPS must be below this threshold to consider enabling packet pacing.

    uint16_t pacingToggleFpsUpper;///< When packet pacing toggle based on FPS enabled, current FPS must exceed this threshold to consider disabling packet pacing.
}NvscPacketPacing;


typedef struct NvscClientPerfBrControl_t
{

    uint8_t enable;///< Disable client perf bitrate control by default.

    uint8_t decodeAdjPercent;///< Adjustment factor for the client's decoder performance estimate.  Set to 0 to ignore this client estimate.

    uint8_t renderAdjPercent;///< Adjustment factor for the client's render performance estimate.  Set to 0 to ignore this client estimate.

    uint8_t stepPercent;///< Percentage of current bitrate to decrease if client performance is bad.

    uint32_t coolDownPeriodInMs;///< Minimum time between bitrate decreases.
}NvscClientPerfBrControl;


typedef struct NvscBWEstimator_t
{

    uint32_t iirFilterFactor;

    uint8_t slowIirFilterFactor;

    uint32_t owdSlidingWindowLengthInFrames;

    uint32_t minWaitToSendBWEtoServerInFrames;

    uint32_t rateLimitTriggerRatio;///< Qos rate limit is triggered when avgBitRate exceeds this threshold.

    uint32_t rateLimitRatio;///< The avg bitRate is limited to the percentage of BWE reported by client

    uint8_t bwuSafeZoneLowLimit;///< Bandwidth utilization safe zone lower limit. Qos bitrate is not increased in safe zone.

    uint32_t rateLimitUtilizationTriggerRatio;///< Qos rate limit is triggered when utilization exceeds this threshold.

    uint32_t newQosConvergenceRate;///< This controls the step size which is used to converge to estimated BW.

    uint16_t stepUpLimitPercent;///< The maximum increase step size based on percentage of current streaming bitrate in 100 percent.

    uint8_t maxStepUpPercent;///< The maximum increase step size based on percentage of initial streaming bitrate in 100 percent.

    uint16_t stepDownPercent;///< The down step size for Qos bitrate in 100 percent.

    uint8_t lossyFrameStepDownRatio;///< Represents the ratio of default Qos bitrate down step size used during lossy frame.

    uint16_t lossyFrameBitrateDropThreshold;///< The lossy frame threshold used to drop bitrate drop.

    uint16_t lossyFrameHighThreshold;///< The lossy frame threshold used to halt bitrate increase.

    uint16_t lossyFrameLowThreshold;///< The lossy frame threshold used to reduce bitrate stepsize.

    uint16_t packetLossHighThresholdx100;///< The packet loss percent threshold used to drop bitrate.

    uint16_t packetLossLowThresholdx100;///< The packet loss percent lower than threshold is used to increase bitrate. Bitrate increase is skipped for packet loss between low and high threshold

    uint16_t updatesPerSecond;///< The number of times that Qos bitrate can be increased in one second.

    uint8_t fecLimitForBitrateIncrease;///< The threshold for FEC percentage that limits bitrate increase for video stream.

    uint16_t reservedUplinkBandwidthKbps;///< The reserved bandwidth for uplink traffic.

    uint8_t useOwdCongestionControl;///< To enable Frame Rx duration based Bandwidth estimation and ignore OWD, which will be handled on the server Qos.

    uint8_t staticSceneEncUtilThreshold;///< Encoder utilization threshold to identify static scenes and skip bitrate increase. This feature is disabled by default GS 4.24 onward

    uint16_t minimumFrameSizeBytes;///< Minimum frame size to consider frame for BWE.

    uint8_t accountPacketResendBitrateOverhead;///< To enable accounting retransmit bitrate to compute Qos bitrate

    uint8_t packetResendAverageIirFilterFactor;///< IIR filter factor used to compute resend packet count average

    uint16_t minimumFrameRxTimeUs;///< Minimum frame receive time, ensures receive time is not very small value specifically during static scene.

    uint16_t minimumFrameRxTimeCorrectionUs;///< Some clients(Rtc) Rx time reported has milli second precision, correction factor added to compensate for precision loss

    uint8_t useFrameBwu;///< Calculate the bandwidth utilization percentage using frame Rx duration alone without considering the frame one way dealy. Value: 0 - disable, : 1 - enable
}NvscBWEstimator;

/// Updates on how to use audio VBR mode.
typedef enum VbrModes_t
{
    AUDIOBITRATE_VBR_UNSUPPORTED = 0,///< Old client/server.
    AUDIOBITRATE_VBR_ALLOWED = 1,///< Old client/server.
    AUDIOBITRATE_VBR_FORCE_OFF = 2,///< User forced VBR mode off.
    AUDIOBITRATE_VBR_FORCE_ON = 3,///< User forced VBR mode on.
}VbrModes;


typedef struct NvscAudioBitrateSettings_t
{

    uint8_t adaptiveBitrateEnable;

    uint8_t bandwidthUsageLowLimit;

    uint8_t bandwidthUsageHighLimit;

    uint8_t uptickDivisor;

    uint16_t uptickThresholdMs;

    uint16_t local8chMin;

    uint16_t local8chMax;

    uint16_t local6chMin;

    uint16_t local6chMax;

    uint16_t local2chMin;

    uint16_t local2chMax;

    uint16_t remote8chMin;

    uint16_t remote8chMax;

    uint16_t remote6chMin;

    uint16_t remote6chMax;

    uint16_t remote2chMin;

    uint16_t remote2chMax;
    VbrModes VbrMode;///< Specified audio VBR mode
}NvscAudioBitrateSettings;

/// Struct storing details about mic audio settings.
typedef struct NvscMicAudioSettings_t
{

    uint8_t numChannels;///< Number of mic audio channels. Default is 1-channel mono.

    uint16_t channelMask;///< Mic Audio channel bitmask. Default is 1-channel mono.

    uint16_t version;///< Version of the mic audio implementation.

    uint8_t micSetupResultSuccess;///< RTSP setup status of mic audio. Boolean: 0 = not supported, 1 = supported, 2 = supported, but should be deferred.

    uint16_t frameSize;///< Mic packet size in ms

    uint16_t bitrate;///< Mic bitrate

    uint8_t enablePacketizer;///< if true enables Packetizer and disables FEC, if false disables Packetizer and disables FEC

    uint8_t numOfPacketToRetransmit;///< If packetizer is enable this fields configures number of packets that will be retransmitted

    uint8_t useOpusInBandFec;///< If this parameter is set to 1, opus in-band FEC will be used

    uint8_t packetLossRate;///< This param is used to set the packet loss rate (percent) within the opus encoder

    uint16_t opusEncoderMode;///< Set the encode mode: SILK(1000), CELT(1002), or HYBRID(1001)
}NvscMicAudioSettings;


typedef enum AudioApiType_t
{
    API_OPENSLES = 0,///< Force OpenSLES mode.
    API_AAUDIO = 1,///< Force AAudio mode.
}AudioApiType;

/// Struct storing details about Jitter buffer configs.
typedef struct NvscAudioJbSettings_t
{

    uint8_t burstAbsenceDuration;///< Jitter buffer frame burst absence duration in seconds.

    uint8_t thresholdBase;///< Min jitter buffer threshhold base .

    uint8_t maxThreshold;///< Max jitter buffer threshhold

    uint8_t underFlowIncreaseVal;///< Jb threshhold incrementer in underflow
}NvscAudioJbSettings;

/// Struct storing details about surround audio settings.
typedef struct NvscAudioSurroundSettings_t
{

    uint8_t numChannels;///< Number of audio channels. Default is 2-channel stereo.

    uint16_t channelMask;///< Audio channel bitmask. Default is 2-channel stereo (left and right).

    uint8_t enable;///< Whether or not to enable surround audio.

    uint16_t version;///< Version of the surround audio implementation.

    uint16_t AudioQuality;///< Level of Audio Quality
}NvscAudioSurroundSettings;

/// Struct storing details about audio settings.
typedef struct NvscAudioSettings_t
{
    NvscAudioSurroundSettings surround;///< Surround audio settings
    NvscAudioJbSettings jbConfig;///< Jitter Buffer configs

    uint8_t enableNativeBufferImplementation;///< Use this to fetch android supported buffer size and set same in OpenSL ES
    AudioApiType apiType;///< Audio API used in android
}NvscAudioSettings;

/// Available network transfer protocols for bitstream data.
/// \sa NvscServerEndpoint
typedef enum NvscTransferProtocol_t
{
    NVSC_TP_INVALID = -1,///< Not a valid transfer protocol.
    NVSC_TP_TCP,///< TCP transmission.
    NVSC_TP_RTP,///< RTP transmission.
    NVSC_TP_UDP,///< UDP transmission.
    NVSC_TP_WS,///< WS transmission.
    NVSC_TP_WSS,///< WSS transmission.
    NVSC_TP_NUM_PROTOCOLS,///< Not a valid transfer protocol.
}NvscTransferProtocol;

/// Struct storing details about remote input settings.
typedef struct NvscRiSettings_t
{
    NvscTransferProtocol protocol;///< Remote input protocol

    uint8_t usePartiallyReliableUdpChannel;///< Use partially reliable udp channel for remote input

    uint8_t timestampsEnabled;///< Enable timestamps for remote input

    uint8_t useMultipleGamepads;///< Use multiple gamepad format when sending gamepad event to the server.

    uint32_t hidDeviceMask;///< Mask of all HID devices supported by this server.  Value is OR of NvstHidDeviceCapability values.
}NvscRiSettings;

/// Struct storing details about runtime settings
typedef struct NvscRuntimeSettings_t
{

    uint8_t recordClientStats;///< Flag to control client side stats recording

    uint8_t recordServerStats;///< Flag to control server side stats recording

    uint8_t clientNetworkCapture;///< Flag to control client side network capturing

    uint8_t clientTraceCapture;///< Flag to control client side high performance trace capturing

    uint8_t serverNetworkCapture;///< Flag to control server side network capturing

    uint16_t serverTraceCapture;///< Flag to control server side high performance trace capturing

    uint32_t maxVerboseEtlSizeMb;///< Flag to indicate the maximum size of the trace capturing output ETL.

    uint32_t usePresentCompletedConfirmedTimestamp;///< Flag to indicate if present completed confirmed timestamp needs to be used instead of present completed.

    uint8_t mouseCursorCapture;///< Flag to control mouse capture

    uint8_t mimicRemoteCursor;///< Flag to control mimic remote cursor

    uint32_t mouseSettings[NVST_MSI_END];///< Stores mouse motion parameters- [0]: ballistics threshold1, [1]: threshold2, [2]: acceleration value, [3]: speed value

    uint8_t hapticsState;///< Flag to control state of haptics feature

    uint32_t maxVerboseGameEtlSizeMb;///< Flag to indicate the maximum size of the trace capturing game ETL.

    uint8_t audioSrtp;///< Flag to control state of audio encryption over SRTP feature

    uint8_t micSrtp;///< Flag to control state of mic encryption over SRTP feature

    uint8_t videoSrtp;///< Flag to control state of video encryption over SRTP feature

    char encryptionKey[512];///< Encryption key for control, audio, mic and video encryption.

    uint32_t encryptionKeyId;///< Encryption key ID for control, audio, mic and video encryption.

    uint16_t srtpReplayWindowSize;///< SRTP replay window size for replay attack protection.
}NvscRuntimeSettings;

/// Struct storing details about audio qos settings.
typedef struct NvscAudioQosSettings_t
{

    uint8_t enableAudioStats;///< Whether to enable/disable Audio stats 1 - enable 0 - disable

    uint32_t audioStatsUpdateIntervalMs;///< Time (ms) between Audio QOS stats sent to the server.

    uint32_t bitRate;///< Target Audio bitrate in CBR mode.

    uint32_t packetDuration;///< Target Audio Packet Duration in milli sec.

    uint32_t qosTrafficType;///< QoS Traffic type for audio which is used for DSCP setting in a flow.

    uint8_t enableRedundancy;///< Audio stream: whether to enable/disable RFC 2198 redundancy. 1 - enable - 0 disable.

    uint8_t enableRedundancyForMic;///< Mic stream: whether to enable/disable RFC 2198 redundancy. 1 - enable - 0 disable.
}NvscAudioQosSettings;

/// Struct storing details about QoS score settings.
typedef struct NvscQosScore_t
{

    uint16_t networkStatsScoreUpdateTime;///< Time (ms) between network stats quality Score updates sent from the NVST to client

    uint8_t iirFilterFactor;///< This is the IIR filter coefficient used for Qos sciore calculation.

    uint16_t maxLatencyThresholdInMs;///< This is the maximum latency range for qos score calculation. Any latency higher or equal will get minimum score.

    uint8_t minLatencyThresholdInMs;///< This is the minimum latency range for qos score calculation. Any latency less or equal will get best score.

    uint8_t lowBandwidthUtilizationThreshold;///< This is the threshold to determine if network bandwidth is sufficient for current streaming rate.

    uint8_t bwuIirFilterFactor;///< This is the IIR filter coefficient used for smoothening Bandwidth utilization.
}NvscQosScore;

/// Struct storing settings for Stats Processor thread
typedef enum StatsProcessorThreadFlags_t
{
    SPT_DISABLE_ALL = 0x0,///< Disable stats processor thread
    SPT_ENABLE_SA_SCORE_GPU_PERF = 0x01,///< Enables stats processor thread to process GPU Perf score
    SPT_ENABLE_SA_SCORE_SERVER_PERF = 0x02,///< Enables stats processor thread to process Server Perf score
    SPT_ENABLE_SA_SCORE_VISUAL = 0x04,///< Enables stats processor thread to process Visual score
    SPT_ENABLE_SA_SCORE_DECODER = 0x08,///< Enables stats processor thread to process Decoder score
    SPT_ENABLE_SA_SCORE_DOWNLINK_LAG = 0x10,///< Enables stats processor thread to process Downklink Lag score
    SPT_ENABLE_SA_SCORE_DOWNLINK_CONGESTION = 0x20,///< Enables stats processor thread to process Downklink Congestion score
    SPT_ENABLE_SA_SCORE_UPLINK = 0x40,///< Enables stats processor thread to process Uplink score
}StatsProcessorThreadFlags;

/// Struct storing settings for Stats Processor thread
typedef struct StatsProcessorThreadSettings_t
{
    StatsProcessorThreadFlags flags;///< Settings for Stats Processor thread
}StatsProcessorThreadSettings;


typedef struct NvscRtcPreemptiveIdrSettings_t
{

    uint16_t minKeyFrameSendIntervalMs;///< Requests within the interval from last served request are ignored.

    uint16_t minBurstNackSize;///< Minimum number of packets NACK-ed in a single RTCP message to be considered as indicative of bursty loss.

    uint16_t minNackPacketCaptureAgeMs;///< Threshold for the time since capture of the NACK-ed packet to be considered too old.

    uint16_t nackPacketCaptureAgeRttFactor;///< RTT multiplier to be accounted for while calculating NACK packet age.

    uint16_t dropDeltaFramesOnKeyFrameRequest;///< Whether to drop delta frames in the pipeline when the preemptive IDR request is made. Boolean: 0 = No, 1 = Yes.

    uint16_t clearPacketHistoryOnKeyFrameRequest;///< Whether to clear NACK packet history or not on preemptive IDR request. Boolean: 0 = No, 1 = Yes.
}NvscRtcPreemptiveIdrSettings;


typedef enum NvscVqosTacticsManagerMode_t
{
    VQOS_TACTICS_MANAGER_OFF = 0x0,///< Disable Qos Tactics Manager
    VQOS_TACTICS_MANAGER_OBSERVATION_MODE = 0x1,///< Run Qos Tactics Manager in observation-only mode
    VQOS_TACTICS_MANAGER_CONTROL_MODE = 0x2,///< Run Qos Tactics Manager in control mode
}NvscVqosTacticsManagerMode;


typedef struct NvscVqosTacticsManagerSettings_t
{
    NvscVqosTacticsManagerMode mode;///< Flag to specify the mode for running QoS tactics manager

    uint16_t decayFactorX1000;///< Decay factor for signals in tactics manager (x1000 since float values are not supported)

    uint16_t resetInterval;///< Number of frames after which any non-default tactic should get reset

    uint16_t statsBufferSize;///< Number of previous frames for which the ring buffer should store the data

    uint16_t statsWindowSize;///< Number of previous frames for which the stats should be calculated

    uint16_t owdThresholdX1000;///< Threshold for OWD signal in tactics manager (x1000 since float values are not supported)

    uint16_t plThresholdX1000;///< Threshold for packet loss signal in tactics manager (x1000 since float values are not supported)

    uint16_t bweKurtThresholdX1000;///< Threshold for kurtosis of bandwidth estimation in tactics manager (x1000 since float values are not supported)

    uint8_t logging;///< Internal config to enable server-side logging of Qos Tactics calculations
}NvscVqosTacticsManagerSettings;


typedef struct NvscQecSettings_t
{

    uint32_t framesWithInvalidRefThreshold;///< Threshold for number of frames with invalid reference to be sent to decoder specific to QEC algorithm.

    uint32_t consecutiveFrameLostThreshold;///< Number of consecutive frames lost threshold specific to QEC algorithm.

    uint16_t lowDecoderFpsThreshold;///< Threshold for automatic application of QEC skip mode if the decoder FPS is lower than the given value.

    uint16_t multiLossThreshold;///< Threshold for numbers of frames lost after a frame with invalid reference that was recovered.

    uint16_t continuousGoodThreshold;///< Threshold for number of frames with invalid refence that were recovered by QEC.

    uint32_t mvxThreshold;///< Mean motion vector per macro-block in the X direction.

    uint32_t mvyThreshold;///< Mean motion vector per macro-block in the Y direction.

    uint32_t mvxyThreshold;///< Mean motion vector per macro-block in the XY direction.

    uint8_t intraMbPercentageThreshold;///< Threshold for percentage of intra macroblocks within the frame.
}NvscQecSettings;


typedef enum NvscTurboModeOverride_t
{
    NVSC_TURBO_MODE_NO_OVERRIDE = 0,///< Default Turbo Mode selection based on PM and SSAU decisions.
    NVSC_TURBO_MODE_FORCE_ON,///< Force Turbo Mode ON in NvStreamer. SSAU and SOPS still follow default selection logic.
    NVSC_TURBO_MODE_FORCE_OFF,///< Force Turbo Mode OFF in NvStreamer. SSAU and SOPS still follow default selection logic.
}NvscTurboModeOverride;

/// Struct storing settings for controlling the post-processing for RL bitrate model.
typedef struct NvscVqosRlInputPostprocessingSettings_t
{

    uint8_t enableBitrateDownLimitStaticScene;///< Enable limit on bitrate down step for static scenes

    uint8_t enableBitrateUpLimitMaxAvailableBw;///< Enable limit on bitrate up step for max available bandwidth

    uint32_t staticSceneUtilizationThesholdx1000;///< Utilization threshold for static scene

    uint16_t numFramesHighEncUtilThres;///< Number of frames that exceed the high encode util threshold

    uint16_t staticSceneThresFrames;///< Static scene thresold in number of frames

    uint16_t throttlingLimitScalex1000;///< Scaling factor to reduce the throttling limit being applied. If set to zero, this disables the throttling limit for RL bitrate
}NvscVqosRlInputPostprocessingSettings;

/// Struct storing settings for controlling the pre-processing of inputs for RL bitrate model.
typedef struct NvscVqosRlInputPreprocessingSettings_t
{

    uint8_t bweFilterFactor;///< IIR factor for server-side filtering of weighted Bandwidth estimation.

    uint8_t bwuFilterFactor;///< IIR factor for server-side filtering of weighted Bandwidth utilization.

    uint32_t frameDropPlWeightx1000;///< Weight on frame drop due to packet loss

    uint32_t frameDropPlThresholdPercent;///< Threshold on packet loss before the model starts to react.

    uint32_t frameDelayStutterToleranceMs;///< Tolerance for frame delay while computing frame drop estimate

    uint32_t owdFilterWeightx1000;///< Filter weight for OWD while computing normalized utilization time

    uint32_t peakFrameDelayToleranceMs;///< Tolerance for peak frame delay while computing normalized utilization time

    uint32_t minNormalizedUtilizationx10000;///< Minimum cap for normalized utilization time input

    uint32_t staticSceneEncUtilThresx1000;///< Threshold for encoder utilization to detect static scenes

    uint32_t highEncUtilWindowSize;///< Number of previous frames to  check for high encoder utilization before marking the current frame as non-static

    uint32_t maxUtilCapFrameDelayTolerancex1000;///< Maximum encoder utilization for frame delay tolerance

    uint32_t utilTimeFractionScalarx1000;///< Scalar multiplier for utilization time fraction

    uint32_t maxBwFilterFactor;///< Maximum BW filter factor

    uint32_t maxBwScaleFactorx1000;///< Scaling factor for maximum BW limit
}NvscVqosRlInputPreprocessingSettings;

/// Struct storing settings for manual mode of bitrate algorithm.
typedef struct NvscVqosRlBitrateManualModeSettings_t
{

    uint8_t enable;///< Enable manual mode to estimate bitrate when there is no qos feedback

    uint32_t thresholdL1;///< Threshold to enter L1 of manual mode bitrate, for TxRxLag (in number of frames)

    uint32_t thresholdL2x1000;///< Threshold to enter L2 to manual mode, in terms of fraction of starting bitrate (x1000 since float values are not supported)

    uint32_t thresholdL3;///< Threshold to enter L3 of manual mode bitrate, for TxRxLag (in number of frames)

    uint32_t maxFramesL3;///< Max number of frames to remain in L3 stage of manual mode bitrate

    uint32_t decayFactorL1x1000;///< Decay factor for L1 stage of manual mode (x1000 since float values are not supported)

    uint32_t decayFactorL2x1000;///< Decay factor for L2 stage of manual mode (x1000 since float values are not supported)
}NvscVqosRlBitrateManualModeSettings;

/// Struct storing settings for early update mode.
typedef struct NvscVqosRlEarlyUpdateSettings_t
{

    uint16_t bitrateThreshold;///< Threshold for bitrate early update condition

    uint16_t fecThreshold;///< Threshold for FEC early update condition

    uint16_t minimumDistance;///< Minimum distance between two frames having early update mode

    uint16_t cummRxGapThresMs;///< Threshold for cumulative gap of received frames to trigger early update

    uint16_t frameDropPlThres;///< Threshold for number of frames dropped with packet loss to trigger early update
}NvscVqosRlEarlyUpdateSettings;


typedef enum NvscVqosRlLibrary_t
{
    NVSC_VQOS_RL_LIBRARY_TENSORRT = 0,///< Use TensorRT library
    NVSC_VQOS_RL_LIBRARY_PYTHON = 1,///< Use Python library (only for local builds)
}NvscVqosRlLibrary;


typedef enum NvscVqosRlFecProfile_t
{
    NVSC_VQOS_RL_FEC_PROFILE_DEFAULT = 0,///< Enable default fec profile
}NvscVqosRlFecProfile;


typedef enum NvscVqosRlBitrateProfile_t
{
    NVSC_VQOS_RL_BITRATE_PROFILE_DEFAULT = 2,///< Enable default bitrate profile
}NvscVqosRlBitrateProfile;


typedef enum NvscVqosRlFeatures_t
{
    NVSC_VQOS_RL_DISABLED = 0x0,///< Disable all RL features
    NVSC_VQOS_RL_BITRATE = 0x1,///< Enable bitrate model
    NVSC_VQOS_RL_FEC = 0x2,///< Enable FEC model
}NvscVqosRlFeatures;

/// Struct storing settings for adaptive QoS using RL.
typedef struct NvscVqosRlSettings_t
{
    NvscVqosRlFeatures features;///< Flags to enable individual RL features
    NvscVqosRlBitrateProfile bitrateProfile;///< Option to control which bitrate profile to use
    NvscVqosRlFecProfile fecProfile;///< Option to control which fec profile to use
    NvscVqosRlLibrary library;///< Option to control which backend library to use

    uint16_t bitrateUpdateFrequency;///< Number of frames between two model updates for bitrate

    uint32_t minimumModelInputBufferOccupancy;///< Minimum size of non-zero data in the RL input buffer required to start running the model inference

    uint32_t bitrateMinActionKbps;///< Minimum action for bitrate model

    uint32_t bitrateMaxActionKbps;///< Maximum action for bitrate model

    uint32_t txRxLagIIRFactorx1000;///< IIR filter factor for average TxRxLag (x1000 since float values are not supported)

    uint8_t enableWeightedBwe;///< Option to enable the weighted bandwidth estimation.

    uint32_t weightedBwePlPercentThres;///< Packet loss threshold for weighted bwe calculation.
    NvscVqosRlEarlyUpdateSettings earlyUpdate;///< Settings for early update mode
    NvscVqosRlBitrateManualModeSettings bitrateManualMode;///< Settings for manual mode of bitrate algorithm
    NvscVqosRlInputPreprocessingSettings preprocessing;///< Settings for controlling the pre-processing of inputs for RL bitrate model
    NvscVqosRlInputPostprocessingSettings postprocessing;///< Settings for controlling the pout-processing for RL bitrate model

    uint8_t enableFeedback;///< Option to enable the RL feedback from client to the server.

    uint32_t feedbackVersion;///< Version of RL feedback structure being sent by client.

    uint8_t serverLogging;///< Whether or not the server dumps the RL input/data data to local log files. Only for internal debugging.

    uint8_t modelInputLogging;///< Whether or not the server dumps the RL model input/output data data to local csv files. Only for internal debugging.
}NvscVqosRlSettings;

/// Struct storing details about BLL-FEC settings.
typedef struct NvscBllFecSettings_t
{

    uint8_t enable;///< Whether or not to use the alternative Video QoS forward error correction.

    uint8_t adaptiveActivation;///< Whether or not to use adaptive logic for BLL-FEC increases at frame losses.

    uint8_t adaptiveActivationThresholdX100;///< Value for EMA (x100) of complete frame received at which QoS starts adapting FEC.

    uint8_t isWindowLengthFixed;///< Denotes whether the size of the window of loss observations used by BLL-FEC is fixed or dynamically adapted.

    uint16_t minWindowSize;///< Min window size in # frames prior to FEC drop assuming no equal or higher losses observed. Also used as the initial window size.

    uint16_t maxWindowSize;///< Max window size in # frames prior to FEC drop assuming no equal or higher losses observed. Set to 0 to switch to using time domain variables below.

    uint16_t minTimeWindowSizeMs;///< Min time duration prior to FEC drop assuming no equal or higher losses observed. Determines the initial window size of per-frame lossy observations.

    uint16_t maxTimeWindowSizeMs;///< Max time duration prior to FEC drop assuming no equal or higher losses observed.

    uint32_t defaultBll;///< Default FEC protection intensity expressed in count Bytes.

    uint8_t repairMinPercent;///< Denotes the minimum FEC percent to be applied given the numSrcPackets for current frame.

    uint16_t maxEffectiveFecPercent;///< Maximum effective FEC percent cap for any given frame. Note the rounding can cause the on-wire effective FEC percent to be higher than this value.
    MetaParams<uint16_t> maxEffectiveFecPercentMetaParams;

    uint16_t maxEffectiveFecPercentFloor;///< Denotes the minimum effective FEC percent cap enforced after timeToDropMaxEffectiveFecMs following burst loss observation.
    MetaParams<uint16_t> maxEffectiveFecPercentFloorMetaParams;

    uint32_t maxEffectiveFecDropDurationMs;///< Denotes the time duration in ms required to drop max effective FEC percent  cap from maxEffectiveFecPercent to maxEffectiveFecPercentFloor                    after observing the previous burst loss high. Value of 0 disables the the adaptation of max effective FEC percent cap.

    uint32_t numSrcPacketsSkipEffectiveFecCap;///< Denotes the threshold of source packets for a frame, above which we enforce the adaptive max effective FEC percent cap.

    uint8_t minRequiredFecPackets;///< Minimum number of FEC repair packets to use per frame.

    uint16_t maxAllowedFecPackets;///< Maximum allowed number of FEC repair packets to use per frame.

    uint32_t numSrcPackets;///< Number of source packets that will be given to the FEC Encode block.

    uint8_t preserveBitrateWindowSizePercent;///< Threshold percent of difference of max and min window size below which the FEC overhead will not be accounted for in the proposed encoder rate. Set to 0 to disable the functionality.

    uint32_t skipBitrateIncreaseThresholdBytes;///< Threshold of BLL-FEC's target FEC intensity above which we decide to skip bitrate increase.

    uint8_t adjustEncoderBitrateForMinMaxFecPackets;///< Adjust encoder target bitrate according to minimum required and maximum allowed FEC packets.
}NvscBllFecSettings;

/// Struct storing details about fec settings.
typedef struct NvscFecSettings_t
{

    uint8_t enable;///< Whether or not to use Video QoS forward error correction.

    uint8_t adaptiveActivation;///< Whether or not to use adaptive logic for FEC increases at frame losses, default is disabled.

    uint8_t adaptiveActivationThresholdX100;///< Value for EMA (x100) of complete frame received at which QoS increases percent FEC, default is 95

    uint8_t maxStepsPerFecIncrement;///< Increment FEC repair percenet in steps. Maximum number of steps per FEC increment, default is disabled.

    uint32_t numSrcPackets;///< Number of source packets that will be given to the FEC Encode block.

    uint32_t repairPercent;///< FEC repair percent.

    uint32_t repairMaxPercent;///< FEC repair max percent.

    uint32_t repairMinPercent;///< FEC repair min percent.

    uint8_t minRequiredFecPackets;///< Minimum number of FEC repair packets to use per frame. Supercedes the repairMaxPercent setting.

    uint16_t maxAllowedFecPackets;///< Maximum number of FEC repair packets to use per frame. Supercedes the repairMaxPercent setting.

    uint16_t minPacketLossThreshold;///< The minimum number of packets in a frame to impact FEC percent.

    uint16_t rateDropWindow;///< The period in seconds after which FEC rate can be lowered.

    uint8_t adjustEncoderBitrateForMinMaxFecPackets;///< Adjust encoder target bitrate according to minimum required and maximum allowed FEC packets.
}NvscFecSettings;


typedef enum SmartIntraRefreshPattern_t
{
    SMART_IR_SINGLE_RATE = 1,///< Single rate refresh
    SMART_IR_DOUBLE_RATE = 2,///< Double rate refresh
    SMART_IR_TRIPLE_RATE = 3,///< Triple rate refresh
    SMART_IR_QUAD_RATE = 4,///< Quad rate refresh
}SmartIntraRefreshPattern;


typedef enum intraRMode_t
{
    INTRA_STATIC_MODE = 0x01,///< Intra Refresh is enabled throughout the session
    INTRA_DYNAMIC_MODE = 0x02,///< Intra Refresh is enabled when the network is bad
    INTRA_RECOVERY_MODE = 0x04,///< Intra Refresh is enabled when session enters recovery mode
}intraRMode;

/// Struct storing details about Intra Refresh settings.
typedef struct NvscVqosIntraR_t
{

    uint32_t length;///< Configure the length of Intra Refresh across frames.

    uint32_t period;///< Configure the period for which Intra Refresh should be generated.

    uint8_t maxScalingFactor;///< Configure the max intra refresh scaling factor for intra refresh period and length.

    uint32_t coolDownPeriodMs;///< Configure the period after which Intra Refresh will step down its length and period.

    uint8_t enableSmartIntraRefresh;///< Enable/Disable Smart Intra refresh feature. by default it will be disabled.
    intraRMode mode;///< This flag enables intra refresh only in bad network conditions

    uint16_t frameLossThreshold;///< Minimum frame loss required to trigger IR param change.

    uint16_t frameLossWindowSize;///< Number of past frames to be considered for frame loss threshold.

    uint16_t txRxLagThresholdInMs;///< Minimum TxRxlag required to trigger IR param change.
    SmartIntraRefreshPattern smartIntraRefreshPatternType;///< Flags to select Smart intra refresh pattern
}NvscVqosIntraR;

/// Struct storing details about QP Grouping settings.
typedef struct NvscVqosQpGrouping_t
{

    uint8_t enable;///< Disable QP Grouping by default.

    uint8_t maxQp;///< QPG won't target minQp values higher than this setting. Minimum value is taken from the video[streamIndex].minQp setting.

    uint32_t coolDownPeriodInMs;///< Minimum time between minQp adjustments.
}NvscVqosQpGrouping;


typedef enum DfcVersion_t
{
    DFC_ALGO_VERSION_1 = 1,///< Default DFC algorithm where streaming FPS is lowered from maxFPS (120) to minFPS (60) after which resolution downgrade is applied
    DFC_ALGO_VERSION_2 = 2,///< This DFC algorithm allows immediate resolution downgrade upon poor client decode/render perf
}DfcVersion;

/// Struct storing details about video QoS DFC settings.
typedef struct NvscVqosDfc_t
{

    uint8_t enable;///< Disable video QoS DFC by default.

    uint8_t adjustResAndFps;///< Adjust streaming resolution and FPS as part of DFC algo.

    uint8_t maxResLevels;///< Max number of DFC resolution table entries to create.

    uint8_t useAdaptiveQp;///< Use adaptive QP - dynamically adjust QP thresholds based on resolution, frequency, and bitrate.

    uint8_t minTargetFps;///< Minimum streaming FPS to target if the resolution is above a certain resolution level (for ex: 720p for DFC V2.0) or if it isn't at the lowest allowed level.

    uint8_t lowResMinTargetFps;///< Minimum streaming FPS to target below a certain resolution level (for ex: from 720p for DFC V2.0) or when the resolution is already as low as possible. Can allow lower framerates as a final effort to maintain video quality.

    uint8_t highResMinClientFps;///< Minimum fps threshold for client perf (decoder, render) at resolutions > 720p
    DfcVersion dfcAlgoVersion;///< Setting to select variant of DFC algorithm

    uint8_t decodeFpsAdjPercent;///< Scaling percentage applied to the client's decoder FPS capability estimate. Set to 0 to ignore this client estimate when adjusting target framerate.

    uint8_t renderFpsAdjPercent;///< Adjustment percentage applied to the client's render FPS capability estimate. Set to 0 to ignore this client estimate when adjusting target framerate.

    uint8_t clientFpsDecreasePercent;///< Percentage FPS decrease used to update the target streaming FPS ceiling based on client performance.

    uint8_t clientFpsIncreasePercent;///< Percentage FPS increase used to update the target streaming FPS ceiling based on client performance.

    uint8_t clientFpsMinStep;///< Minimum FPS ceiling adjustment step to take in response to client performance feedback.

    uint8_t fpsDecreasePercent;///< Percentage decrease used to update target streaming FPS based on encoder performance as measured by QP.

    uint8_t fpsIncreasePercent;///< Percentage increase used to update target streaming FPS based on encoder performance as measured by QP.

    uint8_t fpsStepSizeMin;///< Minimum FPS step by which to adjust target stream FPS. Useful for low frequencies or implementing fixed size steps.

    uint8_t qpMaxUpperLimit;///< Max allowed adaptive QP upper threshold.

    uint8_t qpMinUpperLimit;///< Min allowed adaptive QP upper threshold.

    uint8_t qpLowerLimit;///< Lower QP threshold below which DFC will attempt to raise the fps or streaming resolution.

    uint8_t qpMaxResThresholdAdj;///< Value by which the upper QP threshold will be adjusted, only for the maximum resolution level.

    uint8_t qpCodecThresholdAdj;///< Value by which the upper QP threshold will be adjusted to account for codecs other than H264.

    uint8_t minQpHeadroom;///< Minimum QP headroom required for resolution upgrade.

    uint32_t minGoodMsBeforeUpgrade;///< Minimum time we must remain at max FPS before considering a res upgrade. Helps prevent upgrades due to a few good frames.

    uint32_t upgradeCooldownMs;///< Cooldown period DFC must wait after res change before upgrading res.

    uint32_t downgradeCooldownMs;///< Cooldown period DFC must wait after res change before downgrading res.

    uint16_t ceilingUpCooldownMs;///< Time to wait after a ceiling FPS change before it can be raised.

    uint16_t ceilingDownCooldownMs;///< Time to wait after a ceiling FPS change before it can be lowered.

    uint16_t targetUpCooldownMs;///< Time to wait after a target FPS change before it can be raised.

    uint16_t targetDownCooldownMs;///< Time to wait after a target FPS change before it can be lowered.

    uint8_t initFpsIncreasePercent;///< Percentage between min and max values used for initializing targetFps.

    uint16_t promoteResolutionCoolingTimeMs;///< Adaptive QP cooling time (in ms) for promoting resolution if QP stays at low level.
}NvscVqosDfc;

/// Enabled performance history categories.
typedef enum NvscPerfHistoryFeature_t
{
    DISABLE_PERF_HISTORY = 0x0,///< Empty mask means don't run perf history logic.
    ENABLE_DECODER_PERF_HISTORY = 0x1,///< Use decoder performance history in resolution upgrade logic.
    ENABLE_RENDER_PERF_HISTORY = 0x2,///< Use render performance history in resolution upgrade logic.
}NvscPerfHistoryFeature;

/// Struct storing details about video QoS Performance History settings.
typedef struct NvscVqosPerfHistory_t
{

    uint16_t iirFilterFactor;///< IIR filter factor for computing filtered values of performance history inputs (ex. decoder time, render time).

    uint32_t minNumSamples;///< Minimum number of performance samples needed to stop a resolution upgrade to particular resolution/fps combination.

    uint32_t resetTimerMs;///< Time to wait after a resolution downgrade before that resolution's performance stats are forgotton. Set to 0 to disable the timer.

    uint16_t fpsUpgradePct;///< Percentage of new FPS to use when determining if new resolution/fps is supportable. Allows for some performance headroom / hysteresis.
    NvscPerfHistoryFeature featureMask;///< This is to control various categories of performance history tracking.
}NvscVqosPerfHistory;

/// Struct storing details about video QoS settings for client performance monitoring.
typedef struct NvscVqosClientPerformanceMonitor_t
{

    uint8_t flags;///< Disable video Qos client performance monitoring feature by default.

    uint16_t resolutionUpdateCoolDownCount;///< This is the number of frames that CPM waits before it resumes monitoring client's performance.

    uint16_t avgBeginTimeThresholdMs;///< This is the begin time threshold for new method.

    uint16_t avgDecodeTimeThresholdFactor;///< This is the decode time threshold scaling factor for CPM.

    uint16_t maxFrameBeginTimeMs;///< This is the begin time clipping upper limit.

    uint16_t maxFrameDecodeTimeFactor;///< This is the decode time clipping upper limit scaling factor.

    uint16_t iirFilterFactor;///< IIR filter factor for computing filtered values of client decoder, render fps capabilities).

    uint16_t resolutionChangeHoldonMs;///< Timeout to ignore CPM downgrade request after resolution change.

    uint8_t waitPeriodAfterIdr;///< This is the number of frames that CPM waits before it resumes monitoring client's performance after receiving an IDR frame.
}NvscVqosClientPerformanceMonitor;

/// Struct storing details about Qos GFC settings
typedef struct NvscVqosGfc_t
{

    uint32_t minGoodMsBeforeUpgrade;///< Minimum time we must remain at max FPS before considering a res upgrade. Helps prevent upgrades due to a few good frames.

    uint32_t upgradeCooldownMs;///< Cooldown period DFC must wait after res change before upgrading res.

    uint32_t downgradeCooldownMs;///< Cooldown period DFC must wait after res change before downgrading res.

    uint8_t minTargetFps;///< Minimum streaming FPS to target if the resolution is above a certain resolution level (for ex: 720p for DFC V2.0) or if it isn't at the lowest allowed level.
}NvscVqosGfc;


typedef enum NvscVqosGrcEnableMask_t
{
    GRC_ENABLE_NONE = 0x0,///< GRC is not enabled
    GRC_ENABLE_H264 = 0x1,///< GRC is enabled for H264 streams
    GRC_ENABLE_H265 = 0x2,///< GRC is enabled for H265 streams
    GRC_ENABLE_DFC = 0x4,///< GRC is enabled when DFC is enabled
    GRC_ENABLE_AV1 = 0x8,///< GRC is enabled for AV1 streams
}NvscVqosGrcEnableMask;

/// Struct storing details about Qos GRC settings
typedef struct NvscVqosGrc_t
{
    NvscVqosGrcEnableMask enable;///< Whether GRC is enabled or not

    uint8_t supported;///< Whether GRC is supported by the client or not

    uint16_t stepUpIntervalInFrames;///< Number of frames we should wait after stepping up before stepping again

    uint16_t stepUpWidth;///< Difference in width to use between resolution step ups

    uint16_t stepDownIntervalInFrames;///< Number of frames we should wait after stepping down before stepping again

    uint16_t stepDownWidth;///< Difference in width to use between resolution step downs

    uint16_t updateCoolingTimeMs;///< Cooling time (in msec) for updating resolution in video QoS QP-based GRC

    uint16_t promoteCoolingTimeMs;///< Cooling time (in msec) for promoting resolution if QP stays at low level

    uint16_t midpointQpUpdateCoolingTimeMs;///< How long to wait before upgrading if the QP is below the midpoint of the low and high thresholds

    uint16_t downLevels;///< Number of levels to reduce resolution when a QP threshold is reached

    uint16_t upLevels;///< Number of levels to increase resolution when a QP threshold is reached

    uint8_t minQpHeadroom;///< Minimum QP headroom required for resolution upgrade.

    uint8_t lowerQpThreshold;///< With QP lower than this threshold, game content is easy to encode.

    uint8_t upperQpThreshold;///< With QP higher than this threshold, game content is hard to encode.

    uint8_t minAdaptiveQpThreshold;///< Lower bound of adaptive QP threshold that takes into account bpp.

    uint8_t qpMaxResThresholdAdj;///< Value by which the upper QP threshold will be adjusted, only for the maximum resolution level.

    uint8_t qpCodecThresholdAdj;///< Value by which the upper QP threshold will be adjusted to account for codecs other than H264.

    uint8_t iirFilterFactor;///< Factor of IIR filter in video QoS QP-based GRC.
}NvscVqosGrc;

/// DRC table type.
typedef enum NvscVqosDrcTableType_t
{
    DRC_TABLE_TYPE_DYNAMIC = 1,///< Dynamically generate DRC resolutions based on the requested max resolution.
    DRC_TABLE_TYPE_STATIC = 2,///< Force usage of the static/hardcoded DRC table.
}NvscVqosDrcTableType;

/// Struct storing details about video QoS DRC settings.
typedef struct NvscVqosDrc_t
{

    uint8_t enable;///< enable video QoS DRC by default.
    NvscVqosDrcTableType tableType;///< Controls DRC table generation, i.e. static vs. dynamic.

    uint8_t iirFilterFactor;///< Factor of IIR filter in video QoS QP-based DRC.

    uint16_t bitrateIirFilterFactor;///< Factor of IIR filter for video QoS bitrate filtering, including the input to dynamic QP threshold calculations.

    uint8_t minQpHeadroom;///< Minimum QP headroom required for resolution upgrade.

    uint8_t updateCoolingTime;///< Cooling time (in sec) for updating resolution in video QoS QP-based DRC.

    uint8_t promoteCoolingTime;///< Cooling time (in sec) for promoting resolution if QP stays at low level.

    uint8_t lowerQpThreshold;///< With QP lower than this threshold, game content is easy to encode.

    uint8_t upperQpThreshold;///< With QP higher than this threshold, game content is hard to encode.

    uint8_t minAdaptiveQpThreshold;///< Lower bound of adaptive QP threshold that takes into account bpp.

    uint8_t qpMaxResThresholdAdj;///< Value by which the upper QP threshold will be adjusted, only for the maximum resolution level.

    uint8_t qpCodecThresholdAdj;///< Value by which the upper QP threshold will be adjusted to account for codecs other than H264.

    uint16_t downgradeCostLength;///< DRC cost calculation filter length (in frames). Set it to 0 to disable DRC cost-based calculations.

    uint32_t downgradeCostX1000;///< For DRC cost calculations, this is the cost due to the reconfiguration discontinuity (x1000).

    uint32_t downgradeCostLowResMultX1000;///< For DRC cost calculations, this is the cost multiplier for changes at low resolutions (x1000).

    uint16_t lowEncoderUtilizationThreshold;///< This is the encoder utilization threshold to identify static scene.

    uint8_t minRequiredBitrateCheckEnabled;///< This is to check for average target bitrate to be greater than minimum required bitrate before doing a resolution upgrade.

    uint8_t stepDownResolutionAlignment;///< Value set by client to ensure DRC stepdown resolutions are multiple of this

    uint16_t stepDownMinHeight;///< Value set by client to request server to support lower step down resolutions

    uint16_t stepDownTargetAspectRatioX100;///< Value set by client for server to round up/down the resolution to be multiple of stepDownResolutionAlignment (x100)

    uint8_t add1440pResLevelFor4kDrcTable;///< This is to add 1440p resolution as intermediate DRC level for 4K DRC table. It is disabled by default
}NvscVqosDrc;

/// Struct storing details about decoder's performance History settings.
typedef struct NvscVqosPerfHistoryType_t
{

    uint16_t iirFilterFactor;///< IIR filter factor for computing filtered values of performance history decoder time.

    uint32_t minNumSamples;///< Minimum number of performance samples needed to stop a resolution upgrade to particular resolution/fps combination.

    uint32_t resetTimerMs;///< Time to wait after a resolution downgrade before that resolution's performance stats are forgotton. Set to 0 to disable the timer.

    uint16_t fpsUpgradePercent;///< Percentage of new FPS to use when determining if new resolution/fps is supportable. Allows for some performance headroom / hysteresis.
}NvscVqosPerfHistoryType;

/// Struct storing details about video QoS Performance History settings.
typedef struct NvscVqosPerformanceHistory_t
{
/// Enabled performance history categories.
    NvscPerfHistoryFeature featureMask;///< This is to control various categories of performance history tracking.
    NvscVqosPerfHistoryType decoder;///< Describes performance history settings for receiver decoder.
/// Struct storing details about renderer's performance History settings.
    NvscVqosPerfHistoryType renderer;///< Describes performance history settings for receiver renderer.
}NvscVqosPerformanceHistory;

/// Enabled decode time based cpm and performance history categories.
typedef enum NvscCpmRtcFeature_t
{
    DISABLE_CPM_RTC = 0x0,///< Empty mask means neither cpm nor perf history is enabled.
    ENABLE_CPM_RTC = 0x1,///< Enable cpm downgrade based on decode times.
    ENABLE_PERF_HISTORY_RTC = 0x2,///< Use decode performance history in resolution upgrade logic. Applicable only if cpm is also enabled.
}NvscCpmRtcFeature;

/// Struct storing details about video QoS settings for client performance monitoring for RTC client.
typedef struct NvscVqosClientPerformanceMonitorRtc_t
{

    uint16_t badNwDetectionRttDeltaThresholdMs;///< Threshold for change in RTT for detecting bad network that can influence decode times data.

    uint16_t badNwDetectionAvgNacksThreshold;///< Threshold for average nack packets for detecting bad network that can influence decode times data.

    uint16_t badNwDetectionAvgNacksIirFilterFactor;///< IIR filter factor for computing average of packets nacked.

    uint16_t badNwSkipFramesCount;///< This is the number of frames that CPM waits before it resumes monitoring client's performance on bad network that can influence decode times.

    uint16_t decodeTimeThresholdMs;///< Decode time threshold for triggering CPM downgrade.

    uint16_t decTimeHeadroomForResUpgradePct;///< Percent of decode time threshold to be maintaned as headroom for allowing resolution upgrade.

    uint16_t resUpgradeDisableDurationMs;///< Upgrade disable duration since last decode time headroom violation.

    uint16_t decodeTimeIirFilterFactor;///< IIR filter factor for computing average decode times.

    uint16_t serverResolutionUpdateCoolDownCount;///< This is the number of frames that server waits for allowing upgrade after CPM downgrade.

    uint16_t skipDowngradeDuringStaticScenes;///< Whether to skip CPM downgrades during static scenes or not. Boolean: 0 = No, 1 = Yes.

    uint16_t decodePerfHistoryThresholdPctCurrentResolution;///< Percent of decode time threshold to be used as threshold for deciding performance history of the current resolution. It's used to decide if next higher resolution can be sustained given performance history of the current resolution.

    uint16_t decodePerfHistoryThresholdPctNextResolution;///< Percent of decode time threshold to be used as threshold for deciding performance history of the next requested resolution. It's used to decide if next higher resolution can be sustained given it's performance history.

    uint16_t decodePerfHistoryIirFilterFactor;///< IIR filter factor for computing filtered values of performance history decode inputs.

    uint16_t decodePerfHistorySamplesRequiredMin;///< Minimum number of decode performance samples needed to stop a resolution upgrade to particular resolution/fps combination.

    uint32_t decodePerfHistoryResetTimeMs;///< Time to wait after a resolution downgrade before that resolution's decode performance stats are forgotton. Set to 0 to disable the timer.
    NvscCpmRtcFeature featureMask;///< This is to control decode time based cpm and performance history features.
}NvscVqosClientPerformanceMonitorRtc;

/// Struct storing details about QP Grouping settings.
typedef struct NvscVqosQpg_t
{

    uint8_t enabled;///< Disable QP Grouping by default.

    uint8_t maxQp;///< QPG won't target minQp values higher than this setting. Minimum value is taken from the video[streamIndex].minQp setting.

    uint32_t coolDownPeriodInMs;///< Minimum time between minQp adjustments.
}NvscVqosQpg;

/// Struct storing details about QP management settings.
typedef struct NvscVqosQp_t
{

    uint8_t adaptiveQpEnabled;///< Use adaptive QP - dynamically adjust QP thresholds based on resolution, frequency, and bitrate.

    uint8_t iirFilterFactor;///< Factor of IIR filter in video QoS QP-based DRC.

    uint8_t minQpHeadroom;///< Minimum QP headroom required for resolution upgrade.

    uint32_t promoteCoolingTimeMs;///< Cooling time (in ms) for promoting resolution if QP stays at low level.

    uint8_t lowerQpThreshold;///< With QP lower than this threshold, game content is easy to encode.

    uint8_t upperQpThreshold;///< With QP higher than this threshold, game content is hard to encode.

    uint8_t minAdaptiveQpThreshold;///< Lower bound of adaptive QP threshold that takes into account bpp.

    uint8_t qpMaxResThresholdAdj;///< Value by which the upper QP threshold will be adjusted, only for the maximum resolution level.

    uint8_t qpCodecThresholdAdj;///< Value by which the upper QP threshold will be adjusted to account for codecs other than H264.

    uint16_t qpCodecMinThresholdAdj;///< Bumps up minQP for non-H264 codecs. Lower byte is for HEVC, upper byte is for AV1. Intended for AB experiments.

    uint16_t downgradeCostLength;///< DRC cost calculation filter length (in frames). Set it to 0 to disable DRC cost-based calculations.

    uint32_t downgradeCostX1000;///< For DRC cost calculations, this is the cost due to the reconfiguration discontinuity (x1000).

    uint32_t downgradeCostLowResX1000;///< For DRC cost calculations, this is the cost multiplier for changes at low resolutions (x1000).

    uint16_t midpointQpUpdateCoolingTimeMs;///< How long to wait before upgrading if the QP is below the midpoint of the low and high thresholds
    NvscVqosQpg qpg;///< Used to describe QP Grouping (QPG) settings. QP Grouping aims to reduce streaming by dynamically adjusting the encoder's minQp knob to prevent quick downward spikes in QP / increases in frame size.
}NvscVqosQp;

/// Struct storing details about Qos GRC settings
typedef struct NvscVqosGradualResolutionControl_t
{

    uint8_t supported;///< Whether GRC is supported by the receiver or not

    uint16_t stepUpIntervalInFrames;///< Number of frames we should wait after stepping up before stepping again

    uint16_t stepUpWidth;///< Difference in width to use between resolution step ups

    uint16_t stepDownIntervalInFrames;///< Number of frames we should wait after stepping down before stepping again

    uint16_t stepDownWidth;///< Difference in width to use between resolution step downs

    uint16_t updateCoolingTimeMs;///< Cooling time (in msec) for updating resolution in video QoS QP-based GRC

    uint16_t downLevels;///< Number of levels to reduce resolution when a QP threshold is reached

    uint16_t upLevels;///< Number of levels to increase resolution when a QP threshold is reached
/// Struct storing details about QP management settings to use with Grc.
    NvscVqosQp qp;///< Used to describe QP manager settings for Grc.
}NvscVqosGradualResolutionControl;

/// Struct storing details about video QoS DFC settings.
typedef struct NvscVqosDynamicFrequencyControl_t
{

    DfcVersion dfcAlgoVersion;///< Setting to select variant of DFC algorithm

    uint8_t adjustResAndFps;///< Adjust streaming resolution and FPS as part of DFC algo.

    uint8_t maxResLevels;///< Max number of DFC resolution table entries to create.

    uint8_t minTargetFps;///< Minimum streaming FPS to target if the resolution is above a certain resolution level (for ex: 720p for DFC V2.0) or if it isn't at the lowest allowed level.

    uint8_t lowResMinTargetFps;///< Minimum streaming FPS to target below a certain resolution level (for ex: from 720p for DFC V2.0) or when the resolution is already as low as possible. Can allow lower framerates as a final effort to maintain video quality.

    uint8_t highResMinReceiverFps;///< Minimum fps threshold for receiver perf (decoder, render) at resolutions > 720p

    uint8_t decodeFpsAdjPercent;///< Scaling percentage applied to the receiver's decoder FPS capability estimate. Set to 0 to ignore this receiver estimate when adjusting target framerate.

    uint8_t renderFpsAdjPercent;///< Adjustment percentage applied to the receiver's render FPS capability estimate. Set to 0 to ignore this receiver estimate when adjusting target framerate.

    uint8_t receiverFpsDecreasePercent;///< Percentage FPS decrease used to update the target streaming FPS ceiling based on receiver performance.

    uint8_t receiverFpsIncreasePercent;///< Percentage FPS increase used to update the target streaming FPS ceiling based on receiver performance.

    uint8_t receiverFpsMinStep;///< Minimum FPS ceiling adjustment step to take in response to receiver performance feedback.

    uint8_t fpsDecreasePercent;///< Percentage decrease used to update target streaming FPS based on encoder performance as measured by QP.

    uint8_t fpsIncreasePercent;///< Percentage increase used to update target streaming FPS based on encoder performance as measured by QP.

    uint8_t fpsStepSizeMin;///< Minimum FPS step by which to adjust target stream FPS. Useful for low frequencies or implementing fixed size steps.

    uint32_t minGoodMsBeforeUpgrade;///< Minimum time we must remain at max FPS before considering a res upgrade. Helps prevent upgrades due to a few good frames.

    uint32_t upgradeCooldownMs;///< Cooldown period DFC must wait after res change before upgrading res.

    uint32_t downgradeCooldownMs;///< Cooldown period DFC must wait after res change before downgrading res.

    uint16_t ceilingUpCooldownMs;///< Time to wait after a ceiling FPS change before it can be raised.

    uint16_t ceilingDownCooldownMs;///< Time to wait after a ceiling FPS change before it can be lowered.

    uint16_t targetUpCooldownMs;///< Time to wait after a target FPS change before it can be raised.

    uint16_t targetDownCooldownMs;///< Time to wait after a target FPS change before it can be lowered.

    uint8_t initFpsIncreasePercent;///< Percentage between min and max values used for initializing targetFps.

    uint16_t fpsPeriodMsEstimate;///< Period over which the streaming FPS estimate is computed for Turbo Mode or DFC.

    uint16_t minStreamFpsEstimate;///< Minimum streaming FPS estimate to use for Turbo Mode or DFC.

    uint16_t maxStreamFpsEstimate;///< Maximum streaming FPS estimate to use for Turbo Mode or DFC.

    uint8_t useClientFpsPerf;///< Use client decode/render FPS capabilities to adjust streaming fps ceiling.
}NvscVqosDynamicFrequencyControl;

/// Direct or Gradual
typedef enum NvscVqosTransControlType_t
{
    TRANSCONTROL_TYPE_DIRECT = 1,///< Abrupt resolution change to the target resolution
    TRANSCONTROL_TYPE_GRADUAL = 2,///< Gradual resolution change towards the target resolution
}NvscVqosTransControlType;

/// Fixed, DRC or DFC
typedef enum NvscVqosResControlType_t
{
    RES_CONTROL_TYPE_FRC = 1,///< Fixed Resolution Control mode
    RES_CONTROL_TYPE_DRC = 2,///< Dynamic Resolution Control mode (DRC).
    RES_CONTROL_TYPE_DFC = 3,///< Dynamic Frequency Conrol mode (DFC).
}NvscVqosResControlType;

/// Struct storing details about video QoS resolution and fps management settings.
typedef struct NvscVqosResControl_t
{
    NvscVqosResControlType resControlType;///< Controls which resolution and framerate management algo to use
    NvscVqosTransControlType transControlType;///< Controls which resolution transition algo to use
/// DRC table type.
    NvscVqosDrcTableType tableType;///< Controls DRC table generation, i.e. static vs. dynamic.

    uint8_t enable;///< Enable video QoS Resolution Control by default.

    uint16_t bitrateIirFilterFactor;///< Factor of IIR filter for video QoS bitrate filtering, including the input to dynamic QP threshold calculations.

    uint32_t updateCoolingTimeMs;///< Cooling time (in ms) for updating resolution in video QoS QP-based DRC.

    uint16_t lowEncoderUtilizationThreshold;///< This is the encoder utilization threshold to identify static scene.

    uint8_t minRequiredBitrateCheckEnabled;///< This is to check for average target bitrate to be greater than minimum required bitrate before doing a resolution upgrade.

    uint8_t stepDownResolutionAlignment;///< Value set by receiver to ensure DRC stepdown resolutions are multiple of this

    uint16_t stepDownMinHeight;///< Value set by receiver to request server to support lower step down resolutions

    uint16_t stepDownTargetAspectRatioX100;///< Value set by receiver for server to round up/down the resolution to be multiple of stepDownResolutionAlignment (x100)

    uint8_t add1440pResLevelFor4kDrcTable;///< This is to add 1440p resolution as intermediate DRC level for 4K DRC table. It is disabled by default

    uint32_t startupResolutionHoldTimeMs;///< Time (ms) at start of session that Qos will prevent any resolution changes. Helps prevent overreacting to any startup glitches, ex. initial poor receiver performance reports.
    NvscVqosDynamicFrequencyControl dfc;///< Used to describe the video Qos DFC parameters.
/// Struct storing details about Qos GFC settings
    NvscVqosDynamicFrequencyControl gfc;///< Describes parameters to gradually change resolutions and FPS
    NvscVqosGradualResolutionControl grc;///< Describes parameters to gradually change resolutions
    NvscVqosQp qp;///< Used to describe QP manager settings.
    NvscVqosClientPerformanceMonitorRtc cpmRtc;///< Describe the video Qos parameters for monitoring client performance for RTC client.
    NvscVqosPerformanceHistory perfHistory;///< Describes performance history settings, used to help determine if receiver performance can handle upgrading the resolution.
}NvscVqosResControl;

/// Struct storing details about video QoS bad network settings.
typedef struct NvscVqosBadNetwork_t
{

    uint32_t notifyUpBoundThreshold;///< message send out upper boundary threshold.
}NvscVqosBadNetwork;

/// Configurations for different versions of TxRxLag bitrate control module
typedef struct NvscTxRxLagModule_t
{

    uint8_t moduleVersion;///< Feature toggle between legacy and refactored (default) algo for TxRxLag

    uint32_t maxIncreaseThreshold;///< Used to limit streaming bitrate when Tx Rx Lag increase exceeds this threshold.

    uint32_t minFeedbackTxDeltaMs;///< Minimum time window of sent feedbacks to detect 0 frame increase

    uint8_t countLowFbFrameDelta;///< Consecutive count of low feedback frame number delta to skip increasing bitrate

    uint32_t maxFeedbackSilenceMs;///< Time threshold for silence of client qos feedbacks to drop bitrate
}NvscTxRxLagModule;

/// Struct storing details about video QoS bandwidth settings.
typedef struct NvscVqosBandwidth_t
{

    uint32_t flags;///< Flags that define behavior of video bandwith QoS.

    uint32_t maximumBitrateKbps;///< maximum allowed bitrate in kbps.
    MetaParams<uint32_t> maximumBitrateKbpsMetaParams;

    uint32_t minimumBitrateKbps;///< minimum allowed bitrate in kbps.
    MetaParams<uint32_t> minimumBitrateKbpsMetaParams;

    uint32_t minimumEncoderBitrateKbps;///< minimum allowed encoder bitrate in kbps.
    MetaParams<uint32_t> minimumEncoderBitrateKbpsMetaParams;

    uint32_t statsTime;///< stats time (number of milliseconds to wait before sending stats to the server).

    uint32_t lossThreshold;///< loss threshold (loss rate below which no QoS adjustment is to be done).

    uint32_t jitterThresholdUs;///< Jitter above which we need to skip increasing video bitrate.

    uint8_t maxBitrateScalePercent;///< Percentage used to scale the client's requested max bitrate. Given as a percentage of the default value. Only applied if uiAutoMode is set.
    MetaParams<uint8_t> maxBitrateScalePercentMetaParams;

    uint32_t checkBwThrottlingIntervalMs;///< Time interval in milliseconds to check for network bandwidth throttling

    uint8_t bwThrottlingThresholdPercent;///< Bandwidth throttling detection threshold percentage

    uint32_t minThrottlingCoolingTime;///< Minimum cooling time (in sec) for capping bitrate when throttling is detected

    uint16_t throttlingBitrateCapIncreasePercent;///< After throttling cooling time is complete, stepsize used to relax bitrate cap

    uint32_t rtpStatsTime;///< RTP stats time (number of frames to wait before sending stats to the server).

    uint8_t maxBitrateScalePercentL1;///< Percentage used to scale client's requested max bitrate for resolution level1.

    uint8_t maxBitrateScalePercentL2;///< Percentage used to scale client's requested max bitrate for resolution level2 and beyond.
    NvscTxRxLagModule txRxLag;///< TxRxLag bitrate control module settings
    NvstMultiStreamBitrateControl multiStreamBitrateControl;///< controls the multi stream bitrate mode.
}NvscVqosBandwidth;

/// Struct storing details about video QoS settings.
typedef struct NvscVideoQosSettings_t
{

    uint64_t rtxTime;///< rtxTime in order to control the nack timeout.
    NvscVqosBandwidth bw;///< Used to describe the video Qos bandwidth parameters.
    NvscVqosBadNetwork bn;///< Used to describe the video Qos bad network parameters.
    NvscVqosResControl resControl;///< Used to describe the video Qos streaming resolution and framerate management parameters.
    NvscVqosDrc drc;///< Used to describe the video Qos DRC parameters.
    NvscVqosGrc grc;///< Describes parameters to gradually change resolutions
    NvscVqosGfc gfc;///< Describes parameters to gradually change resolutions and FPS
    NvscVqosClientPerformanceMonitor cpm;///< Describe the video Qos parameters for monitoring client performance.
    NvscVqosPerfHistory perfHistory;///< Describes performance history settings, used to help determine if client performance can handle upgrading the resolution.
    NvscVqosDfc dfc;///< Used to describe the video Qos DFC parameters.
    NvscVqosQpGrouping qpg;///< Used to describe QP Grouping (QPG) settings. QP Grouping aims to reduce streaming by dynamically adjusting the encoder's minQp knob to prevent quick downward spikes in QP / increases in frame size.
    NvscVqosIntraR intraR;///< Used to configure Intra refresh feature
    NvscFecSettings fec;///< FEC Configuration Settings
    NvscBllFecSettings bllFec;///< BLL-FEC Configuration Settings
    NvscVqosRlSettings rl;///< Settings for adaptive QoS algorithm using Reinforcement Learning
    NvscTurboModeOverride turboMode;///< Turbo Mode (high-FPS streaming) override knob to force enable or disable the feature in NvStreamer.

    uint16_t fpsPeriodMsEstimate;///< Period over which the streaming FPS estimate is computed for Turbo Mode or DFC.

    uint16_t minStreamFpsEstimate;///< Minimum streaming FPS estimate to use for Turbo Mode or DFC.

    uint16_t maxStreamFpsEstimate;///< Maximum streaming FPS estimate to use for Turbo Mode or DFC.

    uint32_t periodicRefreshIntervalMs;///< Time in milliseconds between two periodic refresh requests. NVSC has a feature to periodically request an IDR or Intra-refresh from the server. Set to 0 to disable.

    uint32_t videoQualityScoreUpdateTime;///< Time (ms) between Quality Score updates sent from the server.

    uint32_t qosTrafficType;///< QoS Traffic type for video which is used for DSCP setting in a flow

    uint8_t enableEcn;///< If set then video traffic will be tagged with ECN-ECT tag.

    uint8_t EcnEctCodepoint;///< Selects the ECT value used when ECN is enabled. Values 0 and 1 map to ECT_0 and ECT_1, respectively. To select NOT_ECT, set enableEcn to 0.
    NvstVideoFormat bitStreamFormat;///< Bit stream format used by video encoder.
/// H264 profile level id.
    uint32_t H264BitStreamProfile;///< H264 profile level id as defined in https://datatracker.ietf.org/doc/html/rfc6184#section-8.1
/// H265 profile-id.
    uint8_t H265BitStreamProfile;///< H265 profile id as defined in https://datatracker.ietf.org/doc/html/rfc7798#section-7.1

    uint8_t enableQec;///< If set then server will generate additional stats from encoder and run QEC logic
    NvscQecSettings qec;///< Settings to control QEC feature.

    uint32_t startupResolutionHoldTimeMs;///< Time (ms) at start of session that Qos will prevent any resolution changes. Helps prevent overreacting to any startup glitches, ex. initial poor client performance reports.

    uint32_t maxQosFeedbackVersion;///< Highest supported qos feedback version.

    uint32_t maxQosTimingsVersion;///< Highest supported qos client timings version.

    uint32_t maxQosBolbStatsVersion;///< Highest supported qos blob stats version.

    uint16_t highOwdJumpTriggerThreshold;///< Threshold after which OWD spike is considered as OWD jump, expressed as a percentage of the frame duration(16.66 for 60fps)

    uint32_t highOwdJumpDropThresholdMs;///< Trigger bitrate decrease if there are OWD jumps which last longer than this threshold

    uint32_t consFramesWithHighOwdThresholdMs;///< Trigger bitrate decrease if there is consecutive frames with High OWD exceeds this threshold in ms

    uint32_t highOwdThresholdUs;///< For Owd Congestion Control algo, Owd above threshold is considered as High Owd in micro seconds

    uint32_t owdBitrateDropMultiplierPercent;///< Final Owd CC algo bitrate reduction percent will be multiplied by this percentage. Then capped by bwe.stepDownPercent

    uint32_t owdSkipThresholdMs;///< Skips bitrate increase if Owd crosses this threshold for the frame

    uint8_t qosServiceIirCoefficient;///< IIR filter coefficient to estimate cadence of Qos service

    uint8_t frameRecoveryOverride;///< Config used to override the frame loss recovery method, this is of the type NvstVideoStreamRecoveryFlags defined in VideoDecoderUnit.h
    NvscVqosTacticsManagerSettings tacticsManager;///< Settings to control Qos Tactics Manager for the Greedy bitrate algorithm.
    NvscRtcPreemptiveIdrSettings rtcPreemptiveIdrSettings;///< Settings to control preemptive IDR feature for RTC clients.

    uint32_t clientFeedbackCollectionRetryPeriodUs;///< Time (in microseconds) between each client feedback retry when feedback cannot contain all messages
    StatsProcessorThreadSettings statsProcessorThread;///< Settings for Stats Processor thread
}NvscVideoQosSettings;


typedef struct NvscL4SHandling_t
{

    uint8_t version;///< Version of the L4S handling implementation.

    uint8_t enableEcnFeedback;///< Flag controls whether to send the ECN feedback stats from client or not.

    uint8_t frameDataHistorySize;///< Number of frames data to be stored and used to react to ECN feedback.

    uint16_t numFramesHistoryToLookBack;///< Number of non-CE marked frames prior to the CE marked frame to look back while calculating the target packet burst.

    uint8_t iirFilterFactor;///< IIR filter factor for computing the filtered value of target packet burst.

    uint8_t nthPercentileOfFrameSize;///< The N-th percentile of frame size to be used while calculating the target group count.

    uint16_t increaseCooldownTimeMs;///< Time in milliseconds for making the packet pacing config more aggressive.

    uint16_t decreaseCooldownTimeMs;///< Time in milliseconds for relaxing the packet pacing config.

    uint8_t enableQosBitrateAdaptation;///< Enable adaptation of QosBitrateBps according to fraction of sent packets experiencing congestion.

    uint8_t minAlphaBitrateDowngradeX100;///< Min value of congestion estimate Alpha x100 below which the QosBitrateBps will be downgraded.
    MetaParams<uint8_t> minAlphaBitrateDowngradeX100MetaParams;

    uint8_t alphaBitrateAdjustmentFactor;///< Bitrate adjustment factor for congestion-induced QosBitrateBps downgrade. Defaults to 2 as per IETF recommendation.
    MetaParams<uint8_t> alphaBitrateAdjustmentFactorMetaParams;

    uint8_t defaultMaxPPGroupCount;///< Maximum packet pacing group count for sessions where max FPS not one of {30, 60, 120}.
}NvscL4SHandling;

/// Settings for dynamic packet size.
typedef struct NvscDynamicPacketSize_t
{

    uint8_t enable;///< Enable or disable dynamic packet size feature.

    uint32_t frameSizeL0ThresholdBytes;///< Level 0 frame size threshold. It is total frame send size which includes the FEC data also.

    uint32_t packetSizeL0;///< Maximum allowed packet size for frames with packet count less than level 0 threshold. Also includes 16 bytes of RTP extention header

    uint32_t frameSizeL1ThresholdBytes;///< Level 1 frame size threshold. It is total frame send size which includes the FEC data also.

    uint32_t packetSizeL1;///< Maximum allowed packet size for frames having size less than level 1 threshold. Also includes 16 bytes of RTP extention header.
}NvscDynamicPacketSize;

/// Settings for max packet size allowed detection.
typedef struct NvscMaxPacketSizeDetection_t
{

    uint8_t enable;///< Enable or disable max packet size detection.

    uint32_t minNumFrames;///< Minimum number of frames packet loss rate data required to detect the max packet size allowed.

    uint32_t packetLossRate;///< Packet loss rate used to detect the max packet size allowed.
}NvscMaxPacketSizeDetection;

/// Settings for dumping uncompressed input video frames.
typedef struct NvscVideoFrameDumpSettings_t
{

    uint8_t enabled;///< Enable video frame dumping.

    uint16_t memoryUsage;///< MiB's of server system memory to be used to store the frame ring buffer.

    uint16_t capturePeriod;///< Period in which frames are captured. Use 1 to capture all frames, 2 for every-other, etc.

    uint16_t downsampleFactor;///< Downsample scale factor to capture frames. Use 1 for full-size, 2 for half-size, etc.
}NvscVideoFrameDumpSettings;

/// Settings for dumping uncompressed input video frames when exiting.
typedef struct NvscExitVideoFrameDumpSettings_t
{

    uint8_t disabled;///< Disable video frame dumping.
}NvscExitVideoFrameDumpSettings;

/// Settings for dumping uncompressed input video frames.
typedef struct NvscVideoRawFrameDumpSettings_t
{

    uint8_t enabled;///< Enable video frame dumping.

    uint16_t numFrames;///< Number of frames to record.
}NvscVideoRawFrameDumpSettings;

/// Configures frame pacing's PID controller.
typedef struct Pid_t
{

    uint32_t kP;///< Proportional term of PID controller (multiplied by 1000, since there's no support for float fields.

    uint32_t kI;///< Integral term of PID controller (multiplied by 1000, since there's no support for float fields).

    uint32_t kL;///< Maximum allowed accumulation limit for kI (multiplied by 1000, since there's no support for float fields).

    uint32_t targetFrameTimeUs;///< Target video frame time (in microseconds).

    uint32_t minTargetFrameTimeUs;///< Minimum target video frame time (in microseconds).

    uint32_t maxTargetFrameTimeUs;///< Maximum target video frame time (in microseconds).

    uint32_t allowedDeviation;///< Maximum allowed deviation from target frame time (in per milles).

    uint32_t targetQueueTimeUs;///< Target queue time for video frames (in microseconds). Set to 0 to use adaptative target queue time based on frame arrival jitter history.
}Pid;


typedef enum NvscFramePacingRenderEstimationMode_t
{
    FRAME_PACING_RENDER_ESTIMATION_MODE_QUANTILE = 0,///< Use moving quantile estimation.
    FRAME_PACING_RENDER_ESTIMATION_MODE_NORMAL = 1,///< Use gaussian estimation.
}NvscFramePacingRenderEstimationMode;


typedef struct NvscFramePacingRenderHistory_t
{
    NvscFramePacingRenderEstimationMode renderEstimationMode;///< Method of calculating render time bound.

    uint32_t n;///< Approximate number of observations in history. Estimates variance of render times.

    uint32_t maxTimeUs;///< Maximum frame render time to add to jitter advance to compute frame target queue time.

    uint32_t minTimeUs;///< Minimum frame render time to add to jitter advance to compute frame target queue time.

    uint32_t stddevsX1000;///< Estimates render bound time. Sigma(jitter) * stddevs + jitter bound = target queue time. (x1000)

    uint32_t quantileX1000;///< Percentile of frame arrival jitter to use to estimate frame arrival jitter bound.

    uint32_t quantileConvergenceX10000;///< How quickly quantile adjusts. 20/10000 = .0020 = med/slow, 10/10000 = .001 = slow, 100/10000 = 0.01 = fast.
}NvscFramePacingRenderHistory;


typedef enum NvscFramePacingJitterEstimationMode_t
{
    FRAME_PACING_JITTER_ESTIMATION_MODE_QUANTILE = 0,///< Use moving quantile estimation.
    FRAME_PACING_JITTER_ESTIMATION_MODE_NORMAL = 1,///< Use gaussian estimation.
}NvscFramePacingJitterEstimationMode;


typedef struct NvscFramePacingJitterHistory_t
{
    NvscFramePacingJitterEstimationMode jitterEstimationMode;///< Method of calculating frame arrival jitter bound.

    uint32_t n;///< Approximate number of observations in history. Estimates variance of frame arrival jitter. Alpha = 2 / (N + 1).

    uint32_t stddevsX1000;///< Estimates frame target queue time. Sigma(jitter) * stddevs + render bound = target queue time. (x1000). Used directly in normal distribution jitter estimation mode. Used to adjust rate of movement in quantile estimation mode.

    uint32_t quantileX1000;///< Percentile of frame arrival jitter to use to estimate frame arrival jitter bound.

    uint32_t quantileConvergenceX10000;///< How quickly quantile adjusts. 25/10000 = .0020 = med/slow, 10/10000 = .001 = slow, 100/10000 = 0.01 = fast.

    uint32_t quantileWindowSize;///< Jitter data window that is used to calculate quantile. Setting this to a non-zero value means an explicit window will be used, but not smoothed moving estimate.

    uint32_t quantileWindowStep;///< Jitter data moving window offset when percentile gets recalculated. Setting this to a non-zero value means an explicit window will be used, but not smoothed moving estimate.

    uint32_t maxAdvanceUs;///< Max target queue time in microseconds.

    uint32_t minAdvanceUs;///< Min target queue time in microseconds.

    uint32_t outlierUs;///< Drop |jitter| values above this threshold to avoid skewing the variance too far.
}NvscFramePacingJitterHistory;


typedef enum NvscFramePacingMode_t
{
    FRAME_PACING_MODE_NEVER = 0,///< Do not pace frame rendering. Stream at a steady FPS decided by QoS.
    FRAME_PACING_MODE_VIRTUAL_VSYNC = 1,///< Pace frame rendering using Virtual VSync agorithm.
    FRAME_PACING_MODE_REFLEX = 2,///< Pace frame rendering to match streaming FPS. Valid only for apps that have NVIDIA Reflex integrated.
}NvscFramePacingMode;


typedef enum NvscFramePacingFeedbackMode_t
{
    FRAME_PACING_FEEDBACK_NEVER = 0,///< Never send frame pacing feedback.
    FRAME_PACING_FEEDBACK_INTERVAL = 1,///< Send frame pacing feedback together with QoS stats.
    FRAME_PACING_FEEDBACK_PERFRAME = 2,///< Send frame pacing feedback on every frame.
}NvscFramePacingFeedbackMode;

/// Configures render frame pacing
typedef struct NvscFramePacing_t
{
/// Enable extra frame pacing debug logs.
    uint8_t enableExtraDebugLogging;///< Set to 1 to enable extra debug log messages.
    NvscFramePacingFeedbackMode feedbackMode;///< When to send this feedback: never, once per frame, or together with QoS stats.
    NvscFramePacingMode mode;///< Algorithm to use to pace frame rendering and streaming.

    uint32_t feedbackTimeoutMs;///< Frame pacing feedback arrival timeout (in milliseconds seconds).

    uint32_t queueSmoothingHistoryN;///< Approximate number of observations in frame queue time history. Estimates frame queue time average.

    uint32_t queueHistoryOutlierUs;///< Clamp frame queue times above this threshold to avoid skewing the average too far.

    uint32_t frameDropThresholdMultipleX1000;///< Multiple of target queue time at which frames with a pending queue time outside this value should be dropped from the render queue.

    uint32_t deactivationThresholdFpsX1000;///< Frame pacing gets deactivated if FPS rate deviates more than the threshold value. The default value is 50, meaning 50/1000, i.e., 5%.

    uint32_t streamingFpsSmoothingHistoryLength;///< Approximate number of observations in streaming FPS history. Estimates stremaing FPS average.

    uint32_t activationDelayMs;///< Feature activation delay interval in milliseconds.

    uint32_t deactivationDelayMs;///< Feature deactivation delay interval in milliseconds.

    uint32_t maxQueuedFrames;///< Maximum number of queued frames. Exceeding this number causes client re-syncs.
    NvscFramePacingJitterHistory jitterHistory;///< Frame pacing frame arrival jitter history estimation parameters.
    NvscFramePacingRenderHistory renderHistory;///< Frame pacing frame client render history estimation parameters.
    Pid pid;///< Frame pacing's PID controller's parameters. See https://www.animatics.com/support/knowledge-base/pid-control for explanation of kP, kI, and kL.
}NvscFramePacing;

/// Available multi pass configs for video encoding.
typedef enum NvscEncoderMultiPass_t
{
    NVSC_ENC_MULTI_PASS_DEFAULT,///< Default multi pass config.
    NVSC_ENC_MULTI_PASS_DISABLED,///< Single Pass.
    NVSC_ENC_TWO_PASS_QUARTER_RESOLUTION,///< Two Pass encoding is enabled where first Pass is quarter resolution.
    NVSC_ENC_TWO_PASS_FULL_RESOLUTION,///< Two Pass encoding is enabled where first Pass is full resolution.
}NvscEncoderMultiPass;

/// Available presets for video encoding. Note that presets P1 to P7 have been introduced to provide a fine grained performance/quality trade off.                      P1 provides the highest performance and least quality while P7 provides the highest quality and least performance.
typedef enum NvscEncoderPreset_t
{
    NVSC_ENC_PRESET_INVALID = -1,///< Not a valid preset.
    NVSC_ENC_PRESET_DEFAULT,///< Default preset.
    NVSC_ENC_PRESET_HP,///< High performance preset.
    NVSC_ENC_PRESET_HQ,///< High quality preset.
    NVSC_ENC_PRESET_BD,///< Blueray preset.
    NVSC_ENC_PRESET_LOW_LATENCY,///< Low latency preset.
    NVSC_ENC_PRESET_LOW_LATENCY_HQ,///< Low latency HQ preset.
    NVSC_ENC_PRESET_LOW_LATENCY_HP,///< Low latency HP preset.
    NVSC_ENC_PRESET_LOSSLESS,///< Lossless preset.
    NVSC_ENC_PRESET_LOSSLESS_HP,///< LossLess HP preset.
    NVSC_ENC_PRESET_NVENC_P1,///< NV Encoder Preset 1.
    NVSC_ENC_PRESET_NVENC_P2,///< NV Encoder Preset 2.
    NVSC_ENC_PRESET_NVENC_P3,///< NV Encoder Preset 3.
    NVSC_ENC_PRESET_NVENC_P4,///< NV Encoder Preset 4.
    NVSC_ENC_PRESET_NVENC_P5,///< NV Encoder Preset 5.
    NVSC_ENC_PRESET_NVENC_P6,///< NV Encoder Preset 6.
    NVSC_ENC_PRESET_NVENC_P7,///< NV Encoder Preset 7.
}NvscEncoderPreset;

/// Available multi-reference encoding feature control settings.
typedef enum NvscEncoderMultiRefFeatureSetting_t
{
    NVSC_ENC_ENABLE_MULTIREF_FOR_ALL_FORMATS = 0x0,///< Enable multi-reference encoding for all codec formats.
    NVSC_ENC_DISABLE_MULTIREF_H264 = 0x1,///< Disable multi-reference encoding for H264 format.
    NVSC_ENC_DISABLE_MULTIREF_FOR_H265 = 0x2,///< Disable multi-reference encoding for H265 format.
    NVSC_ENC_DISABLE_MULTIREF_FOR_AV1 = 0x4,///< Disable multi-reference encoding for AV1 format.
}NvscEncoderMultiRefFeatureSetting;

/// Available encoder features.
typedef enum NvscEncoderSettings_t
{
    ENABLE_SPLIT_ENCODE = 0x1,///< Enable split encode if supported.
    ENABLE_4K_2PASS_RC = 0x2,///< Use 2-pass quality rate control mode for 4K-HEVC on Pascal.
    FEATURE_4K_1x_VBV = 0x4,///< Use 1x VBV buffer size with 2-pass quality RC mode for 4K60.
    FEATURE_SPATIAL_AQ = 0x8,///< Enable Spatial AQ in rate control for 4K60.
    FEATURE_KEY_FRAME_SCALE = 0x10,///< Enable key frame scale in NVSC_RC_CBR_TWO_PASS rate control mode.
    FEATURE_FAKE_ENCODE_FPS = 0x20,///< Enable fake encode fps for turbo mode only.
    FEATURE_EMPHASIS_MAP = 0x40,///< Enable usage of Emphasis map in the encoder.
    OVERRIDE_ENCODE_PRESET = 0x80,///< Enable override of video encoder preset.
    DISABLE_MULTI_REFERENCE = 0x100,///< Disable multi-reference encoding.
    FORCE_ENABLE_SPATIAL_AQ = 0x200,///< Force Enable Spatial AQ in rate control.
}NvscEncoderSettings;

/// Available rate control modes for video encoding.
typedef enum NvscRateControlMode_t
{
    NVSC_RC_INVALID = -1,///< Not a valid RC mode.
    NVSC_RC_CONSTQP,///< Constant quantization parameter.
    NVSC_RC_VBR,///< Variable bitrate.
    NVSC_RC_CBR,///< Constant bitrate.
    NVSC_RC_VBR_MINQP,///< Variable bitrate with minimum quantization parameter.
    NVSC_RC_CBR_TWO_PASS,///< Constant bitrate using two pass encoding.
    NVSC_RC_TWO_PASS_FRAMESIZE_CAP,///< Multi pass encoding optimized for maintaining frame size.
    NVSC_RC_NUM_MODES,///< Not a valid RC mode.
}NvscRateControlMode;


typedef enum NvstWaitMethod_t
{
    NVST_WM_UNDEFINED = 0,///< Wait method undefined (use server setting).
    NVST_WM_NO_WAIT = 1,///< Don't wait.
    NVST_WM_WAIT_WITH_TIMEOUT = 2,///< Wait with timeout.
    NVST_WM_WAIT_EVENT_NOCURSOR_WITH_TIMEOUT = 3,///< Windows only: Wait for event w/ timeout, ignore cursor updates.
    NVST_WM_NO_WAIT_IF_FRAME_READY = 4,///< Linux only: Only wait if there isn't a new frame.
    NVST_WM_NO_WAIT_FORCE_REFRESH = 5,///< Linux only: Don't wait.  Force frame refresh.
}NvstWaitMethod;


typedef enum NvstSleepMethod_t
{
    NVST_SM_UNDEFINED = 0,///< Sleep method undefined (use server setting).
    NVST_SM_NORMAL_SLEEP = 1,///< Use normal sleep.
    NVST_SM_CPU_POLL_SLEEP = 2,///< Use CPU polling-based sleep.
    NVST_SM_WAITABLE_TIMER = 3,///< Use timer-based sleep.
    NVST_SM_WAITABLE_TIMER_BUSYWAIT = 4,///< Use timer-based sleep + busy wait.
    NVST_SM_NORMAL_SLEEP_BUSYWAIT = 5,///< Use normal sleep + busy wait.
}NvstSleepMethod;


typedef enum NvstCaptureMethod_t
{
    NVST_CM_UNDEFINED = 0,///< Capture method undefined (use server setting).
    NVST_CM_BASIC_SLEEP = 1,///< Use basic sleep capture method.
    NVST_CM_ADJUSTED_SLEEP = 2,///< Use adjusted sleep capture method.
    NVST_CM_CONSTANT_SLEEP = 3,///< Use constant sleep capture method.
    NVST_CM_WAIT_FOR_VBLANK = 4,///< Use wait for vblank-based capture method.
}NvstCaptureMethod;

/// Struct storing details about capture settings.
typedef struct NvstCaptureSettings_t
{

    uint32_t captureStrategy;///< Capture strategy.
    NvstCaptureMethod captureMethod;///< Capture method.
    NvstSleepMethod sleepMethod;///< Sleep method.

    uint16_t sleepMethodAccuracyUs;///< Sleep method accuracy in microseconds, used for busy wait.
    NvstWaitMethod waitMethod;///< Video frame provider wait method.

    uint16_t waitMethodTimeoutMs;///< Video frame provider wait method timeout in milliseconds, if applicable.

    uint8_t enableLinuxDirectCapture;///< Enables a Linux server to use direct capture, when available.  Default 1.  Set to 0 to disable.
}NvstCaptureSettings;

/// Available H264 levels for video encoding.
typedef enum NvscH264Level_t
{
    NVSC_H264_LEVEL_INVALID = -1,///< Not a valid H264 level
    NVSC_H264_LEVEL_41 = 41,///< H264 Level 4.1
    NVSC_H264_LEVEL_42 = 42,///< H264 Level 4.2
    NVSC_H264_LEVEL_50 = 50,///< H264 Level 5.0
    NVSC_H264_LEVEL_51 = 51,///< H264 Level 5.1
    NVSC_H264_LEVEL_52 = 52,///< H264 Level 5.2
    NVSC_H264_LEVEL_60 = 60,///< H264 Level 6.0
}NvscH264Level;

/// Available codec levels for video encoding.
typedef enum NvscCodecLevel_t
{
    NVSC_CODEC_LEVEL_INVALID = -1,///< Not a valid codec level
    NVSC_CODEC_LEVEL_41 = 41,///< Video Codec Level 4.1
    NVSC_CODEC_LEVEL_42 = 42,///< Video Codec Level 4.2
    NVSC_CODEC_LEVEL_50 = 50,///< Video Codec Level 5.0
    NVSC_CODEC_LEVEL_51 = 51,///< Video Codec Level 5.1
    NVSC_CODEC_LEVEL_52 = 52,///< Video Codec Level 5.2
    NVSC_CODEC_LEVEL_60 = 60,///< Video Codec Level 6.0
}NvscCodecLevel;

/// Struct storing details about video configuration settings
typedef struct NvscVideoSettings_t
{

    uint8_t perfIndicatorEnabled;///< Enables perf indicator.

    uint32_t clientViewportWd;///< Width of the view port.

    uint32_t clientViewportHt;///< Height of the view port.

    uint32_t adapterNumber;///< The adapter to which the client is connecting.

    uint32_t maxFPS;///< Maximum allowed streaming framerate.

    uint8_t syncCapturedAndStreamingFps;///< Sync captured FPS and streaming FPS.
    NvscCodecLevel maxCodecLevel;///< Maximum Video Codec Level.

    uint32_t maxCodecProfile;///< Maximum Video Codec Profile.
    NvscH264Level maxH264Level;///< Maximum H.264 Level.

    uint32_t maxH264Profile;///< Maximum H.264 Profile.

    uint32_t streamRecoveryType;///< Bitfield indicating the recovery types supported by the decoder.

    uint32_t maxNumReferenceFrames;///< Override config for maximum number of reference frames. For standard compliant decoders, leave this at zero.

    uint32_t contextType;///< Video context type to be used on server side (CUDA=8/DX9=9/DX11=10), server may ignore unsupported types.
    NvstCaptureSettings captureSettings;///< Capture settings
    NvscTransferProtocol transferProtocol;///< Transfer protocol used to transmit frames.
    NvscRateControlMode rateControlMode;///< Rate control method used by encoder.
    NvscEncoderSettings encoderFeatureSetting;///< This is to control various features on encoder settings.
    NvscEncoderMultiRefFeatureSetting encoderMultiRefFeatureSetting;///< This is to control the multi-reference encoding feature.
    NvscEncoderPreset encoderPreset;///< Preset used by encoder.

    uint8_t overrideEncoderPreset;///< Used to force override the encoder preset with the one given in encoderPreset, disabled by default.

    uint32_t initialQp;///< Initial QP at the start of streaming. Set to 35 so first few frames are not too large.

    uint32_t minQp;///< Minimum possible QP used for streaming. Actual qp is limited by vqos[i].maximumBitrateKbps. Default is 18 for WAR to Kepler bug to prevent possible bitrate spikes

    uint8_t maxQpForPFrame;///< Value greater than 0 will allow to use maximum QP for rate control. This also specifies the max possible QP used for P-frames during streaming.

    uint32_t lowQpBitrateKbps;///< Below this bitrate (in kbps), allow the encoder to lower the minimum QP to the value set by minQp (see above). This will override the QPG.

    uint16_t videoBitrateIirFactor;///< Filtering factor for video bitrate estimation.

    uint32_t initialBitrateKbps;///< Target bitrate in kbps. Used before QoS is triggered.

    uint32_t initialPeakBitrateKbps;///< Peak bitrate in kbps. Used before QoS is triggered, ignored with CBR rate control mode.

    uint32_t vbvMultiplier;///< Percentage of average frame size used for VBV buffer size.

    uint8_t keyFrameScale;///< Allowed frame size increase factor for scene change frame.

    uint8_t fakeEncodeFps;///< Faked encode FPS for turbo mode only, used to limit encoded stream level to ease client processing requirements.

    uint32_t numTemporalLayers;///< No. of total layers in temporal/hierP encoding.
    NvscEncoderMultiPass encoderMultiPass;///< Force multi pass config used by encoder.

    uint8_t allowOverrideEncoderMultiPassFor4k;///< Used to allow or not allow to override the encoder multi pass config for 4k resolution when split encode is disabled. Value: 0 - Does not allow, 1 - Allow.

    uint32_t packetSize;///< Maximum allowed packet size. Also includes 16 bytes of RTP extention header

    uint8_t mtuPacketSizeControl;///< Flag controls whether to use MTU value determined by NCT as packet size in streamer or not.

    uint8_t refPicInvalidation;///< Whether or not to allow invalidating a range of encoded reference frames based on timestamps.

    uint8_t skipFramesWaitingForIdr;///< Whether or not to allow skip forwarding the assembled frames other than IDR and Intra refresh frames from NVSC to client while waiting for an IDR frame.

    uint32_t pingBackIntervalMs;///< Interval between ping messages sent to the server to indicate that the client is still alive, in milliseconds.

    uint32_t pingBackTimeoutMs;///< Timout interval used by server to disconnect dead client, in milliseconds.

    uint32_t timeoutLengthMs;///< Length in milliseconds of timeout used when sending protocol messages. /// @todo decide where it fits best logically

    uint8_t fullFrameAssembly;///< \todo Whether frames are done as whole or as slices.

    uint8_t enableIntraRefresh;///< Whether to enable intra refresh

    uint8_t enableLongTermReferences;///< Whether to enable long term references

    uint32_t framesWithInvalidRefThreshold;///< threshold for number of frames with invalid reference to be sent to decoder

    uint32_t consecutiveFrameLostThreshold;///< number of consecutive frames lost threshold

    uint32_t videoEncoderDeblockingMode;///< H.264 encoder deblocking filter mode

    uint32_t videoEncoderSlicesPerFrame;///< No. of slices into which frames are divided

    uint32_t videoSplitEncodeStripsPerFrame;///< No. of strips into which frames are divided

    uint8_t updateSplitEncodeStateDynamically;///< Flag controls whether to update the split encode state dynamically based on the resolution type or not.

    uint32_t dynamicRangeMode;///< Dynamic range modes: 0 - SDR, 1 - HDR, 2 - EDR.

    uint8_t fbcDynamicFpsGrabTimeoutMs;///< Timeout for FBC grab in ms for Turbo Mode Streaming

    uint8_t enableVrStreamingMode;///< Whether to enable VR streaming mode
    NvstSurfaceFormat surfaceFormat;///< Surface format used by video stream.
    NvscFramePacing framePacing;///< Render frame pacing config
    NvstCscMode encoderCscMode;///< RGB Ycbcr Conversion method used by encoder.
    NvscVideoRawFrameDumpSettings rfd;///< Video Frame Dumping Settings
    NvscExitVideoFrameDumpSettings efd;///< Exit Video Frame Dumping Settings
    NvscVideoFrameDumpSettings fd;///< Video Frame Dumping Settings

    uint32_t enableFbcDiffMap;///< Enable/Disable FBC Difference map feature, by default is is disabled

    uint8_t disableFrameScaling;///< Disable video frame scaling.

    uint8_t dx9EnableNv12;///< Enable nv12 frame format for dx9 stream.

    uint8_t dx9EnableHdr;///< Enable HDR for dx9 stream.

    uint8_t enableNextCaptureMode;///< Enable next capture mode.

    uint32_t sendFrameTimeoutMs;///< Timeout for the video sender thread to complete one iteration

    uint32_t sendFirstFrameTimeoutMs;///< Timeout for the video sender thread to complete the first iteration

    uint32_t senderDequeueTimeoutMs;///< Timeout for the video sender thread to dequeue from the video unit queue.

    uint16_t enableTimestampRender;///< Enable client side timestamp based video frame rendering. Values: 0 = disable on all platforms. 1 = enable on all platforms. Otherwise bitfield enabling per platform: (bit 2 = Windows, bit 3 = macOS, bit 4 = Linux, bit 5 = Android, bit 6 = iOS, ...)

    uint16_t enableAdaptiveQRender;///< Enable client side adaptive queue video frame rendering (ts render 2.0). Values: 0 = disable on all platforms. 1 = enable on all platforms. Otherwise bitfield enabling per platform: (bit 2 = Windows, bit 3 = macOS, bit 4 = Linux, bit 5 = Android, bit 6 = iOS, ...)

    uint8_t enableRtpNack;///< Disable[0]/Enable[1] retransmission of RTP packets using NACK mechanism

    uint8_t rtpNackBackoffTimeMs;///< Time in ms for which NACK logic waits before sending the next pending NACK request

    uint8_t rtpNackInitialWaitTimeMs;///< Time in ms for which NACK logic waits before sending the first pending NACK request

    uint8_t rtpNackMaxPacketCount;///< Max number of packets that can be NACKed in a single request

    uint32_t rtpNackQueueLength;///< Max number of packets (should be 2^N) that will be maintained in the RTP Queue

    uint8_t enableADJB;///< Disable[0]/Enable[1] Adaptive Dejitter Buffer

    uint8_t adjbMinLengthMs;///< Min DJB length for ADJB

    uint8_t adjbMaxLengthMs;///< Max DJB length for ADJB

    uint32_t adjbQuantile;///< Jitter history quantile for ADJB

    uint32_t adjbQuantileConvergenceFactor;///< Jitter history quantile convergence factor for ADJB

    uint8_t dejitterBufferLengthMs;///< The length of dejitter buffer in time, for 2 frames at 60fps this will be 32ms

    uint16_t nackDjbLengthMultiplyFactorx100;///< Multiplication factor for dejitter buffer length in time that used to decide the state of the NACK feature (x100 since float values are not supported)

    uint16_t nackHysteresisLengthUs;///< Hysteresis length in time that gets deducted from the dejitter buffer length to decide the state of the NACK feature when NACK feature is not enabled already

    uint16_t rtpNackQueueMaxPackets;///< Maximum packet count allowed in RTP out of order queue when NACK is active.

    uint8_t rtpNackDjbInteractionMode;///< Config to enable Nack DJB interaction.
    NvscMaxPacketSizeDetection packetSizeDetection;///< Max packet size detection settings
    NvscDynamicPacketSize dynamicPacketSize;///< Dynamic packet size settings

    uint8_t appendVideoTimingExtnAudNal;///< Specific to RTC clients, controls whether AUD NAL containing video-timing RTP extension must be appended to end of frame.

    uint8_t mapRtpTimestampsToFrames;///< Specific to RTC clients, determines if the server needs to map RTP timestamps from the client to server frame numbers
    NvscL4SHandling l4sHandling;///< Settings to control L4S handling feature.
}NvscVideoSettings;

/// Defines the API marking method used for marking.
typedef enum SelectionEnforcementMethod_t
{
    WINSOCK = 0x0,///< Use Winsock2 API to enforce the packet marking. Note that without elevated privileges, this API is limited to few codepoints only.
    RIVERMAX = 0x01,///< Use Rivermax API to enforce the packet marking. Note this API requires a supported NIC and driver setup on sender.
}SelectionEnforcementMethod;

/// Defines the header marking method used to translate the transit selection value.
typedef enum SelectionType_t
{
    DSCP = 0x0,///< Use DSCP codepoints for packet marking purposes.
    TTL = 0x01,///< Use TTL ranges for packet marking purposes.
}SelectionType;


typedef struct TransitSelectionSettings_t
{

    uint8_t enableDynamicTransitSelection;///< Specify if to use the transit selection logic. '0' disables the feature and continues using qosTrafficType for service class differentiation only.
    MetaParams<uint8_t> enableDynamicTransitSelectionMetaParams;

    uint8_t selectionValue;///< Transit behavior to be applied for AV streaming packets. '0' (untagged) is the default behavior.
    MetaParams<uint8_t> selectionValueMetaParams;

    char allSelectionValues[64];///< Comma-separated list of transit selection options available to the streamer for PBR. '0' (untagged) will result in natural BGP routing.

    uint8_t relyOnRuntimeParams;///< Either rely on runtime params (=='1') or config XML (=='0') for sourcing default transit value and transit alternatives.
    MetaParams<uint8_t> relyOnRuntimeParamsMetaParams;
    SelectionType selectionType;///< Marking selection type setting.
    SelectionEnforcementMethod selectionEnforcementMethod;///< Marking enforcement method setting.

    uint8_t selectionTTLRange;///< When using TTL as the marking method, defines the TTL range length reserved for a single selection value.
    MetaParams<uint8_t> selectionTTLRangeMetaParams;
}TransitSelectionSettings;

/// Struct storing details about the feature settings which can be forced periodically to capture the bitstream dump .
typedef struct NvscForcedPeriodicSettings_t
{

    uint16_t resolutionChangeInterval;///< Forces a resolution change periodically for the mentioned number of frames.

    uint16_t frameInvalidationInterval;///< Forces a frame invalidation periodically for the mentioned number of frames.

    uint16_t invalidationFrameRange;///< Periodic frame invalidation frame range. Server will drop the mentioned number of frames while forcing the periodic frame invalidation.

    uint8_t dumpDroppedFramesDueToInvalidation;///< Used to dump or not to dump the dropped frames while forcing the periodic frame invalidation into the server-side bitstream dump . Value: 0 - Do not dump, 1 - Dump.
}NvscForcedPeriodicSettings;


typedef enum ipVersionMode_t
{
    INVALID_IP = 0,///< Invalid IP
    IPV4 = 4,///< IP version 4
    IPV6 = 6,///< Ip version 6
}ipVersionMode;


typedef enum recoveryMode_t
{
    RECOVERY_MODE_DISABLED = 0,///< Recovery mode disabled
    RECOVERY_MODE_ENABLED = 1,///< recovery mode enabled
}recoveryMode;

/// The URL scheme for RTSP signaling.  Legacy is rtsp:// or rtsps://
typedef enum RtspScheme_t
{
    RTSP_SCHEME_LEGACY = 0x0,///< Use legacy scheme: rtsp:// or rtsps://
    RTSP_SCHEME_WEB_SOCKET = 0x2,///< Use an unencrypted web socket.
    RTSP_SCHEME_SECURE_WEB_SOCKET = 0x3,///< Use a secure web socket.
    RTSP_SCHEME_UNDEFINED = 0x4,///< Use the parameters provided in the connection config to determine the scheme.
}RtspScheme;

/// Features to be used on next connect call.
typedef enum NvscFeatureFlags_t
{
    NVSC_FEATURE_VIDEO = 0x1,///< Use video streaming.
    NVSC_FEATURE_AUDIO = 0x2,///< Use audio streaming.
    NVSC_FEATURE_REMOTE_INPUT = 0x4,///< Use remote input.
    NVSC_FEATURE_ENCRYPT_VIDEO = 0x10,///< Encrypt video.
    NVSC_FEATURE_ENCRYPT_AUDIO = 0x20,///< Encrypt audio.
    REMOVED_NVSC_FEATURE_ENCRYPT_REMOTE_INPUT = 0x40,///< (REMOVED) Encrypt remote input. (use NVSC_FEATURE_ENCRYPT_CONTROL_CHANNEL instead)
    NVSC_FEATURE_ENCRYPT_CONTROL_CHANNEL = 0x80,///< Encrypt control channel traffic.
}NvscFeatureFlags;

/// Available uses for network ports.
/// \sa NvscServerEndpoint
typedef enum NvscPortUsage_t
{
    NVSC_PU_INVALID = -1,///< Not a valid port usage.
    NVSC_PU_CONTROL,///< Port is used to transport control messages.
    NVSC_PU_VIDEO,///< Port is used to transport video.
    NVSC_PU_AUDIO,///< Port is used to transport audio.
    NVSC_PU_INPUT,///< Port is used to transport input event messages.
    NVSC_PU_SIGNALING,///< Port is used to transport signaling(RTSP) traffic.
    NVSC_PU_MIC,///< Port is used to transport mic audio.
    NVSC_PU_SECURE_SIGNALING,///< Port is used to transport secure signaling(RTSPS) traffic.
    NVSC_PU_BUNDLE,///< Port is used to transport all streaming traffic.
}NvscPortUsage;

/// Struct storing details about a server port.
typedef struct NvscServerEndpoint_t
{

    uint16_t portNumber;///< Port number.
    NvscTransferProtocol protocol;///< Protocol used.
    NvscPortUsage usage;///< Intended use.

    char serverIp[512];///< Null terminated string of the server address of this Stream. It may be Hostname or Ip address
}NvscServerEndpoint;


typedef enum EnetSequenceWindowsPartiallyReliable_t
{
    ENET_PEER_WAIT_WINDOW_PARTIALLY_RELIABLE = 2,///< Packet seq delta beyond which receiver drops missing part-reliable packet
}EnetSequenceWindowsPartiallyReliable;


typedef enum ReliabilityType_t
{
    TYPE_RELIABLE = 0,///< Fully reliable, sequenced and acked, transmitted indefinitely
    TYPE_PARTIALLY_RELIABLE,///< Partially reliable, sequenced and acked, limited transmissions
    TYPE_UNRELIABLE,///< Unreliable, unsequenced and unacked, transmitted once
}ReliabilityType;

/// Struct with mutli channel feature control flag and number of channels.
typedef struct EnetControlChannel_t
{

    uint8_t channelCount;///< Number of sub channels for the control socket
    ReliabilityType reliabilityType;///< Different types of messages for enet control channel

    uint8_t qosReliabilityType;///< Reliability type for transmission of QoS messages

    uint32_t clientQosTrafficType;///< QoS Traffic type for control channel data used in Qos flow DSCP setting

    uint8_t maxTxPartiallyReliable;///< Max number of transmissions for partially reliable messages
    EnetSequenceWindowsPartiallyReliable enetSequenceWindowsPartiallyReliable;///< Different window sizes to configure behavior of partial reliability in ENet

    uint8_t waitWindowPartiallyReliable;///< Size of wait window beyond which ENet drops missing partially reliable packets

    uint32_t mtuSize;///< MTU size to control fragmentation at the ENet layer

    uint32_t enetReTxAttemptsMax;///< Max value of retransmission before we send a telemetry event to report high outgoing command attempts

    uint32_t timeoutMaximumMs;///< Maximum timeout for all peers at the ENet layer

    uint16_t pingBackTimeoutMs;///< Timout interval used by server's control channel to disconnect dead client, in milliseconds.

    uint32_t clientEnetStatsIntervalMs;///< Time interval in ms between successive sends of client ENet stats

    uint8_t packetStateLogging;///< Log life cycle of each enet packet in the form of states
}EnetControlChannel;

/// Struct storing details about nvsc client ports.
typedef struct NvscClientPorts_t
{

    char localAddress[512];

    uint8_t useReserved;///< Enable fixed ports to leverage router QoS. Value: 0 - disable, : 1 - enable

    uint8_t fallbackDynamic;///< Client port selection to fall back to using dynamic ports when the desired ports are already in use.

    uint16_t session;///< Client session initiation (currently over RTSP) port number.

    uint16_t audio;///< Client audio port number.

    uint16_t mic;///< Client mic port number.

    uint16_t video;///< Client video port number.

    uint16_t control;///< Client control port number.

    uint16_t bundle;///< Client BUNDLE port number.
}NvscClientPorts;

/// Struct storing details about a client interface.
typedef struct NvscClientInterface_t
{

    uint8_t usePreferred;///< Tell NVSC client to pick the preferred network interface to use. Value: 0 - let OS pick an interface; 1 - use the preferred interface.
}NvscClientInterface;

/// Struct storing details about general configuration settings
typedef struct NvscGeneralSettings_t
{
    NvscClientInterface clientInterface;
    NvscClientPorts clientPorts;///< Details about ports used by the clients. Unused entries must be zeroed out.
    EnetControlChannel enetControlChannel;///< Details about multi channel implementation of control socket for enet
    NvstServerNetwork serverNetwork;///< Server network the session belongs to.
    NvscServerEndpoint serverEndpoints[20];///< Details about endpoints used by the server. Unused entries must be zeroed out.

    uint32_t videoSyncAudioDelayAdjust;///< reduce delay of video frame when we synchronize the next video frame based on its capture timestamp

    uint64_t startTime;///< Reference system start time used by both audio and video thread. It is used in conjunction with Video/AudioSyncOffsets
    NvscFeatureFlags featureFlags;///< Features used in current session.

    uint8_t enableInputEventLogging;///< Whether to capture input events.

    uint8_t usedOnlyInSnoopyTests ;///< Used in snoopy tests.

    uint8_t serverCapture;///< Whether or not to capture video stream to file on server. /// \todo Move to runtime

    uint8_t clientCapture;///< Whether or not to capture video stream to file on client. /// \todo Move to runtime

    char outputFolder[MAX_PATH];///< Client data output folder.for stats, pcaps and event tracing files.

    uint32_t rtpQueueMaxPackets;///< Maximum packet count allowed in RTP out of order queue.

    uint32_t rtpQueueMaxDurationMs;///< Maximum duration in ms permitted for RTP out of order queue.

    uint16_t rtpQueueMaxFrameWaitDurationMs;///< Maximum duration in ms permitted for RTP out of order queue to wait for packets of a frame.

    uint8_t rtpEnablePacketCounter;///< Feature enable flag for RTP packet counter for early drop of packets based on assemblable frames.

    uint8_t measureRtpInactivityTime;///< Config which controls if we need to measure RTP inactivity time, value of 0 disables the feature

    uint8_t useReliableUdp;///< Use reliable UDP for control channel.

    uint8_t customMessageOnCC;///< Whether or not to use control channel to transfer custom message.

    uint8_t rtcDataChannelOnNativeBundle;///< Whether or not to use data channel on SCTP as the control channel protocol.

    uint8_t rtcVideoOnNativeBundle;///< Whether or not to use RTC compliant video on native streaming.

    uint8_t rtcAudioOnNativeBundle;///< Whether or not to use RTC compliant audio on native streaming.

    uint8_t rtcMicOnNativeBundle;///< Whether or not to use RTC compliant microphone on native streaming.

    uint8_t nativeRtcOnBundlePort;///< Whether or not to use bundle port for native RTC traffic
    RtspScheme rtspScheme;///< The URL scheme for RTSP signaling.  Legacy is rtsp:// or rtsps://

    uint8_t RtspsClientFeature;///< Placeholder flag to avoid streaming termination in old clients still sending this value.

    char pemCertPath[NVST_MAX_PEM_CERT_PATH];///< Path on file system where CA for selfigned server certificate is located.

    char iceUserNameFragmentV2[ICE_STRING_LENGTH];///< ICE username fragment.

    char icePasswordV2[ICE_STRING_LENGTH];///< ICE password.

    char dtlsFingerprintV2[DTLS_FINGERPRINT_LENGTH];///< DTLS fingerprint.

    uint8_t filterLocalIp;///< Filter same local IPs for hole punching address list. Disable this for Snoopy only

    uint8_t videoStreamerCount;///< Number of video streamers.

    uint32_t serverNATType;///< The server's NAT type.

    uint32_t clientNATType;///< The client's NAT type.
    recoveryMode enableRecoveryMode;///< Recovery mode on client.

    uint16_t recoveryModeTriggerThresholdMs;///< Time in msec before server recovery mode is triggered due to increased TxRxLag.

    uint8_t enableIntraRefreshInRecoveryMode;///< To enable IntraRefresh wave during Recovery mode

    uint32_t controlChannelStatsTransmitIntervalMs;///< Interval (ms) and feature toggle (0 = disable) to transmit control channel stats.

    uint32_t uplinkStatsCollectionIntervalMs;///< Interval (ms) for collection of uplink stats.

    uint8_t useQosForAudioStats;///< Use Video/Qos channel to send aggregated audio and video stats to server.

    uint32_t maxQosMessagesSize;///< Maximum allowed QoS messages buffer sie.
    ipVersionMode ipVersion;///< Ip version to create socket and addresses.
    NvstConnectionType clientConnectionType;///< Network connection type
    NvstConnectionSubType clientConnectionSubType;///< Network connection sub type

    uint8_t logSpsHeader;///< Log SPS header while sending an I-Frame: 0 - disabled, 1 - enabled

    uint8_t pingVersion;///< Provides ability to set the ping version.

    uint8_t readTosField;///< TOS feild read control: 0 - disabled, 1 - enabled

    uint8_t clientSupportsIntraRefresh;///< Whether the platform/client supports intra refresh: 1 - supported, 0 - unsupported

    uint8_t decodeFpsAdjPercent;///< Adjustment factor for the client's decoder performance estimate. Set to 0 to ignore this client estimate for Perf History.

    uint8_t renderFpsAdjPercent;///< Adjustment factor for the client's render performance estimate. Set to 0 to ignore this client estimate for Perf History.

    uint32_t groupBlobStatsBufferSizeBytes;///< Max size of blob data buffered before flushing to ETL, 0 to disable Group blob stats feature.
    NvscForcedPeriodicSettings forcedPeriodicSettings;///< Details about feature settings which can be forced periodically.

    uint8_t sendFrameSizeInGsExtnHeader;///< Feature toggle to either send or not send frame size in the GS Frame extension header
    TransitSelectionSettings transitSelectionSettings;///< Settings to control per-packet transit behavior.
}NvscGeneralSettings;

/// Struct storing stream configuration and options.
/// \remarks
/// Stream configuration is specified when invoking nvstConnectToServer().
/// \sa nvstConnectToServer
typedef struct NvscClientConfig_t
{

    NvstVideoDecoder videoDecoder;///< Information about the H.264 decoder.
    NvscGeneralSettings general;///< General Configuration Settings
    NvscVideoSettings video[VIDEO_STREAM_MAX_COUNT];///< Video Configuration Settings
    NvscVideoQosSettings vqos[VIDEO_STREAM_MAX_COUNT];///< Video QoS configuration settings
    NvscQosScore qscore;///< Describe the parameters for Qos scores.
    NvscAudioQosSettings aqos;///< Audio QoS configuration settings
    NvscRuntimeSettings runtime;///< Runtime Configuration Settings
    NvscRiSettings ri;///< Remote Input Configuration Settings
    NvscAudioSettings audio;///< Audio settings
    NvscMicAudioSettings mic;///< Mic settings
    NvscAudioBitrateSettings audioBitrate;///< Audio Bitrate Configuration
    NvscBWEstimator bwe;///< Bandwidth Estimation Configuration Settings
    NvscClientPerfBrControl clientPerfBr;///< Settings to control bitrate based on client performance feedback.
    NvscPacketPacing packetPacing;///< Settings to control packet pacing feature.
}NvscClientConfig;
