#include <jni.h>
#include <string>


#include "opencv2/core/core.hpp"

extern "C" JNIEXPORT jstring

JNICALL
Java_com_hiowls_www_quickstart_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
extern "C"
JNIEXPORT jstring JNICALL
Java_com_hiowls_www_quickstart_MainActivity_validate(JNIEnv *env, jobject instance, jlong matAddrGr,
                                                     jlong matAddrRgba) {

    // TODO
    cv::Rect();
    cv::Mat();
    std::string hello2 = "Hello from validate";


    return env->NewStringUTF(hello2.c_str());
}