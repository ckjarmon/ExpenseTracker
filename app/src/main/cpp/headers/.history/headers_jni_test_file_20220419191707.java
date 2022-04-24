
public class headers_jni_test_file {

    static {
        System.loadLibrary("native");
    }
    
    public static void main(String[] args) {
        new headers_jni_test_file().TESTSEQ("{\"Name\": \"FirstName LastName\",  \"A_O_T\": 0,  \"Budgets\": [1,2,3],\"Income\": 0,\"Scores\": [],\"SumDebits\": 0 }");
    }

    // Declare a native method sayHello() that receives no arguments and returns void
    private native void TESTSEQ();
}