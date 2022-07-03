#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "pers_h01c_jni_helloJni.h"

JNIEXPORT void JNICALL Java_pers_h01c_jni_helloJni_helloWorld (JNIEnv * env, jobject obj, jstring str){
    const char * name = (*env) -> GetStringUTFChars(env, str, NULL);
    printf("hello %s", name);
};

JNIEXPORT jstring JNICALL Java_pers_h01c_jni_helloJni_staticHelloWorld (JNIEnv * env, jclass cls, jstring str){
    const char * name = (*env) -> GetStringUTFChars(env, str, NULL);

    jstring ret = (*env) -> NewStringUTF(env, name);
    return ret;
}
