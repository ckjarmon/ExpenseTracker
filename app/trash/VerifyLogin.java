package com.kyeou.expensetracker;

import java.io.IOException;

public class VerifyLogin {
    private String password;
    private String username;

    // loads the required password and username
   /* public void getCredentials() {
        this.password = AccountLogin.getPassword();// this will get the password that is stored
        this.username = AccountLogin.getUsername();// this will get the username that is stored
    }*/

    public void loadProfile(String username) throws IOException {

        new WriteReadHandle().WriteHandle("user.json", userLogIn(new WriteReadHandle().ReadHandle("user.json"), new WriteReadHandle().ReadHandle("transactions.json")));

    }


    public native String userLogIn(String USER_INFO_JSON, String TRANS_INFO_JSON);
}
