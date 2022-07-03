package pers.h01c.jni;

import java.util.ArrayList;

public class testDrive {


    public static void main(String[] args) {
        helloJni h = new helloJni();
        Class cls = h.getClass();
        System.out.println(cls);
        h.helloWorld("你好 hello jni");
        System.out.println(helloJni.staticHelloWorld("static 静态你好 jni"));

        jniDataTypes dt = new jniDataTypes();
        float ret = dt.primitiveTypesFunc(true, (short) 5, 2, 123456);
        System.out.println(ret);
        // output should be: -62.123456

        System.out.println(dt.stringTypeFunc("jnithispartnotshown", 3, 3));
        // output should be: jnijnijnijnijnijnijnijni

        ArrayList<String> arr = new ArrayList<>();
        System.out.printf("object.elementCount = %d, class.callCount = %d\n", dt.elementCount, jniDataTypes.callFuncCount);
        for(int i=0; i<10; i++){arr.add("hello");}
        System.out.println(dt.objectTypeFunc(arr));
        System.out.printf("object.elementCount = %d, class.callCount = %d\n", dt.elementCount, jniDataTypes.callFuncCount);
        for(int i=0; i<5; i++){arr.add("hello");}
        System.out.println(dt.objectTypeFunc(arr));
        System.out.printf("object.elementCount = %d, class.callCount = %d\n", dt.elementCount, jniDataTypes.callFuncCount);
        // output should be:
        // object.elementCount = 0, class.callCount = 0
        // 10
        // object.elementCount = 10, class.callCount = 1
        // 15
        // object.elementCount = 25, class.callCount = 2
    }

}
