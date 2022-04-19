package com.kyeou.expensetracker;


public class VerifyLogin {
    private String password;
    private String username;

    //public VerifyLogin(String username, String password) {

    //}
    //loads the required password and username
    public void getCredentials(){
        this.password = AccountLogin.getPassword();//this will get the password that is stored
        this.username = AccountLogin.getUsername();//this will get the username that is stored
    }

    public void loadProfile(){
        //this will call all methods required to login and load a users profile
    }

    //this method will verify if the the username and password given by the user matches what was
    //found in the database
    public boolean isUsernameAndPassword (String username, String password){
        if(this.username!=username || this.password!=password) {
            System.out.println("Incorrect username or password");
            return false;
        }
        return true;
    }
}

