// Copyright NVIDIA Corporation 2017 - 2022
// TO THE MAXIMUM EXTENT PERMITTED BY APPLICABLE LAW, THIS SOFTWARE IS PROVIDED
// *AS IS* AND NVIDIA AND ITS SUPPLIERS DISCLAIM ALL WARRANTIES, EITHER EXPRESS
// OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
// MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  IN NO EVENT SHALL
// NVIDIA OR ITS SUPPLIERS BE LIABLE FOR ANY SPECIAL, INCIDENTAL, INDIRECT, OR
// CONSEQUENTIAL DAMAGES WHATSOEVER (INCLUDING, WITHOUT LIMITATION, DAMAGES FOR
// LOSS OF BUSINESS PROFITS, BUSINESS INTERRUPTION, LOSS OF BUSINESS
// INFORMATION, OR ANY OTHER PECUNIARY LOSS) ARISING OUT OF THE USE OF OR
// INABILITY TO USE THIS SOFTWARE, EVEN IF NVIDIA HAS BEEN ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGES.

/// \file VideoDecoder.h
/// Defines the interface between the streaming core and a platform specific video decoder.

#pragma once

#include <stdbool.h>
#include <stdint.h>

#include "../common/VideoDecodeUnit.h"
#include "../common/VideoFormat.h"

#if defined(__cplusplus)
extern "C"
{
#endif

/// \addtogroup Video
/// @{

/// Use standard limits for maximum number of reference frames.
#define USE_STANDARD_LIMITS 0

    /// Used to tell the decoder whether to enable or disable the video jitter buffer.
    /// \param[in] userData The opaque pointer specified during initialization.
    /// Provided by the client during the initialization of the NVSC API.
    /// NVSC will then provide this value at all invocations of this callback.
    /// \param[in] bEnable Enable jitter buffer if this is true, disable otherwise.
    typedef void (*CONTROL_VIDEO_JITTER_BUFFER_PROC)(void* userData, bool bEnable);

    /// Struct holding video Quality of Service requirements from client.
    typedef struct NvstClientVideoQosSetting_t
    {
        /// Dynamic resolution mode.
        /// Server will generate different video resolutions based on network streaming condition.
        bool videoDynamicResolutionMode;

        /// Display error recovery mode.
        /// Due to network condition, video frame data can be lost,
        /// which causes video corruption until recovered.
        /// Decoder can choose different modes in this case.
        /// false - pause on loss of frame data.
        /// true - continue display on loss of frame data.
        bool videoDisplayContinueOnFrameLoss;

        /// H.264 encoder mode for multithreaded slice decode support.
        /// If the client wishes to decode multiple slices in parallel,
        /// then constrained encoding must be enabled.
        /// Deblocking across slice boundaries must be disabled:
        /// sliceMode = 3 and sliceModeData = slicesPerFrame.
        /// \todo Explain why is encoder mode present in client header.
        bool videoSliceDecodeMultithreaded;

        /// Multi-reference video frames are P frames that use multiple previous frames as references.
        /// Some client features may not be able to accept multi-reference frames.
        /// This flag allows clients to disable the encoder muti-reference feature.
        bool disableMultiReference;

        /// Number of slices into which frames are divided.
        /// \todo This is replicated information from the VDU struct.
        uint32_t slicesPerFrame;

        /// Allow server sending intra refresh frames when required.
        /// Allow intra refresh frame related features ony if decoder supports decoding intra refresh frames.
        /// true - Allow server to send intra refresh frames when required
        /// false - Do not allow server to send intra refresh frames in any case
        bool allowIntraRefreshFrames;
    } NvstClientVideoQosSetting;

    /// Struct holding information about a H.264 decoder.
    /// \remarks
    /// An instance of this struct, with the appropriate values,
    /// must be specified during initialization of the stream client.
    typedef struct NvstVideoDecoder_t
    {
        /// YCbCr color space conversion mode for video encoding.
        NvstCscMode cscMode;

        /// Expected VU type.
        NvstVideoDecodeUnitType expectedVduType;

        /// Bitfield indicating the recovery types supported by the decoder.
        /// At least one must be supported.
        /// \todo Explain who populates this bitfield.
        uint32_t streamRecoveryType;

        /// Maximum H264 profile handled by the decoder.
        NvstH264Profile maxH264Profile;

        /// Maximum H264 level handled by the decoder.
        /// \remarks
        /// Only values from {41, 42, 50, 51} are supported.
        /// This is currently only used to compute the maximum number of reference frames.
        uint32_t maxH264Level;

        /// Maximum Reference Frames handled by the decoder.
        /// Specify maximum number of reference frames decoder needs to maintain on client.
        /// Clients can choose values from 1 to 16.
        /// Standards specify the max at 16, hence server will cap the value even
        /// if client passes any value greater than 16. If client set this value to 0,
        /// it means maximum number of reference frames will be determined based on standard limits.
        uint32_t maxNumReferenceFrames;

        /// Video QoS settings.
        NvstClientVideoQosSetting videoQosSetting;

        /// Dynamic range mode.
        NvstHdrMode dynamicRangeMode;

        /// Permit gradual resolution changes for this video stream
        /// If true, and supported by the server, the SDK will change the resolution much more frequently than usual.
        /// The resolution may even change multiple frames in a row.
        bool permitGrc;

    } NvstVideoDecoder;

    /// Struct containing the video format preferences.
    /// \remarks
    /// A streaming client is expected to populate a format and the corresponding
    /// video decoder settings. There can be multiple NvstVideoFormatPreferences
    /// in which case SDK would query server capabilities to check which format is
    /// supported and the corresponding videoDecoder settings are used.
    typedef struct NvstVideoFormatPreference_t
    {
        /// Video codec format.
        NvstVideoFormat format;

        /// Video Decoder settings corresponding to the format.
        NvstVideoDecoder videoDecoder;
    } NvstVideoFormatPreference;

    /// @}

#if defined(__cplusplus)
}
#endif
