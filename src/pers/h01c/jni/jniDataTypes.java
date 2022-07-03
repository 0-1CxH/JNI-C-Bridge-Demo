package pers.h01c.jni;

import java.util.ArrayList;

public class jniDataTypes {
    static {
        System.loadLibrary("jniDataTypes");
    }

    static long callFuncCount = 0;
    int elementCount = 0;

    native float primitiveTypesFunc(boolean is_neg, short left_sift, int base , long after_point);
    native String stringTypeFunc(String base_str, int pre_len, int repeat_times);
    native int objectTypeFunc(ArrayList<String> array_list);

}
