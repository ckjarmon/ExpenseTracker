//package main.cpp.headers;

import java.io.*;

public class WriteReadHandle {
   
   public WriteReadHandle(it)
   public void WriteHandle(String filename, String ttw) throws IOException {


      File path = getFilesDir();
      File file = new File(path, filename);
      file.createNewFile();
      FileOutputStream stream = new FileOutputStream(file);



     Writer out = new FileWriter(file);
      
      try {
         out.write(ttw);
      } finally {

         if (out != null) {
            out.close();
         }
      }

   }

   public String ReadHandle(String filename) throws IOException {
      File file = new File(filename);
      //file.createNewFile();
      FileReader in = new FileReader(file);
      String ret = "";

      try {

         int content;
         while ((content = in.read()) != -1) {
            //System.out.print((char) content);
            ret += (char)content;
         }
      } finally {
         if (in != null) {
            in.close();
         }
      }
      return ret;
   }



  
   public static void main(String args[]) throws IOException {
      //new WriteReadHandle("transactionsJSON.json", "[{\"Name\": \"FirstName LastName\",  \"A_O_T\": 0,  \"Budgets\": [1,2,3],\"Income\": 0,\"Scores\": [],\"SumDebits\": 0 }]");
      WriteReadHandle test = new WriteReadHandle();
      System.out.println(test.ReadHandle("transactionsJSON.json"));
   }//end main 
}

/*
 * import java.io.*;
 * public class CopyFile {
 * 
 * public static void main(String args[]) throws IOException {
 * File file = new File("wtf_is_this.txt");
 * file.createNewFile();
 * FileReader in = null;
 * FileWriter out = null;
 * 
 * try {
 * in = new FileReader("wtf_is_this.txt");
 * out = new FileWriter("wtf_is_this.txt");
 * 
 * out.write("kjblkjb");
 * }finally {
 * if (in != null) {
 * in.close();
 * }
 * if (out != null) {
 * out.close();
 * }
 * }
 * }
 * }
 */