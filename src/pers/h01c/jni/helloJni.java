package pers.h01c.jni;

public class helloJni {
    
    static {
        System.out.println(System.getProperty("java.library.path"));
        //System.loadLibrary("helloJni");
        System.loadLibrary("helloJniCpp");

    }

    public native void helloWorld(String inputArg);
    public native static String staticHelloWorld(String inputArg);
}
