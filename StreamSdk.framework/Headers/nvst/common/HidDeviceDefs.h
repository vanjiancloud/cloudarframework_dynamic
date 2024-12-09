// Copyright NVIDIA Corporation 2018 - 2022
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

/// \file HidDeviceDefs.h
/// Defines the logical device IDs sent from the client to the server

#pragma once

/// Device IDs, range is uint8_t
typedef enum NvstHidDeviceId_t
{
    /// Special ID for unknown / invalid device ID.
    NVST_HID_DEV_INVALID = 0,
    /// Wacom Intuos Pro M pen/tablet device
    NVST_HID_DEV_INTUOS_PRO_M = 1,
    ///\{
    /// Sony DualSense 5 Controllers
    NVST_HID_DEV_DUALSENSE_A = 2,
    NVST_HID_DEV_DUALSENSE_B = 3,
    NVST_HID_DEV_DUALSENSE_C = 4,
    NVST_HID_DEV_DUALSENSE_D = 5,
    ///\}
    ///\{
    /// Sony DualShock 4 Controllers
    NVST_HID_DEV_DUALSHOCK4_A = 6,
    NVST_HID_DEV_DUALSHOCK4_B = 7,
    NVST_HID_DEV_DUALSHOCK4_C = 8,
    NVST_HID_DEV_DUALSHOCK4_D = 9,
    ///\}
    /// For range control
    NVST_HID_DEV_SIZE
} NvstHidDeviceId;

typedef enum NvstHidDeviceCapability_t
{
    // No devices are supported
    NVST_HID_CAPABILITY_NONE = 0x00000000,
    // Wacom Intuos Pro M pen/tablet device
    NVST_HID_CAPABILITY_INTUOS_PRO_M = 0x00000001,
    // Sony DualSemse Controllers
    NVST_HID_CAPABILITY_DUALSENSE = 0x00000002,
    // Sony DualShock 4 Controllers
    NVST_HID_CAPABILITY_DUALSHOCK4 = 0x00000004
} NvstHidDeviceCapability;

/// Sony Vendor ID
#define HID_VID_SONY 0x054c

/// DualSense Product ID
#define HID_PID_DUALSENSE 0x0ce6
/// DualShock 4 v2 Product ID
#define HID_PID_DUALSHOCK4 0x09cc
/// DualShock 4 v1 Product ID
#define HID_PID_DUALSHOCK4_V1 0x05c4
/// DualShock 4 wireless adapter Product ID
#define HID_PID_DUALSHOCK4_ADAPTER 0x0ba0
