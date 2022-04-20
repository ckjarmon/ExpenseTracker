
public class headers_jni_test_file {

    static {
        System.loadLibrary("native");
    }
    
    public static void main(String[] args) {
        headers_jni_test_file fuck =  new headers_jni_test_file();
        fuck.TESTSEQ("{\"Name\": \"FirstName LastName\",  \"A_O_T\": 0,  \"Budgets\": [1,2,3],\"Income\": 0,\"Scores\": [],\"SumDebits\": 0 }");
    }

    // Declare a native method sayHello() that receives no arguments and returns void
    private native string TESTSEQ(String j);
}