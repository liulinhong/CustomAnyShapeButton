//
//  BlinkEngine.h
//
//  Created by HaibingTang on 16/7/21.
//  Copyright © 2016年 BridgeMind. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


typedef NS_ENUM(NSInteger, BlinkWarningCode) {
  Blink_Warn_Pending = 20,
  Blink_Warn_NoAvailableChannel = 103,
  Blink_Warn_LookupChannelTimeout = 104,
  Blink_Warn_LookupChannelRejected = 105,
  Blink_Warn_OpenChannelTimeout = 106,
  Blink_Warn_OpenChannelRejected = 107,
  Blink_Warn_Adm_RuntimePlayoutWarning = 1014,
  Blink_Warn_Adm_RuntimeRecordingWarning = 1016,
  Blink_Warn_Adm_RecordAudioSilence = 1019,
  Blink_Warn_Adm_PlaybackMalfunction = 1020,
  Blink_Warn_Adm_RecordMalfunction = 1021,
  Blink_Warn_Adm_Interruption = 1025,
  Blink_Warn_Adm_RouteChange = 1026,
  Blink_Warn_Apm_Howling = 1051,
};

typedef NS_ENUM(NSInteger, BlinkErrorCode) {
  Blink_Error_NoError = 0,
  Blink_Error_Failed = 1,
  Blink_Error_InvalidArgument = 2,
  Blink_Error_NotReady = 3,
  Blink_Error_NotSupported = 4,
  Blink_Error_Refused = 5,
  Blink_Error_BufferTooSmall = 6,
  Blink_Error_NotInitialized = 7,
  Blink_Error_InvalidView = 8,
  Blink_Error_NoPermission = 9,
  Blink_Error_TimedOut = 10,
  Blink_Error_Canceled = 11,
  Blink_Error_TooOften = 12,
  Blink_Error_BindSocket = 13,
  Blink_Error_NetDown = 14,
  Blink_Error_NoBufs = 15,
  Blink_Error_InitVideo = 16,
  Blink_Error_JoinChannelRejected = 17,
  Blink_Error_LeaveChannelRejected = 18,
  Blink_Error_AlreadyInUse = 19,
  
  Blink_Error_InvalidVendorKey = 101,
  Blink_Error_InvalidChannelName = 102,
  Blink_Error_DynamicKeyTimeout = 109,
  Blink_Error_InvalidDynamicKey = 110,
  
  Blink_Error_LoadMediaEngine = 1001,
  Blink_Error_StartCall = 1002,
  Blink_Error_StartCamera = 1003,
  Blink_Error_StartVideoRender = 1004,
  Blink_Error_Adm_GeneralError = 1005,
  Blink_Error_Adm_JavaResource = 1006,
  Blink_Error_Adm_SampleRate = 1007,
  Blink_Error_Adm_InitPlayout = 1008,
  Blink_Error_Adm_StartPlayout = 1009,
  Blink_Error_Adm_StopPlayout = 1010,
  Blink_Error_Adm_InitRecording = 1011,
  Blink_Error_Adm_StartRecording = 1012,
  Blink_Error_Adm_StopRecording = 1013,
  Blink_Error_Adm_RuntimePlayoutError = 1015,
  Blink_Error_Adm_RuntimeRecordingError = 1017,
  Blink_Error_Adm_RecordAudioFailed = 1018,
  Blink_Error_Adm_Play_Abnormal_Frequency = 1020,
  Blink_Error_Adm_Record_Abnormal_Frequency = 1021,
  Blink_Error_Adm_Init_Loopback  = 1022,
  Blink_Error_Adm_Start_Loopback = 1023,
  Blink_Error_Vdm_Camera_Not_Authorized = 1501,
};

typedef NS_ENUM(NSInteger, BlinkChannelProfile) {
  Blink_ChannelProfile_Free = 0,
  Blink_ChannelProfile_Broadcaster = 1,
  Blink_ChannelProfile_Audience = 2,
};

typedef NS_ENUM(NSInteger, BlinkVideoProfile) {
  // res       fps  kbps
  Blink_VideoProfile_Invalid = -1,
  Blink_VideoProfile_120P = 0,         // 160x120   15   80
  Blink_VideoProfile_120P_2 = 1,		// 120x160   15   80
#if TARGET_OS_IPHONE
  Blink_VideoProfile_120P_3 = 2,		// 120x120   15   60
  Blink_VideoProfile_180P = 10,		// 320x180   15   160
  Blink_VideoProfile_180P_2 = 11,		// 180x320   15   160
  Blink_VideoProfile_180P_3 = 12,		// 180x180   15   120
#endif
  Blink_VideoProfile_240P = 20,		// 320x240   15   200
  Blink_VideoProfile_240P_2 = 21,		// 240x320   15   200
#if TARGET_OS_IPHONE
  Blink_VideoProfile_240P_3 = 22,		// 240x240   15   160
#endif
  Blink_VideoProfile_360P = 30,		// 640x360   15   400
  Blink_VideoProfile_360P_2 = 31,		// 360x640   15   400
#if TARGET_OS_IPHONE
  Blink_VideoProfile_360P_3 = 32,		// 360x360   15   300
#endif
  Blink_VideoProfile_360P_4 = 33,		// 640x360   30   680
  Blink_VideoProfile_360P_5 = 34,		// 360x640   30   680
  Blink_VideoProfile_360P_6 = 35,		// 360x360   30   500
  Blink_VideoProfile_480P = 40,		// 640x480   15   500
  Blink_VideoProfile_480P_2 = 41,		// 480x640   15   500
#if TARGET_OS_IPHONE
  Blink_VideoProfile_480P_3 = 42,		// 480x480   15   400
#endif
  Blink_VideoProfile_480P_4 = 43,		// 640x480   30   750
  Blink_VideoProfile_480P_5 = 44,		// 480x640   30   750
  Blink_VideoProfile_480P_6 = 45,		// 480x480   30   680
  Blink_VideoProfile_480P_7 = 46,		// 640x480 15 1000
  Blink_VideoProfile_720P = 50,		// 1280x720  15   1000
  Blink_VideoProfile_720P_2 = 51,		// 720x1280  15   1000
  Blink_VideoProfile_720P_3 = 52,		// 1280x720  30   1700
  Blink_VideoProfile_720P_4 = 53,		// 720x1280  30   1700
  Blink_VideoProfile_1080P = 60,		// 1920x1080 15   1500
  Blink_VideoProfile_1080P_2 = 61,		// 1080x1920 15   1500
  Blink_VideoProfile_1080P_3 = 62,		// 1920x1080 30   2550
  Blink_VideoProfile_1080P_4 = 63,		// 1080x1920 30   2550
  Blink_VideoProfile_1080P_5 = 64,		// 1920x1080 60   4300
  Blink_VideoProfile_1080P_6 = 65,		// 1080x1920 60   4300
  Blink_VideoProfile_4K = 70,			// 3840x2160 30   8000
  Blink_VideoProfile_4K_2 = 71,		// 2160x3080 30   8000
  Blink_VideoProfile_4K_3 = 72,		// 3840x2160 60   13600
  Blink_VideoProfile_4K_4 = 73,		// 2160x3840 60   13600
  Blink_VideoProfile_DEFAULT = Blink_VideoProfile_360P,
  Blink_VideoProfile_480P_HIGH = 100,		// 480x480   30   680
};

typedef NS_ENUM(NSUInteger, BlinkQuality) {
  Blink_Quality_Unknown = 0,
  Blink_Quality_Excellent = 1,
  Blink_Quality_Good = 2,
  Blink_Quality_Poor = 3,
  Blink_Quality_Bad = 4,
  Blink_Quality_VBad = 5,
  Blink_Quality_Down = 6,
};

typedef NS_ENUM(NSUInteger, BlinkUserOfflineReason) {
  Blink_UserOffline_Quit = 0,
  Blink_UserOffline_Dropped = 1,
};

typedef NS_ENUM(NSUInteger, BlinkLogFilter) {
  Blink_LogFilter_Console = 0x08000,
  Blink_LogFilter_Debug = 0x0800,
  Blink_LogFilter_Info = 0x0001,
  Blink_LogFilter_Warn = 0x0002,
  Blink_LogFilter_Error = 0x0004,
  Blink_LogFilter_Critical = 0x0008,
};

typedef NS_ENUM(NSUInteger, BlinkRenderMode) {
  /**
   Hidden(1): If the video size is different than that of the display window, crops the borders of the video (if the video is bigger) or stretch the video (if the video is smaller) to fit it in the window.
   */
  Blink_Render_Hidden = 1,
  
  /**
   Blink_Render_Fit(2): If the video size is different than that of the display window, resizes the video proportionally to fit the window.
   */
  Blink_Render_Fit = 2,
  
  /**
   Blink_Render_Adaptive(3)：If both callers use the same screen orientation, i.e., both use vertical screens or both use horizontal screens, the Blink_Render_Hidden mode applies; if they use different screen orientations, i.e., one vertical and one horizontal, the Blink_Render_Fit mode applies.
   */
  Blink_Render_Adaptive = 3,
};

typedef NS_ENUM(NSUInteger, BlinkQualityReportFormat) {
  Blink_QualityReportFormat_Json = 0,
  Blink_QualityReportFormat_Html = 1,
};

__attribute__((visibility("default"))) @interface BlinkStats : NSObject
@property (assign, nonatomic) NSUInteger duration;
@property (assign, nonatomic) NSUInteger txBytes;
@property (assign, nonatomic) NSUInteger rxBytes;
@property(assign, nonatomic) NSUInteger users;
@end

__attribute__((visibility("default"))) @interface BlinkLocalVideoStats : NSObject
@property (assign, nonatomic) NSUInteger sentBitrate;
@property (assign, nonatomic) NSUInteger sentFrameRate;
@end

__attribute__((visibility("default"))) @interface BlinkRemoteVideoStats : NSObject
@property (assign, nonatomic) NSUInteger uid;
@property (assign, nonatomic) NSUInteger delay;
@property (assign, nonatomic) NSUInteger width;
@property (assign, nonatomic) NSUInteger height;
@property (assign, nonatomic) NSUInteger receivedBitrate;
@property (assign, nonatomic) NSUInteger receivedFrameRate;
@end

__attribute__((visibility("default"))) @interface BlinkAudioVolumeInfo : NSObject
@property (assign, nonatomic) NSUInteger uid;
@property (assign, nonatomic) NSUInteger volume;
@end

typedef NS_ENUM(NSInteger, BlinkLogonState) {
  kLogonStateLogoning,
  kLogonStateLogon,
  kLogonStateLogoffing,
  kLogonStateLogoff
};

typedef NS_ENUM(NSInteger, BlinkJoinState) {
  kJoinStateLeft,
  kJoinStateJoining,
  kJoinStateJoined
};

typedef NS_ENUM(NSInteger, BlinkSessionConnectionState) {
  kSessionConnectionStateNew,
  kSessionConnectionStateChecking,
  kSessionConnectionStateConnected,
  kSessionConnectionStateCompleted,
  kSessionConnectionStateFailed,
  kSessionConnectionStateDisconnected,
  kSessionConnectionStateClosed,
  kSessionConnectionStateCount,
};

@class BlinkEngine;

@protocol BlinkEngineDelegate <NSObject>
@optional
#pragma Signaling
- (void) blinkEngine:(BlinkEngine *)engine onLogonComplete:(BOOL)success;
- (void) blinkEngine:(BlinkEngine *)engine onLogoffComplete:(BOOL)success;
- (void) blinkEngine:(BlinkEngine *)engine onJoinComplete:(BOOL)success;
- (void) blinkEngine:(BlinkEngine *)engine onLeaveComplete:(BOOL)success;
- (void) blinkEngine:(BlinkEngine *)engine onUserJoined:(NSString *)userId;
- (void) blinkEngine:(BlinkEngine *)engine onUserLeft:(NSString *)userId;

#pragma AudioVideo
- (void) blinkEngine:(BlinkEngine *)engine onSessionState:(BlinkSessionConnectionState)state;
- (void) blinkEngine:(BlinkEngine *)engine firstRemoteVideoFrameOfUid:(NSString *)uid;
- (void) blinkEngine:(BlinkEngine *)engine onAudioVidoeStats:(NSString *)stats;
- (void) blinkEngine:(BlinkEngine *)engine onAudioVidoeError:(NSError *)error;
- (void) onLocalVideoTrack:(BlinkEngine *)engine;
- (void) onAudioDeviceReady:(BlinkEngine *)engine;
- (void) blinkEngine:(BlinkEngine *)engine onRemoteVideoView:(UIView *)view changeVidoeSize:(CGSize)size;
@end

__attribute__((visibility("default"))) @interface BlinkEngine : NSObject

@property (nonatomic, assign) BOOL isAudioOnly;
@property (nonatomic, assign) BlinkLogonState state;
@property (nonatomic, assign) BlinkJoinState joinState;
@property (nonatomic, weak) id<BlinkEngineDelegate> delegate;


+ (BlinkEngine *)sharedBlinkEngine;

- (void)logonWithUserId: (NSString*)userId;
- (void)logoff;
- (void) joinChannel:(NSString*)channel
         isAudioOnly:(BOOL)isAudioOnly;
- (void)leaveChannel;
- (void)hangup;
- (void)enableState;
- (UIView *)createLocalView: (CGRect)frame;
- (UIView *)createRemoteView:(CGRect)frame forUser:(NSString *)userId;
- (void)switchCamera;
- (void)switchSpeaker:(BOOL)isOn;
- (BOOL)isSpeakerOn;
- (void)muteAudio:(BOOL)isMute;
- (void)muteVideo:(BOOL)isMute;
@end
