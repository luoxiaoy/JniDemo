//
// Created by Administrator on 2016/7/1.
//

#ifndef JNIDEMO_LOG_H
#define JNIDEMO_LOG_H

#include <jni.h>
#include <android/log.h>

#define TAG	"test_jni"

#define LOGI(...)	__android_log_print(ANDROID_LOG_INFO, TAG, __VA_ARGS__)
#define LOGD(...)	__android_log_print(ANDROID_LOG_DEBUG, TAG, __VA_ARGS__)
#define LOGW(...)	__android_log_print(ANDROID_LOG_WARN, TAG, __VA_ARGS__)
#define	LOGE(...)	__android_log_print(ANDROID_LOG_ERROR, TAG, __VA_ARGS__)

#endif //JNIDEMO_LOG_H
