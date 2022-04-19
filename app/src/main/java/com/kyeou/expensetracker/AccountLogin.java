package com.kyeou.expensetracker;
import java.io.Writer;
import java.io.Reader;

public class AccountLogin {
    //get functions to retrieve the password and username
    //need to figure out where they will be stored but for now they will be in a separate file i guess
    public static String getPassword(){
        String password = "";

        return password;
    }

    public static String getUsername(){
        String username = "";

        return username;
    }
    //creates a new account for a new user
    public void createNewAccount(String password, String username){
        if(isNewAccount(username))
            System.out.println("account already exists");
        else{
            setLogin();
        }
    }

    //setters for users new password and username
    //write the pw and un in a file
    public void setLogin(){

    }

    //user has an existing account
    public void verifyLogin (){

    }

    public boolean isNewAccount(String username){
        if(username == getUsername())
            return true;
        return false;
    }
}
