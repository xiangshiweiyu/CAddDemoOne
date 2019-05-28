#include <jni.h>
#include <string>

#define LOGI(FORMAT,...) __android_log_print(ANDROID_LOG_INFO,"ywl5320",FORMAT,##__VA_ARGS__);

extern "C" JNIEXPORT jstring JNICALL
Java_com_hxd_player_Test_stringFromJNI(JNIEnv *env, jobject instance) {
    std::string hello = "数据迁移成功";
    return env->NewStringUTF(hello.c_str());
}

#include <android/log.h>
extern "C"{
#include "include/libavformat/avformat.h"
#include "include/libavutil/avutil.h"
#include "include/libavcodec/avcodec.h"
}


extern "C"
JNIEXPORT void JNICALL
Java_com_hxd_player_Test_TestFFmpeg(JNIEnv *env, jobject instance) {
    //导入头文件
    av_register_all();
    AVCodec *c_temp = av_codec_next(NULL);
    while (c_temp != NULL)
    {
        switch (c_temp->type)
        {
            case AVMEDIA_TYPE_VIDEO:
                LOGI("[Video]:%s", c_temp->name);
                break;
            case AVMEDIA_TYPE_AUDIO:
                LOGI("[Audio]:%s", c_temp->name);
                break;
            default:
                LOGI("[Other]:%s", c_temp->name);
                break;
        }
        c_temp = c_temp->next;
    }

}