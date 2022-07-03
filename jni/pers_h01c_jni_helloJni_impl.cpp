//
// Created by Qicheng Hu on 2022/7/2.
//
#include <iostream>
#include <string>

#include "pers_h01c_jni_helloJni.h"

using namespace std;

std::string jstring2string(JNIEnv*env, jstring jstr)
{
    const char* tmpStr = env->GetStringUTFChars(jstr, nullptr);
    std::string ret(tmpStr);
    env->ReleaseStringUTFChars(jstr, tmpStr);
    return ret;
}

jstring string2jstring(JNIEnv* env, std::string str)
{
    return env->NewStringUTF(str.c_str());
}


JNIEXPORT void JNICALL Java_pers_h01c_jni_helloJni_helloWorld (JNIEnv * env, jobject jobj, jstring str){
    const string &s = jstring2string(env, str);
    string cstring0 = "jni-cpp:" + s;
    cout << cstring0 << endl;
}

JNIEXPORT jstring JNICALL Java_pers_h01c_jni_helloJni_staticHelloWorld(JNIEnv * env, jclass jcls, jstring str){
    const string &s = jstring2string(env, str);
    string cstring0 = "input_string=" + s;
    return string2jstring(env, cstring0);
}
