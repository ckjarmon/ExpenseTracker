package com.kyeou.expensetracker;//package main.cpp.headers;

import java.io.File;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;


public class WriteReadHandle {
   


   public void createFiles() throws IOException {

      File file = new File("user.json");
   file.createNewFile();
     /* try {
         fos = new FileOutputStream(file);
         //fos.write("".getBytes());
      } catch (FileNotFoundException e) {
         e.printStackTrace();
      } finally {
         if (fos != null) {
            try {
               fos.close();
            } catch (IOException e) {
               e.printStackTrace();
            }
         }
      }*/
      file = new File("transactions.json");
      file.createNewFile();
      /*
      try {
         fos = new FileOutputStream("transactions.json");
         //fos.write("".getBytes());
      } catch (FileNotFoundException e) {
         e.printStackTrace();
      } finally {
         if (fos != null) {
            try {
               fos.close();
            } catch (IOException e) {
               e.printStackTrace();
            }
         }
      }*/
   }//end function



   public void WriteHandle(String filename, String ttw) throws IOException {


      //File path = getFilesDir();
      //File file = new File(path, filename);
      File file = new File(filename);
      file.createNewFile();
      new FileOutputStream(file);


      try (FileWriter out = new FileWriter(file)) {
         out.write(ttw);
         //stream.write(ttw.getBytes());
      }

   }

   public String ReadHandle(String filename) throws IOException {
      File file = new File(filename);
      //file.createNewFile();
      FileReader in = new FileReader(file);
      StringBuilder ret = new StringBuilder();

      try {

         int content;
         while ((content = in.read()) != -1) {
            //System.out.print((char) content);
            ret.append((char) content);
         }
      } finally {
         in.close();
      }
      return ret.toString();
   }



  
   public static void main(String[] args) throws IOException {
      //new WriteReadHandle("transactionsJSON.json", "[{\"Name\": \"FirstName LastName\",  \"A_O_T\": 0,  \"Budgets\": [1,2,3],\"Income\": 0,\"Scores\": [],\"SumDebits\": 0 }]");
      WriteReadHandle test = new WriteReadHandle();
      System.out.println(test.ReadHandle("transactionsJSON.json"));
      System.out.println(new WriteReadHandle().ReadHandle("transactionsJSON.json"));
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