import java.io.*;

public class WriteReadHandle {
    public WriteReadHandle(String filename) {
        FileReader in = null;
        FileWriter out = null;
        
    }
}

/*import java.io.*;
public class CopyFile {

   public static void main(String args[]) throws IOException {
      File file = new File("wtf_is_this.txt");
      file.createNewFile();
      FileReader in = null;
      FileWriter out = null;

      try {
         in = new FileReader("wtf_is_this.txt");
         out = new FileWriter("wtf_is_this.txt");
         
         out.write("kjblkjb");
      }finally {
         if (in != null) {
            in.close();
         }
         if (out != null) {
            out.close();
         }
      }
   }
}*/
