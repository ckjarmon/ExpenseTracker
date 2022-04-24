package com.kyeou.expensetracker;

import java.io.IOException;
import java.io.PrintStream;
import java.io.File;

import java.util.Scanner;

public class AccountLogin {

    //get functions to retrieve the password and username
    //need to figure out where they will be stored but for now they will be in a separate file i guess
    public static String getPassword(){
        String[] arrS;
        String password = "";
        try{
            Scanner sc = new Scanner(new File("ExpenseTracker.dat"));
            while(sc.hasNextLine()){
                String temp = sc.nextLine();
                if(temp.contains("password: ")){
                    arrS =temp.split(" ");
                    return arrS[1];
                }
            }
        }catch(IOException e){
            System.out.println(e);
        }
        return password;
    }

    public static String getUsername(){
        String[] arrS;
        String username = "";
        try{
            Scanner sc = new Scanner(new File("ExpenseTracker.dat"));
            while(sc.hasNextLine()){
                String temp = sc.nextLine();
                if(temp.contains("username: ")){
                    arrS =temp.split(" ");
                    return arrS[1];
                }
            }
        }catch(IOException e){
            System.out.println(e);
        }
        return username;
    }

    //creates a new account for a new user
    public void createNewAccount(String password, String username){
        if(isNewAccount(username))
            System.out.println("account already exists");
        else{
            setLogin(username,password);
        }
    }

    //setters for users new password and username
    //write the pw and un in a file
    public void setLogin(String username, String password){
        try{
            PrintStream writer = new PrintStream(new File("ExpenseTracker.dat"));
            writer.println("username: "+username);
            writer.println("password: "+password);
        }
        catch(IOException e){
            System.out.println(e);
        }
    }

    //user has an existing account and logs into their account
    public void verifyLogin (String username, String password){
        VerifyLogin userProfile = new VerifyLogin();
        userProfile.isUsernameAndPassword(username, password);
    }

    public boolean isNewAccount(String username){
        return username.equals(getUsername());
    }
}
