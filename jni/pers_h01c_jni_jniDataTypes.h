/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class pers_h01c_jni_jniDataTypes */

#ifndef _Included_pers_h01c_jni_jniDataTypes
#define _Included_pers_h01c_jni_jniDataTypes
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     pers_h01c_jni_jniDataTypes
 * Method:    primitiveTypesFunc
 * Signature: (ZSIJ)F
 */
JNIEXPORT jfloat JNICALL Java_pers_h01c_jni_jniDataTypes_primitiveTypesFunc
  (JNIEnv *, jobject, jboolean, jshort, jint, jlong);

/*
 * Class:     pers_h01c_jni_jniDataTypes
 * Method:    stringTypeFunc
 * Signature: (Ljava/lang/String;II)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_pers_h01c_jni_jniDataTypes_stringTypeFunc
  (JNIEnv *, jobject, jstring, jint, jint);

/*
 * Class:     pers_h01c_jni_jniDataTypes
 * Method:    objectTypeFunc
 * Signature: (Ljava/util/ArrayList;)I
 */
JNIEXPORT jint JNICALL Java_pers_h01c_jni_jniDataTypes_objectTypeFunc
  (JNIEnv *, jobject, jobject);

#ifdef __cplusplus
}
#endif
#endif
