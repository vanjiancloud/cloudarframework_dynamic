// Copyright (c) 2022, NVIDIA CORPORATION.  All rights reserved.
//
// NVIDIA CORPORATION and its licensors retain all intellectual property
// and proprietary rights in and to this software, related documentation
// and any modifications thereto.  Any use, reproduction, disclosure or
// distribution of this software and related documentation without an express
// license agreement from NVIDIA CORPORATION is strictly prohibited.

/*!
 * THIS IS AUTOMATICALLY GENERATED FILE. DO NOT EDIT.
 * For any modifications, refer GsBlobDefs.json
 */

#pragma once

#include <cstdint>

#pragma pack(push, 1)

struct ReportModuleBlobEventServerFrameData
{
    uint8_t rm_blob_id = 1;
    uint8_t rm_blob_version = 3;
    uint16_t rm_stream_index = 0;
    uint32_t rm_frame_number = 0;
    uint8_t rm_igpu = 0;
    double rm_capture_input_ts_ms = 0;
    uint32_t rm_captured_frame_number = 0;
    uint16_t rm_va_sleep_target = 0;
    uint16_t rm_va_busy_wait = 0;
    uint16_t rm_encoder_input_drops = 0;
    double rm_encode_input_ts_ms = 0;
    float rm_encode_duration_ms = 0;
    double rm_tx_ts_ms = 0;
    uint32_t rm_frame_size = 0;
    uint8_t rm_frame_type = 0;
    float rm_vbv_size_kb = 0;
    float rm_encryption_ms = 0;
    float rm_frame_avg_qp = 0;
    float rm_drc_avg_qp = 0;
    float rm_adaptive_qp_threshold = 0;
    uint16_t rm_qos_resolution_change_reasons = 0;
    uint16_t rm_width = 0;
    uint16_t rm_height = 0;
    uint16_t rm_fps = 0;
    uint32_t rm_bitrate_bps = 0;
    uint32_t rm_qos_max_bitrate_bps = 0;
    uint32_t rm_qos_throttling_bitrate_cap_bps = 0;
    uint32_t rm_qos_bitrate_change_reasons = 0;
    uint16_t rm_qos_tactic = 0;
    uint16_t rm_num_packets = 0;
    uint16_t rm_encoded_Packets = 0;
    uint16_t rm_packet_size = 0;
    uint16_t rm_tx_rx_lag_ms = 0;
    float rm_total_ts_tx_gap_ms = 0;
    uint32_t rm_intra_mb_count = 0;
    uint32_t rm_inter_mb_count = 0;
    uint16_t rm_streamer_frame_drop_reason = 0;
    uint32_t rm_avg_mvx = 0;
    uint32_t rm_avg_mvy = 0;
    double rm_capture_frame_start = 0;
    float rm_capture_frame_duration = 0;
    double rm_wait_for_frame_grab_start = 0;
    float rm_wait_for_frame_grab_duration = 0;
    float rm_scaling_duration = 0;
    float rm_csc_duration = 0;
    float rm_enc_map_input_picture_end = 0;
    float rm_enc_picture_end = 0;
    float rm_enc_dequeue_since_wait_for_grab = 0;
    float rm_enc_dequeue_duration = 0;
    float rm_enc_wait_on_async_mode_event_end = 0;
    float rm_enc_lock_bitstream_end = 0;
    float rm_fec_encode_start_since_wait_for_grab = 0;
    float rm_fec_encode_group0_duration = 0;
    float rm_fec_encode_group1_duration = 0;
    float rm_fec_encode_group2_duration = 0;
    float rm_fec_encode_group3_duration = 0;
    float rm_send_packets_start_since_wait_for_grab = 0;
    float rm_send_packets_duration = 0;
    float rm_wait_for_frame_to_send_start_since_wait_for_grab = 0;
    float rm_wait_for_frame_to_send_duration = 0;
    float rm_add_frame_to_sending_queue_since_wait_for_grab = 0;
};


struct ReportModuleBlobEventLowFreqStats
{
    uint8_t rm_blob_id = 2;
    uint8_t rm_blob_version = 2;
    uint16_t rm_stream_index = 0;
    uint32_t rm_frame_number = 0;
    float rm_encoder_bitrate_estimate_kbps = 0;
    uint8_t rm_min_qp = 0;
    int8_t rm_last_min_qp_change_reason = 0;
};


struct ReportModuleBlobEventIntraRefreshData
{
    uint8_t rm_blob_id = 3;
    uint8_t rm_blob_version = 1;
    uint16_t rm_stream_index = 0;
    uint32_t rm_frame_number = 0;
    uint32_t rm_intra_refresh_length = 0;
    uint32_t rm_intra_refresh_period = 0;
    uint32_t rm_intra_refresh_change_reasons = 0;
};


struct ReportModuleBlobEventNativeFramePacing
{
    uint8_t rm_blob_id = 4;
    uint8_t rm_blob_version = 1;
    uint16_t rm_stream_index = 0;
    uint32_t rm_frame_number = 0;
    uint32_t rm_native_frame_pacing_frame_count = 0;
    float rm_native_frame_pacing_avg_queue_time_ms = 0;
    float rm_native_frame_pacing_target_queue_time_ms = 0;
    float rm_native_frame_pacing_target_frame_time_ms = 0;
    float rm_native_frame_pacing_current_frame_time_ms = 0;
    uint8_t rm_native_frame_pacing_active = 0;
};


struct ReportModuleBlobEventRlStats
{
    uint8_t rm_blob_id = 5;
    uint8_t rm_blob_version = 1;
    uint16_t rm_stream_index = 0;
    uint32_t rm_frame_number = 0;
    uint32_t rm_rl_weighted_bwe_kbps = 0;
    uint16_t rm_rl_weighted_bwu_percent = 0;
    uint16_t rm_rl_packet_loss_percent = 0;
    uint32_t rm_rl_bitrate_kbps = 0;
    uint8_t rm_rl_fec_percent = 0;
    uint8_t rm_rl_qos_status = 0;
    uint8_t rl_frame_reasons = 0;
};


struct ReportModuleBlobEventNativeClientFrameTranscodeData
{
    uint8_t rm_blob_id = 6;
    uint8_t rm_blob_version = 1;
    uint16_t rm_stream_index = 0;
    uint32_t rm_frame_number = 0;
    uint8_t rm_native_client_frame_transcode_state_flags = 0;
    uint16_t rm_native_client_frame_transcode_encode_time_100us = 0;
};


struct ReportModuleBlobEventNativeClientGenericStats
{
    uint8_t rm_blob_id = 7;
    uint8_t rm_blob_version = 1;
    uint16_t rm_stream_index = 0;
    uint32_t rm_frame_number = 0;
    int16_t rm_native_client_generic_stats_data0 = 0;
    int16_t rm_native_client_generic_stats_data1 = 0;
    int16_t rm_native_client_generic_stats_data2 = 0;
    int16_t rm_native_client_generic_stats_data3 = 0;
    int16_t rm_native_client_generic_stats_data4 = 0;
    int16_t rm_native_client_generic_stats_data5 = 0;
    int16_t rm_native_client_generic_stats_data6 = 0;
    int16_t rm_native_client_generic_stats_data7 = 0;
};


struct ReportModuleBlobEventNativeClientFrameDecodeDataMissing
{
    uint8_t rm_blob_id = 8;
    uint8_t rm_blob_version = 1;
    uint16_t rm_stream_index = 0;
    uint32_t rm_frame_number = 0;
    uint8_t rm_native_client_decode_data_missing = 0;
};


struct ReportModuleBlobEventNativeClientQosFeedback
{
    uint8_t rm_blob_id = 9;
    uint8_t rm_blob_version = 1;
    uint16_t rm_stream_index = 0;
    uint32_t rm_frame_number = 0;
    uint32_t rm_native_client_qos_feedback_seq_number = 0;
    double rm_native_client_qos_feedback_arrival_timestamp_ms = 0;
    float rm_native_client_qos_feedback_owd_ms = 0;
    float rm_native_client_qos_feedback_jitter_us = 0;
    uint8_t rm_native_client_qos_feedback_packet_loss_rate = 0;
    uint8_t rm_native_client_qos_feedback_fec_percent = 0;
    uint16_t rm_native_client_qos_feedback_max_decode_fps = 0;
    uint16_t rm_native_client_qos_feedback_max_render_fps = 0;
    uint8_t rm_native_client_qos_feedback_quality_score = 0;
    uint8_t rm_native_client_qos_feedback_latency_score = 0;
    uint8_t rm_native_client_qos_feedback_loss_score = 0;
    uint8_t rm_native_client_qos_feedback_bandwidth_score = 0;
    uint8_t rm_native_client_qos_feedback_bw_util = 0;
    uint32_t rm_native_client_qos_feedback_bw_estimation = 0;
    uint16_t rm_native_client_qos_feedback_tx_rx_lag = 0;
    uint16_t rm_native_client_qos_feedback_rtd = 0;
    float rm_native_client_qos_feedback_feedback_jitter_us = 0;
    uint32_t rm_native_client_qos_feedback_avg_bwe = 0;
    uint32_t rm_native_client_qos_feedback_frame_bwe_kbps = 0;
    uint32_t rm_native_client_qos_feedback_avg_frame_bwe_kbps = 0;
};


struct ReportModuleBlobEventNativeClientFrameDecodeData
{
    uint8_t rm_blob_id = 10;
    uint8_t rm_blob_version = 4;
    uint16_t rm_stream_index = 0;
    uint32_t rm_frame_number = 0;
    uint16_t rm_num_packets_lost = 0;
    double rm_first_packet_rx_time_ms = 0;
    float rm_rx_to_decoder_present_delta_ms = 0;
    float rm_rx_to_decode_start_delta_ms = 0;
    float rm_rx_to_predecode_done_delta_ms = 0;
    float rm_rx_to_render_present_delta_ms = 0;
    float rm_rx_to_render_start_delta_ms = 0;
    float rm_rx_to_render_completed_delta_ms = 0;
    float rm_rx_to_present_completed_delta_ms = 0;
    float rm_rtp_lib_queue_time_ms = 0;
    float rm_fec_decode_time_ms = 0;
    float rm_frame_rx_duration_ms = 0;
    uint32_t rm_decode_frame_size = 0;
    int32_t rm_rssi = 0;
    uint32_t rm_nw_speed_kbps = 0;
    uint32_t frame_status_flags = 0;
    float rm_frame_owd_ms = 0;
    float rm_total_ts_rx_gap_time_ms = 0;
    float rm_rx_to_present_completed_confirmed_delta_ms = 0;
    float rm_frame_render_gpu_duration_ms = 0;
    uint16_t rm_num_packets_recovered_by_nack = 0;
    float rm_rtp_inactivity_time_ms = 0;
};


struct ReportModuleBlobEventNativeRtcClientAppFeedbackData
{
    uint8_t rm_blob_id = 11;
    uint8_t rm_blob_version = 1;
    uint16_t rm_stream_index = 0;
    uint32_t rm_frame_number = 0;
    uint16_t rm_native_rtc_client_app_fb_interval_ms = 0;
    uint16_t rm_native_rtc_client_app_fb_avg_decode_time_ms = 0;
    uint16_t rm_native_rtc_client_app_fb_frames_decoded = 0;
    uint16_t rm_native_rtc_client_app_fb_frames_dropped = 0;
    uint16_t rm_native_rtc_client_app_fb_num_packets_lost = 0;
};


struct ReportModuleBlobEventNativeRtcClientStats
{
    uint8_t rm_blob_id = 12;
    uint8_t rm_blob_version = 2;
    uint16_t rm_stream_index = 0;
    uint32_t rm_frame_number = 0;
    uint16_t rm_native_rtc_client_pli_count = 0;
    uint16_t rm_native_rtc_client_nack_packet_capture_age_max_ms = 0;
    uint16_t rm_native_rtc_client_nack_request_max_packets_count = 0;
    uint16_t rm_native_rtc_client_nack_requests_count = 0;
    uint16_t rm_native_rtc_client_nacked_packets_count = 0;
    uint16_t rm_native_rtc_client_nack_not_served_packets_count = 0;
    uint16_t rm_native_rtc_client_key_frame_send_request_ignore_count = 0;
    uint16_t rm_native_rtc_client_delta_frames_dropped_on_preemptive_key_frame_send = 0;
    uint16_t rm_native_rtc_client_key_frame_send_reason = 0;
};


struct ReportModuleBlobEventNativeRtcBweAlgoStats
{
    uint8_t rm_blob_id = 13;
    uint8_t rm_blob_version = 2;
    uint16_t rm_stream_index = 0;
    uint32_t rm_frame_number = 0;
    double rm_native_rtc_frame_rx_time_ms = 0;
    double rm_native_rtc_first_packet_rx_time_ms = 0;
};


struct ReportModuleBlobEventResolutionStats
{
    uint8_t rm_blob_id = 14;
    uint8_t rm_blob_version = 1;
    uint16_t rm_stream_index = 0;
    uint32_t rm_frame_number = 0;
    uint16_t rm_res_width = 0;
    uint16_t rm_res_height = 0;
    uint16_t rm_res_encoder_frame_width = 0;
    uint16_t rm_res_encoder_frame_height = 0;
    uint16_t rm_res_qos_target_width = 0;
    uint16_t rm_res_qos_target_height = 0;
    uint16_t rm_res_qos_width = 0;
    uint16_t rm_res_qos_height = 0;
    uint16_t rm_res_game_width = 0;
    uint16_t rm_res_game_height = 0;
    uint16_t rm_res_prev_width = 0;
    uint16_t rm_res_prev_height = 0;
    uint16_t rm_res_prev_encoder_frame_width = 0;
    uint16_t rm_res_prev_encoder_frame_height = 0;
    uint16_t rm_res_prev_qos_target_width = 0;
    uint16_t rm_res_prev_qos_target_height = 0;
    uint16_t rm_res_prev_qos_width = 0;
    uint16_t rm_res_prev_qos_height = 0;
    uint16_t rm_res_prev_game_width = 0;
    uint16_t rm_res_prev_game_height = 0;
};


struct ReportModuleBlobEventNativeRtcPacketReceivedStats
{
    uint8_t rm_blob_id = 15;
    uint8_t rm_blob_version = 1;
    uint16_t rm_stream_index = 0;
    uint32_t rm_frame_number = 0;
    uint32_t rm_native_rtc_packets_received_per_frame = 0;
};


struct ReportModuleBlobEventRtcCpmStats
{
    uint8_t rm_blob_id = 16;
    uint8_t rm_blob_version = 2;
    uint16_t rm_stream_index = 0;
    uint32_t rm_frame_number = 0;
    uint16_t rm_native_rtc_client_cpm_tracked_avg_dec_time_ms = 0;
    uint16_t rm_native_rtc_client_cpm_tracked_good_nw_avg_dec_time_ms = 0;
    uint16_t rm_native_rtc_client_cpm_tracked_avg_nack_size = 0;
    uint16_t rm_rtc_cpm_events = 0;
};


struct ReportModuleBlobEventNativeRtcClientRtcpStats
{
    uint8_t rm_blob_id = 17;
    uint8_t rm_blob_version = 1;
    uint16_t rm_stream_index = 0;
    uint32_t rm_frame_number = 0;
    uint32_t rm_native_rtc_client_feedback_seq_number = 0;
    double rm_native_rtc_client_feedback_rx_time_us = 0;
    double rm_native_rtc_client_owd_ms = 0;
    float rm_native_rtc_client_jitter_us = 0;
    uint8_t rm_native_rtc_client_avg_packet_loss_percent = 0;
    uint8_t rm_native_rtc_client_fec_percent = 0;
    uint32_t rm_native_rtc_client_avg_bwu = 0;
    uint16_t rm_native_rtc_client_qos_feedback_tx_rx_lag = 0;
    uint64_t rm_native_rtc_client_rtt_ms = 0;
    uint32_t rm_native_rtc_client_avg_frame_bwe_kbps = 0;
};


struct ReportModuleBlobEventL4SRxStats
{
    uint8_t rm_blob_id = 18;
    uint8_t rm_blob_version = 1;
    uint16_t rm_stream_index = 0;
    uint32_t rm_frame_number = 0;
    uint8_t rm_perc_ce_marked_packets = 0;
};


struct ReportModuleBlobEventL4STxStats
{
    uint8_t rm_blob_id = 19;
    uint8_t rm_blob_version = 1;
    uint16_t rm_stream_index = 0;
    uint32_t rm_frame_number = 0;
    double rm_cc_alpha = 0;
    uint16_t rm_pp_group_target = 0;
    uint16_t rm_pp_burst_target = 0;
};


struct ReportModuleBlobEventSurvivalAnalysisScore
{
    uint8_t rm_blob_id = 20;
    uint8_t rm_blob_version = 1;
    uint16_t rm_stream_index = 0;
    uint32_t rm_frame_number = 0;
    int16_t rm_survival_analysis_score_gpu_perf_i16 = 0;
    int16_t rm_survival_analysis_score_server_perf_i16 = 0;
    int16_t rm_survival_analysis_score_visual_i16 = 0;
    int16_t rm_survival_analysis_score_decoder_i16 = 0;
    int16_t rm_survival_analysis_score_downlink_lag_i16 = 0;
    int16_t rm_survival_analysis_score_downlink_congestion_i16 = 0;
    int16_t rm_survival_analysis_score_uplink_i16 = 0;
};


struct ReportModuleBlobEventPacketPacingStats
{
    uint8_t rm_blob_id = 21;
    uint8_t rm_blob_version = 1;
    uint16_t rm_stream_index = 0;
    uint32_t rm_frame_number = 0;
    uint8_t rm_pp_enabled = 0;
    uint8_t rm_pp_reason = 0;
    double rm_pp_lossy_frame_percent = 0;
    uint8_t rm_pp_group_count = 0;
    uint16_t rm_pp_burst_size_packets = 0;
};


struct ReportModuleBlobEventClientFrameMapping
{
    uint8_t rm_blob_id = 22;
    uint8_t rm_blob_version = 1;
    uint16_t rm_stream_index = 0;
    uint32_t rm_frame_number = 0;
    double rm_client_timestamp_ms = 0;
};


struct ReportModuleBlobEventNativeClientGpuUtilizationStats
{
    uint8_t rm_blob_id = 23;
    uint8_t rm_blob_version = 1;
    uint16_t rm_stream_index = 0;
    uint32_t rm_frame_number = 0;
    uint16_t rm_native_client_gpu0_shared_memory_mb = 0;
    uint16_t rm_native_client_gpu0_dedicated_memory_mb = 0;
    uint8_t rm_native_client_gpu0_process_utilization = 0;
    uint8_t rm_native_client_gpu0_process_eng_3d_utilization = 0;
    uint8_t rm_native_client_gpu0_process_eng_copy_utilization = 0;
    uint8_t rm_native_client_gpu0_process_eng_video_utilization = 0;
    uint8_t rm_native_client_gpu0_total_utilization = 0;
    uint8_t rm_native_client_gpu0_total_eng_3d_utilization = 0;
    uint8_t rm_native_client_gpu0_total_eng_copy_utilization = 0;
    uint8_t rm_native_client_gpu0_total_eng_video_utilization = 0;
    uint16_t rm_native_client_gpu1_shared_memory_mb = 0;
    uint16_t rm_native_client_gpu1_dedicated_memory_mb = 0;
    uint8_t rm_native_client_gpu1_process_utilization = 0;
    uint8_t rm_native_client_gpu1_process_eng_3d_utilization = 0;
    uint8_t rm_native_client_gpu1_process_eng_copy_utilization = 0;
    uint8_t rm_native_client_gpu1_process_eng_video_utilization = 0;
    uint8_t rm_native_client_gpu1_total_utilization = 0;
    uint8_t rm_native_client_gpu1_total_eng_3d_utilization = 0;
    uint8_t rm_native_client_gpu1_total_eng_copy_utilization = 0;
    uint8_t rm_native_client_gpu1_total_eng_video_utilization = 0;
};


#define REPORT_MODULE_DEF_STR "RM_BLOB_DEF:{'20': {'1': {'rm_survival_analysis_score_gpu_perf_i16': 'int16_t', 'rm_survival_analysis_score_server_perf_i16': 'int16_t', 'rm_survival_analysis_score_visual_i16': 'int16_t', 'rm_survival_analysis_score_decoder_i16': 'int16_t', 'rm_survival_analysis_score_downlink_lag_i16': 'int16_t', 'rm_survival_analysis_score_downlink_congestion_i16': 'int16_t', 'rm_survival_analysis_score_uplink_i16': 'int16_t'}, 'Metadata': {'Name': 'SurvivalAnalysisScore'}}, '21': {'1': {'rm_pp_enabled': 'uint8_t', 'rm_pp_reason': 'uint8_t', 'rm_pp_lossy_frame_percent': 'double', 'rm_pp_group_count': 'uint8_t', 'rm_pp_burst_size_packets': 'uint16_t'}, 'Metadata': {'Name': 'PacketPacingStats'}}, '22': {'1': {'rm_client_timestamp_ms': 'double'}, 'Metadata': {'Name': 'ClientFrameMapping'}}, '23': {'1': {'rm_native_client_gpu0_shared_memory_mb': 'uint16_t', 'rm_native_client_gpu0_dedicated_memory_mb': 'uint16_t', 'rm_native_client_gpu0_process_utilization': 'uint8_t', 'rm_native_client_gpu0_process_eng_3d_utilization': 'uint8_t', 'rm_native_client_gpu0_process_eng_copy_utilization': 'uint8_t', 'rm_native_client_gpu0_process_eng_video_utilization': 'uint8_t', 'rm_native_client_gpu0_total_utilization': 'uint8_t', 'rm_native_client_gpu0_total_eng_3d_utilization': 'uint8_t', 'rm_native_client_gpu0_total_eng_copy_utilization': 'uint8_t', 'rm_native_client_gpu0_total_eng_video_utilization': 'uint8_t', 'rm_native_client_gpu1_shared_memory_mb': 'uint16_t', 'rm_native_client_gpu1_dedicated_memory_mb': 'uint16_t', 'rm_native_client_gpu1_process_utilization': 'uint8_t', 'rm_native_client_gpu1_process_eng_3d_utilization': 'uint8_t', 'rm_native_client_gpu1_process_eng_copy_utilization': 'uint8_t', 'rm_native_client_gpu1_process_eng_video_utilization': 'uint8_t', 'rm_native_client_gpu1_total_utilization': 'uint8_t', 'rm_native_client_gpu1_total_eng_3d_utilization': 'uint8_t', 'rm_native_client_gpu1_total_eng_copy_utilization': 'uint8_t', 'rm_native_client_gpu1_total_eng_video_utilization': 'uint8_t'}, 'Metadata': {'Name': 'NativeClientGpuUtilizationStats'}}, '1': {'3': {'rm_igpu': 'uint8_t', 'rm_capture_input_ts_ms': 'double', 'rm_captured_frame_number': 'uint32_t', 'rm_va_sleep_target': 'uint16_t', 'rm_va_busy_wait': 'uint16_t', 'rm_encoder_input_drops': 'uint16_t', 'rm_encode_input_ts_ms': 'double', 'rm_encode_duration_ms': 'float', 'rm_tx_ts_ms': 'double', 'rm_frame_size': 'uint32_t', 'rm_frame_type': 'uint8_t', 'rm_vbv_size_kb': 'float', 'rm_encryption_ms': 'float', 'rm_frame_avg_qp': 'float', 'rm_drc_avg_qp': 'float', 'rm_adaptive_qp_threshold': 'float', 'rm_qos_resolution_change_reasons': 'uint16_t', 'rm_width': 'uint16_t', 'rm_height': 'uint16_t', 'rm_fps': 'uint16_t', 'rm_bitrate_bps': 'uint32_t', 'rm_qos_max_bitrate_bps': 'uint32_t', 'rm_qos_throttling_bitrate_cap_bps': 'uint32_t', 'rm_qos_bitrate_change_reasons': 'uint32_t', 'rm_qos_tactic': 'uint16_t', 'rm_num_packets': 'uint16_t', 'rm_encoded_Packets': 'uint16_t', 'rm_packet_size': 'uint16_t', 'rm_tx_rx_lag_ms': 'uint16_t', 'rm_total_ts_tx_gap_ms': 'float', 'rm_intra_mb_count': 'uint32_t', 'rm_inter_mb_count': 'uint32_t', 'rm_streamer_frame_drop_reason': 'uint16_t', 'rm_avg_mvx': 'uint32_t', 'rm_avg_mvy': 'uint32_t', 'rm_capture_frame_start': 'double', 'rm_capture_frame_duration': 'float', 'rm_wait_for_frame_grab_start': 'double', 'rm_wait_for_frame_grab_duration': 'float', 'rm_scaling_duration': 'float', 'rm_csc_duration': 'float', 'rm_enc_map_input_picture_end': 'float', 'rm_enc_picture_end': 'float', 'rm_enc_dequeue_since_wait_for_grab': 'float', 'rm_enc_dequeue_duration': 'float', 'rm_enc_wait_on_async_mode_event_end': 'float', 'rm_enc_lock_bitstream_end': 'float', 'rm_fec_encode_start_since_wait_for_grab': 'float', 'rm_fec_encode_group0_duration': 'float', 'rm_fec_encode_group1_duration': 'float', 'rm_fec_encode_group2_duration': 'float', 'rm_fec_encode_group3_duration': 'float', 'rm_send_packets_start_since_wait_for_grab': 'float', 'rm_send_packets_duration': 'float', 'rm_wait_for_frame_to_send_start_since_wait_for_grab': 'float', 'rm_wait_for_frame_to_send_duration': 'float', 'rm_add_frame_to_sending_queue_since_wait_for_grab': 'float'}, 'Metadata': {'Name': 'ServerFrameData'}}, '3': {'1': {'rm_intra_refresh_length': 'uint32_t', 'rm_intra_refresh_period': 'uint32_t', 'rm_intra_refresh_change_reasons': 'uint32_t'}, 'Metadata': {'Name': 'IntraRefreshData'}}, '2': {'2': {'rm_encoder_bitrate_estimate_kbps': 'float', 'rm_min_qp': 'uint8_t', 'rm_last_min_qp_change_reason': 'int8_t'}, 'Metadata': {'Name': 'LowFreqStats'}}, '5': {'1': {'rm_rl_weighted_bwe_kbps': 'uint32_t', 'rm_rl_weighted_bwu_percent': 'uint16_t', 'rm_rl_packet_loss_percent': 'uint16_t', 'rm_rl_bitrate_kbps': 'uint32_t', 'rm_rl_fec_percent': 'uint8_t', 'rm_rl_qos_status': 'uint8_t', 'rl_frame_reasons': {'FlagType': 'uint8_t', 'Format': {'rm_rl_frame_drop': '1'}}}, 'Metadata': {'Name': 'RlStats'}}, '4': {'1': {'rm_native_frame_pacing_frame_count': 'uint32_t', 'rm_native_frame_pacing_avg_queue_time_ms': 'float', 'rm_native_frame_pacing_target_queue_time_ms': 'float', 'rm_native_frame_pacing_target_frame_time_ms': 'float', 'rm_native_frame_pacing_current_frame_time_ms': 'float', 'rm_native_frame_pacing_active': 'uint8_t'}, 'Metadata': {'Name': 'NativeFramePacing'}}, '7': {'1': {'rm_native_client_generic_stats_data0': 'int16_t', 'rm_native_client_generic_stats_data1': 'int16_t', 'rm_native_client_generic_stats_data2': 'int16_t', 'rm_native_client_generic_stats_data3': 'int16_t', 'rm_native_client_generic_stats_data4': 'int16_t', 'rm_native_client_generic_stats_data5': 'int16_t', 'rm_native_client_generic_stats_data6': 'int16_t', 'rm_native_client_generic_stats_data7': 'int16_t'}, 'Metadata': {'Name': 'NativeClientGenericStats'}}, '6': {'1': {'rm_native_client_frame_transcode_state_flags': 'uint8_t', 'rm_native_client_frame_transcode_encode_time_100us': 'uint16_t'}, 'Metadata': {'Name': 'NativeClientFrameTranscodeData'}}, '9': {'1': {'rm_native_client_qos_feedback_seq_number': 'uint32_t', 'rm_native_client_qos_feedback_arrival_timestamp_ms': 'double', 'rm_native_client_qos_feedback_owd_ms': 'float', 'rm_native_client_qos_feedback_jitter_us': 'float', 'rm_native_client_qos_feedback_packet_loss_rate': 'uint8_t', 'rm_native_client_qos_feedback_fec_percent': 'uint8_t', 'rm_native_client_qos_feedback_max_decode_fps': 'uint16_t', 'rm_native_client_qos_feedback_max_render_fps': 'uint16_t', 'rm_native_client_qos_feedback_quality_score': 'uint8_t', 'rm_native_client_qos_feedback_latency_score': 'uint8_t', 'rm_native_client_qos_feedback_loss_score': 'uint8_t', 'rm_native_client_qos_feedback_bandwidth_score': 'uint8_t', 'rm_native_client_qos_feedback_bw_util': 'uint8_t', 'rm_native_client_qos_feedback_bw_estimation': 'uint32_t', 'rm_native_client_qos_feedback_tx_rx_lag': 'uint16_t', 'rm_native_client_qos_feedback_rtd': 'uint16_t', 'rm_native_client_qos_feedback_feedback_jitter_us': 'float', 'rm_native_client_qos_feedback_avg_bwe': 'uint32_t', 'rm_native_client_qos_feedback_frame_bwe_kbps': 'uint32_t', 'rm_native_client_qos_feedback_avg_frame_bwe_kbps': 'uint32_t'}, 'Metadata': {'Name': 'NativeClientQosFeedback'}}, '8': {'1': {'rm_native_client_decode_data_missing': 'uint8_t'}, 'Metadata': {'Name': 'NativeClientFrameDecodeDataMissing'}}, '11': {'1': {'rm_native_rtc_client_app_fb_interval_ms': 'uint16_t', 'rm_native_rtc_client_app_fb_avg_decode_time_ms': 'uint16_t', 'rm_native_rtc_client_app_fb_frames_decoded': 'uint16_t', 'rm_native_rtc_client_app_fb_frames_dropped': 'uint16_t', 'rm_native_rtc_client_app_fb_num_packets_lost': 'uint16_t'}, 'Metadata': {'Name': 'NativeRtcClientAppFeedbackData'}}, '10': {'4': {'rm_num_packets_lost': 'uint16_t', 'rm_first_packet_rx_time_ms': 'double', 'rm_rx_to_decoder_present_delta_ms': 'float', 'rm_rx_to_decode_start_delta_ms': 'float', 'rm_rx_to_predecode_done_delta_ms': 'float', 'rm_rx_to_render_present_delta_ms': 'float', 'rm_rx_to_render_start_delta_ms': 'float', 'rm_rx_to_render_completed_delta_ms': 'float', 'rm_rx_to_present_completed_delta_ms': 'float', 'rm_rtp_lib_queue_time_ms': 'float', 'rm_fec_decode_time_ms': 'float', 'rm_frame_rx_duration_ms': 'float', 'rm_decode_frame_size': 'uint32_t', 'rm_rssi': 'int32_t', 'rm_nw_speed_kbps': 'uint32_t', 'frame_status_flags': {'FlagType': 'uint32_t', 'Format': {'rm_fec_triggered': '1', 'rm_fec_successful': '1', 'rm_frame_drop_on_decode_fail': '1', 'rm_frame_lost_at_render': '1', 'rm_frame_drop_on_packet_loss': '1', 'rm_frame_with_invalid_reference': '1', 'rm_frame_recovered_by_qec': '1', 'rm_frame_dropped_too_large': '1', 'rm_frame_drop_on_decode_skip': '1', 'rm_frame_with_out_of_order_packet': '1', 'rm_frame_never_received_by_client': '1', 'rm_frame_optimized_by_rtp_packet_counter': '1', 'rm_frame_with_packets_recovered_by_rtp_nack_deprecated': '1', 'rm_frame_with_congestion': '1', 'rm_frame_with_ecn_support': '1', 'rm_frame_with_fec_decode_failed': '1'}}, 'rm_frame_owd_ms': 'float', 'rm_total_ts_rx_gap_time_ms': 'float', 'rm_rx_to_present_completed_confirmed_delta_ms': 'float', 'rm_frame_render_gpu_duration_ms': 'float', 'rm_num_packets_recovered_by_nack': 'uint16_t', 'rm_rtp_inactivity_time_ms': 'float'}, 'Metadata': {'Name': 'NativeClientFrameDecodeData'}}, '13': {'2': {'rm_native_rtc_frame_rx_time_ms': 'double', 'rm_native_rtc_first_packet_rx_time_ms': 'double'}, 'Metadata': {'Name': 'NativeRtcBweAlgoStats'}}, '12': {'2': {'rm_native_rtc_client_pli_count': 'uint16_t', 'rm_native_rtc_client_nack_packet_capture_age_max_ms': 'uint16_t', 'rm_native_rtc_client_nack_request_max_packets_count': 'uint16_t', 'rm_native_rtc_client_nack_requests_count': 'uint16_t', 'rm_native_rtc_client_nacked_packets_count': 'uint16_t', 'rm_native_rtc_client_nack_not_served_packets_count': 'uint16_t', 'rm_native_rtc_client_key_frame_send_request_ignore_count': 'uint16_t', 'rm_native_rtc_client_delta_frames_dropped_on_preemptive_key_frame_send': 'uint16_t', 'rm_native_rtc_client_key_frame_send_reason': 'uint16_t'}, 'Metadata': {'Name': 'NativeRtcClientStats'}}, '15': {'1': {'rm_native_rtc_packets_received_per_frame': 'uint32_t'}, 'Metadata': {'Name': 'NativeRtcPacketReceivedStats'}}, '14': {'1': {'rm_res_width': 'uint16_t', 'rm_res_height': 'uint16_t', 'rm_res_encoder_frame_width': 'uint16_t', 'rm_res_encoder_frame_height': 'uint16_t', 'rm_res_qos_target_width': 'uint16_t', 'rm_res_qos_target_height': 'uint16_t', 'rm_res_qos_width': 'uint16_t', 'rm_res_qos_height': 'uint16_t', 'rm_res_game_width': 'uint16_t', 'rm_res_game_height': 'uint16_t', 'rm_res_prev_width': 'uint16_t', 'rm_res_prev_height': 'uint16_t', 'rm_res_prev_encoder_frame_width': 'uint16_t', 'rm_res_prev_encoder_frame_height': 'uint16_t', 'rm_res_prev_qos_target_width': 'uint16_t', 'rm_res_prev_qos_target_height': 'uint16_t', 'rm_res_prev_qos_width': 'uint16_t', 'rm_res_prev_qos_height': 'uint16_t', 'rm_res_prev_game_width': 'uint16_t', 'rm_res_prev_game_height': 'uint16_t'}, 'Metadata': {'Name': 'ResolutionStats'}}, '17': {'1': {'rm_native_rtc_client_feedback_seq_number': 'uint32_t', 'rm_native_rtc_client_feedback_rx_time_us': 'double', 'rm_native_rtc_client_owd_ms': 'double', 'rm_native_rtc_client_jitter_us': 'float', 'rm_native_rtc_client_avg_packet_loss_percent': 'uint8_t', 'rm_native_rtc_client_fec_percent': 'uint8_t', 'rm_native_rtc_client_avg_bwu': 'uint32_t', 'rm_native_rtc_client_qos_feedback_tx_rx_lag': 'uint16_t', 'rm_native_rtc_client_rtt_ms': 'uint64_t', 'rm_native_rtc_client_avg_frame_bwe_kbps': 'uint32_t'}, 'Metadata': {'Name': 'NativeRtcClientRtcpStats'}}, '16': {'2': {'rm_native_rtc_client_cpm_tracked_avg_dec_time_ms': 'uint16_t', 'rm_native_rtc_client_cpm_tracked_good_nw_avg_dec_time_ms': 'uint16_t', 'rm_native_rtc_client_cpm_tracked_avg_nack_size': 'uint16_t', 'rm_rtc_cpm_events': {'FlagType': 'uint16_t', 'Format': {'rm_rtc_cpm_skip_start_on_loss': '1', 'rm_rtc_cpm_skip_start_on_high_rtt_delta': '1', 'rm_rtc_cpm_monitoring_resume': '1', 'rm_rtc_cpm_skip_downgrade_static_region': '1', 'rm_rtc_cpm_downgrade_requested': '1', 'rm_rtc_cpm_skip_start_on_resolution_downgrade': '1', 'rm_rtc_cpm_disable_upgrade_on_bad_perf_start': '1', 'rm_rtc_cpm_disable_upgrade_on_bad_perf_stop': '1'}}}, 'Metadata': {'Name': 'RtcCpmStats'}}, '19': {'1': {'rm_cc_alpha': 'double', 'rm_pp_group_target': 'uint16_t', 'rm_pp_burst_target': 'uint16_t'}, 'Metadata': {'Name': 'L4STxStats'}}, '18': {'1': {'rm_perc_ce_marked_packets': 'uint8_t'}, 'Metadata': {'Name': 'L4SRxStats'}}}"


#pragma pack(pop)
