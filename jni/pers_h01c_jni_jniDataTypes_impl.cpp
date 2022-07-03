#include <string>
#include "pers_h01c_jni_jniDataTypes.h"
using namespace std;
JNIEXPORT jfloat JNICALL Java_pers_h01c_jni_jniDataTypes_primitiveTypesFunc
(JNIEnv * env, jobject obj, jboolean is_neg, jshort left_shift, jint base, jlong after_point){
    jfloat ret = 0;
    base = base << left_shift;
    jfloat temp = after_point;
    while(temp > 1){
        temp = temp/10.0;
    }
    ret = base + temp;
    if(is_neg&&ret>0){
        ret = -ret;
    }
    return ret;
}

JNIEXPORT jstring JNICALL Java_pers_h01c_jni_jniDataTypes_stringTypeFunc
(JNIEnv * env, jobject obj, jstring base_string, jint pre_len, jint repeat){
    jboolean b(JNI_TRUE);
    const char * base_string_char_array = env ->GetStringUTFChars(base_string, &b);
    string s(base_string_char_array);
    env->ReleaseStringUTFChars(base_string, base_string_char_array);
    s = s.substr(0, pre_len);
    while(repeat){
        s += s;
        repeat--;
    }
    jstring ret = env ->NewStringUTF(s.c_str());
    return ret;
}

JNIEXPORT jint JNICALL Java_pers_h01c_jni_jniDataTypes_objectTypeFunc
(JNIEnv * env, jobject obj, jobject array_list){
    jclass obj_class = env->GetObjectClass(obj);

    // pers.h01c.jni.jniDataTypes.callFuncCount += 1
    jfieldID static_func_call_field_id = env->GetStaticFieldID(obj_class, "callFuncCount", "J");
    jlong static_func_call_value = env->GetStaticLongField(obj_class, static_func_call_field_id);
    env->SetStaticLongField(obj_class, static_func_call_field_id, static_func_call_value+1);

    // array_list_size = array_list.size()
    jclass array_list_class = env->GetObjectClass(array_list);
    jmethodID size_method_id = env->GetMethodID(array_list_class, "size", "()I");
    jint array_list_size = env->CallIntMethod(array_list, size_method_id);

    // elementCount += array_list_size
    jfieldID elem_cnt_field_id = env->GetFieldID(obj_class, "elementCount", "I");
    jint elem_cnt_value = env->GetIntField(obj, elem_cnt_field_id);
    env->SetIntField(obj, elem_cnt_field_id, elem_cnt_value+array_list_size);

    return array_list_size;
}