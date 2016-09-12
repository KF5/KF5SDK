//
//  KFDispatcher.h
//  SampleSDKApp
//
//  Created by admin on 15/4/1.
//  Copyright (c) 2015年 admin. All rights reserved.
//

#import <Foundation/Foundation.h>
@class KFAgent;
@class KFError;
@class KFMessage;
@class KFUser;
@interface KFDispatcher : NSObject

/**
 *  用户信息验证方式
 */
typedef NS_ENUM(NSInteger,KFVerifyUserType){
    KFVerifyUserTypeDefault = 0,    // 使用默认,以邮箱为验证方式
    KFVerifyUserTypeEmail,          // 以邮箱为验证方式
    KFVerifyUserTypePhone           // 以手机号为验证方式
};

/**
 *  NavBarButton的显示方式
 */
typedef NS_ENUM(NSInteger,KFNavBarUIType){
    KFNavBarUITypeLocalizedLabel = 0,   // NavBarButton设置为文字
    KFNavBarUITypeImage,                // NavBarButton设置为图片
    KFNavBarUITypeNone                  // NavBarButton不显示
};

/**
 *  文档展示方式
 */
typedef NS_ENUM(NSInteger,KFHelpCenterType){
    KFHelpCenterTypeDefault = 0,  // 使用默认,默认使用KFHelpCenterTypeCategory
    KFHelpCenterTypeCategory,     // 分区列表
    KFHelpCenterTypeForum,        // 分类列表
    KFHelpCenterTypePost,         // 文档列表
};

/**
 *  消息发送状态
 */
typedef NS_ENUM(NSInteger,KFMessageStatus) {
    KFMessageStatusSending = 0,
    KFMessageStatusSuccess,
    KFMessageStatusFailure
};
/**
 *  消息类型
 */
typedef NS_ENUM(NSInteger,KFMessageType) {
    KFMessageTypeText = 0,
    KFMessageTypeImage,
    KFMessageTypeVoice,
    KFMessageTypeSystem,
    KFMessageTypeOther,
    KFMessageTypeAI
};
/**
 *  消息来自于
 */
typedef NS_ENUM(NSInteger,KFMessageFrom) {
    KFMessageFromMe = 0,
    KFMessageFromOther
};
/**
 *  聊天客服角色
 */
typedef NS_ENUM(NSInteger,KFAgentRole) {
    KFAgentRoleAgent = 0,    // 人工客服
    KFAgentRoleAI            // 机器人客服
};

/**
 *  当前对话状态
 */
typedef NS_ENUM(NSInteger,KFChatStatus) {
    KFChatStatusNone = 0,
    KFChatStatusAIAgent,    // 正在和机器人对话
    KFChatStatusChatting,   // 正在进行对话
    KFChatStatusQueue,      // 正在排队
};
/**
 *  错误类型
 */
typedef NS_ENUM(NSInteger,KFErrorCode) {
    KFErrorCodeNone            = 0,     // 没有错误
    KFErrorCodeDeprecated      = 1000,  // 过期方法错误提醒
    KFErrorCodeAgentOffline    = 1001,  // 没有客服在线
    KFErrorCodeAgentBusy       = 1002,  // 客服忙碌
    KFErrorCodeSocketError     = 5000,  // 服务器连接失败
    KFErrorCodeSocketTimeOut   = 303,   // 服务器请求超时
    KFErrorCodeParamError      = 3004,  // 参数错误
    KFErrorCodeNetWorkOff      = 30000, // 网络断开
    KFErrorCodeSocketOff       = 30001, // 与服务器断开连接
    KFErrorCodeRecordFailure   = 500001,// 录音出错
    KFErrorCodeAudioPalyError  = 500002,// 录音播放出错
    KFErrorCodeRecordTimeShort = 20000, // 录音时间过短
};

/**
 * API success block.
 */
typedef void (^KFAPISuccess) (NSDictionary *result);
/**
 * API error block
 */
typedef void (^KFAPIError) (KFError *error);

@end
