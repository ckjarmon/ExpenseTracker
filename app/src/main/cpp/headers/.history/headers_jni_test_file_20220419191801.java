
public class headers_jni_test_file {

    static {
        System.loadLibrary("native");
    }
    
    public static void main(String[] args) {
        headers_jni_test_file() new headers_jni_test_file().TESTSEQ();
    }

    // Declare a native method sayHello() that receives no arguments and returns void
    private native void TESTSEQ();
}