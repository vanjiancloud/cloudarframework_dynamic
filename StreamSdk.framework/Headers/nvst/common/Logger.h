// SPDX-FileCopyrightText: Copyright (c) 2017-2022, NVIDIA CORPORATION & AFFILIATES. All rights reserved.
// SPDX-License-Identifier: LicenseRef-NvidiaProprietary
//
// NVIDIA CORPORATION, its affiliates and licensors retain all intellectual
// property and proprietary rights in and to this material, related
// documentation and any modifications thereto. Any use, reproduction,
// disclosure or distribution of this material and related documentation
// without an express license agreement from NVIDIA CORPORATION or
// its affiliates is strictly prohibited.

/// \file Logger.h
/// NvstLogger interface.

#pragma once

#include "../common/Result.h"
#include "../common/Util.h"

#include <stdint.h>
#include <stdarg.h>

#if defined(__cplusplus)
extern "C"
{
#endif

    /// \defgroup NvstLogger NvstLogger interface

    /// Log levels.
    ///
    /// Every log message comes with an associated log level.
    /// The logger's log level implies whether a log message is logged or ignored.
    typedef enum NvstLogLevel_t
    {
        /// Descriptive logs with extra granular information.
        NVST_LL_VERBOSE = 0,
        /// Debug events/logs which can help in debugging.
        NVST_LL_DEBUG = 1,
        /// Generally useful information to log.
        NVST_LL_INFO = 2,
        /// Indication of unexpected behavior or undesirable results. No recovery is necessary or attempted.
        NVST_LL_WARNING = 3,
        /// Internal use only.  Log messages that are used in machine-parsing.  This log level will ONLY work with
        /// certain special strings defined in MachineParsedLogStrings.h.  This value cannot be selected by
        /// nvst{initialize,update}Logger().
        /// Getting machine parsed string requires log level NVST_LL_WARNING or lower
        NVST_LL_MACHINE_PARSED = 4,
        /// Issues which are fatal to particular operation/feature, but not to the whole session.
        NVST_LL_ERROR = 5,
        /// Any error forcing session/application to shutdown.
        NVST_LL_CRITICAL = 6,
        /// Just to use with the nvst{initialize,update}Logger() functions to set the log level to silence.
        /// Not to use with nvstWriteLog.
        NVST_LL_SILENCE = 7,
    } NvstLogLevel;

    // Setting for enabling privacy.
    typedef enum NvstPiiMode_t
    {
        // PII in logs will be shown plainly.
        NVST_PM_PLAIN = 0,
        // PII in logs will be obfuscated.
        NVST_PM_OBFUSCATED = 1
    } NvstPiiMode;

/// Default log levels for different build types.
#ifdef DEBUG
    #define NVST_LL_DEFAULT NVST_LL_DEBUG
#else
    #define NVST_LL_DEFAULT NVST_LL_INFO
#endif

    /// Logger output targets
    /// Specifies where log messages will be written.  Any combination of targets may be used.
    /// Bitfield layout - multiple outputs must be bitwise OR'ed
    typedef enum NvstLogTarget_t
    {
        /// No logging.
        NVST_LT_NONE = 0x0,
        /// Log to stderr.
        NVST_LT_STDERR = 0x1,
        /// Log using system provided logging API.
        NVST_LT_SYSTEM = 0x2,
        /// Log to specified file.
        NVST_LT_FILE = 0x4,
        /// Log through invocation of a user-specified callback.
        NVST_LT_CALLBACK = 0x8,
    } NvstLogTarget;

    /// Log prefixes specify additional logging fields that are pre-pended to each log message.
    /// Prefixes are in a bitfield format and must be bitwise OR'ed.  Use NVST_LP_ALL for all prefixes.
    typedef enum NvstLogPrefix_t
    {
        /// No log prefixes.
        NVST_LP_NONE = 0x0,
        /// Add thread ID.  Denoted as {xxx}.
        NVST_LP_THREAD_ID = 0x1,
        /// Add timestamp. GMT denoted as [xxx], local time denoted as =xxx=.
        NVST_LP_TIMESTAMP = 0x2,
        /// Add counter value that increments from 0-9 with each log line.  Denoted as #x.
        NVST_LP_COUNTER = 0x4,
        /// Add logging level.  One of D,I,W,M,E,C and denoted as (x).
        NVST_LP_LEVEL = 0x8,
        /// Add log tag. The name of the module that generated the log message.  Denoted as <xxx>.
        NVST_LP_LOG_TAG = 0x10,
        /// Add time since last log on the same thread, in milliseconds.  Denoted as *xxx*.
        NVST_LP_THREAD_DELTA = 0x20,
        /// Add hash of log string.  Denoted as &xxx&.
        NVST_LP_UNIQUE_ID = 0x40,
        /// Add all logging prefixes.
        NVST_LP_ALL = ~0x0,
    } NvstLogPrefix;

    /// The type of the callback function used to deliver a log message.
    /// \param[in] callbackData The opaque pointer, specified during initialization,
    /// which is to be passed as a parameter to the log callback.
    /// \param[in] level The log level.
    /// \param[in] tag The log tag.
    /// \param[in] message The log message.
    typedef void (*LOGGER_CALLBACK_PROC)(void* callbackData, NvstLogLevel level, const char* tag, const char* message);

    /// \ingroup NvstLogger
    /// Initialize the logger.
    /// \param[in] level The level of logging desired in this streaming session.
    /// \param[in] targets Bitfield of log targets. \sa NvstLogTarget
    /// \param[in] prefixes Log prefixes to use. \sa NvstLogPrefix
    /// \param[in] fileName Log file.
    /// Used only when logTargets includes NVST_LT_FILE flag.
    /// \param[in] callback Log callback function.
    /// Used only when logTargets includes NVST_LT_CALLBACK flag.
    /// \param[in] callbackData Data passed with log callback.
    /// Used only when logTargets includes NVST_LT_CALLBACK flag.
    /// \param[in] piiMode Whether to obfuscate PII data in logs.
    /// \param[in] maxFileSize The max size, in bytes, of log file before it is closed and further logs are discarded.
    /// \warning On Windows, maxFileSize may be overridden by a Registry Key. This is needed to maintain backwards
    /// compatibility. If the value passed in here is ignored, attempt to remove the regkey
    /// [HKEY_LOCAL_MACHINE\\SOFTWARE\\NVIDIA Corporation\\NvStream] "LogSizeLimitInMiB"
    /// \todo Add nvscGetPrivacyAwareString in this header file.
    /// \return
    /// NVST_R_INVALID_OPERATION if the logger has already been initialized.
    /// NVST_R_GENERIC_ERROR if the logger could not be initialized.
    /// NVST_R_INVALID_PARAM if logCallback function pointer is NULL.
    /// NVST_R_SUCCESS otherwise.
    NVST_API NvstResult nvstInitializeLogger(
        NvstLogLevel level,
        int32_t targets,
        int32_t prefixes,
        const char* fileName,
        LOGGER_CALLBACK_PROC callback,
        void* callbackData,
        NvstPiiMode piiMode,
        uint64_t maxFileSize);

    /// \ingroup NvstLogger
    /// Convenience typedef for library consumers.
    typedef NvstResult (*INITIALIZE_LOGGER_PROC)(
        NvstLogLevel level,
        uint32_t targets,
        uint32_t prefixes,
        const char* fileName,
        LOGGER_CALLBACK_PROC callback,
        void* callbackData,
        NvstPiiMode piiMode,
        uint64_t maxFileSize);

    /// \ingroup NvstLogger
    /// \param[in] level The level of logging for all logging targets, the default log level.
    /// \sa nvstUpdateLoggerLevel
    /// \sa nvstUpdateLoggerLevelPerTargetMask
    /// \param[in] targets Bitfield of log targets. \sa NvstLogTarget
    /// \param[in] prefixes Log prefixes to use. \sa NvstLogPrefix
    /// \param[in] fileName Log file.
    /// Used only when logTargets includes NVST_LT_FILE flag.
    /// \param[in] callback Log callback function.
    /// Used only when logTargets includes NVST_LT_CALLBACK flag.
    /// \param[in] callbackData Data passed with log callback.
    /// Used only when logTargets includes NVST_LT_CALLBACK flag.
    /// \param[in] piiMode Whether to obfuscate PII data in logs.
    /// \param[in] maxFileSize The max size, in bytes, of log file before it is closed and further logs are discarded.
    /// \warning On Windows, maxFileSize may be overridden by a Registry Key. This is needed to maintain backwards
    /// compatibility. If the value passed in here is ignored, attempt to remove the regkey
    /// [HKEY_LOCAL_MACHINE\\SOFTWARE\\NVIDIA Corporation\\NvStream] "LogSizeLimitInMiB"
    /// \return
    /// NVST_R_GENERIC_ERROR if the logger could not be updated.
    /// NVST_R_INVALID_PARAM if logCallback function pointer is NULL.
    /// NVST_R_SUCCESS otherwise.
    NVST_API NvstResult nvstUpdateLogger(
        NvstLogLevel level,
        int32_t targets,
        int32_t prefixes,
        const char* fileName,
        LOGGER_CALLBACK_PROC callback,
        void* callbackData,
        NvstPiiMode piiMode,
        uint64_t maxFileSize);

    /// \ingroup NvstLogger
    /// Convenience typedef for library consumers.
    typedef NvstResult (*UPDATE_LOGGER_PROC)(
        NvstLogLevel level,
        uint32_t targets,
        uint32_t prefixes,
        const char* fileName,
        LOGGER_CALLBACK_PROC callback,
        void* callbackData,
        NvstPiiMode piiMode,
        uint64_t maxFileSize);

    /// \ingroup NvstLogger
    /// Uninitialize the logger.
    NVST_API void nvstUninitializeLogger();

    /// \ingroup NvstLogger
    /// Convenience typedef for library consumers.
    typedef NvstResult (*UNINITIALIZE_LOGGER_PROC)();

    /// \ingroup NvstLogger
    /// Update the logger's current log level for all targets
    /// \param[in] logLevel The level of logging desired from this point onward.
    /// \return
    /// NVST_R_GENERIC_ERROR if the logger log level could not be updated.
    /// NVST_R_SUCCESS otherwise.
    /// \todo Decide whether this function is needed at all with nvstUpdateLogger present.
    NVST_API NvstResult nvstUpdateLoggerLevel(NvstLogLevel logLevel);

    /// \ingroup NvstLogger
    /// Convenience typedef for library consumers.
    typedef NvstResult (*UPDATE_LOGGER_LEVEL_PROC)(NvstLogLevel logLevel);

    /// \ingroup NvstLogger
    /// Update log level for log targets specified in the given bitmask
    /// \param[in] logTargetMask Log targets to change log level for, after function call
    /// all targets in mask will have their levels changed to logLevel
    /// \param[in] logLevel The level of logging desired from this point onward.
    /// \return
    /// NVST_R_INVALID_OPERATION if log target does not exist yet.
    /// NVST_R_SUCCESS otherwise.
    NVST_API NvstResult nvstUpdateLoggerLevelPerTargetMask(int32_t logTargetMask, NvstLogLevel logLevel);

    /// \ingroup NvstLogger
    /// Update the logger's current privacy mode from this time onward.
    /// \param[in] piiMode The new PII mode.
    NVST_API void nvstUpdateLoggerPrivacyMode(NvstPiiMode piiMode);

    /// \ingroup NvstLogger
    /// Convenience typedef for library consumers.
    typedef void (*UPDATE_LOGGER_PRIVACY_MODE)(NvstPiiMode piiMode);

    /// \ingroup NvstLogger
    /// Get state of privacy logging field.
    /// \return value of privacy state field;
    NVST_API NvstPiiMode nvstGetLoggerPrivacyMode();

    /// \ingroup NvstLogger
    /// Convenience typedef for library consumers.
    typedef NvstResult (*GET_LOGGER_PRIVACY_MODE)();

    /// \ingroup NvstLogger
    /// Update the logger's current prefixes.
    /// \param[in] prefixes The prefixes desired from this point onward.
    /// \return
    /// NVST_R_GENERIC_ERROR if the logger prefixes could not be updated.
    /// NVST_R_SUCCESS otherwise.
    NVST_API NvstResult nvstUpdateLoggerPrefixes(NvstLogPrefix prefixes);

    /// \ingroup NvstLogger
    /// Convenience typedef for library consumers.
    typedef NvstResult (*UPDATE_LOGGER_PREFIXES_PROC)(NvstLogPrefix prefixes);

    /// \ingroup NvstLogger
    /// Write a log message to the configured log targets.
    /// \param[in] level The log level of this message.
    /// \param[in] tag The tag to prefix to this message.
    /// \param[in] format The format string to apply on the optional arguments.
    NVST_API void nvstWriteLog(NvstLogLevel level, const char* tag, const char* format, ...);

    /// \ingroup NvstLogger
    /// Convenience typedef for library consumers.
    typedef void (*WRITE_LOG_PROC)(NvstLogLevel level, const char* tag, const char* format, ...);

    /// \ingroup NvstLogger
    /// Write a log message to the configured log targets.
    /// \param[in] level The log level of this message.
    /// \param[in] tag The tag to prefix to this message.
    /// \param[in] format The format string to apply on the optional arguments.
    /// \param[in] uniqueId The unique ID to prefix this message.
    /// \param[in] format The format string to apply on the optional arguments.
    NVST_API void nvstWriteLogUniqueId(NvstLogLevel level, uint32_t uniqueId, const char* tag, const char* format, ...);

    /// \ingroup NvstLogger
    /// Convenience typedef for library consumers.
    typedef void (
        *WRITE_LOG_UNIQUE_ID_PROC)(NvstLogLevel level, uint32_t uniqueId, const char* tag, const char* format, ...);

    /// \ingroup NvstLogger
    /// Write a log message to the configured log targets, using va_list.
    ///
    /// Essentially the same as nvstWriteLog, only with args explicitly passed.
    /// It is necessary to have when redirected from a function.
    /// __VA_ARGS__ can only be used in replacement lists of variadic macros.
    /// \param[in] level The log level of this message.
    /// \param[in] tag The tag to prefix to this message.
    /// \param[in] uniqueId The unique ID to prefix this message.
    /// \param[in] format The format string to apply on the optional arguments.
    /// \param[in] variableArgs Standard C list
    NVST_API void nvstWriteLogVaList(
        NvstLogLevel level,
        uint32_t uniqueId,
        const char* tag,
        const char* format,
        va_list variableArgs);

    /// \ingroup NvstLogger
    /// Convenience typedef for library consumers.
    typedef void (*WRITE_LOG_VA_LIST_PROC)(
        NvstLogLevel level,
        uint32_t uniqueId,
        const char* tag,
        const char* format,
        va_list variableArgs);

#if defined(__cplusplus)
}
#endif
