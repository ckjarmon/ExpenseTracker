package com.kyeou.expensetracker;

import java.io.IOException;

public class VerifyLogin {
    private String password;
    private String username;

    // loads the required password and username
    public void getCredentials() {
        this.password = AccountLogin.getPassword();// this will get the password that is stored
        this.username = AccountLogin.getUsername();// this will get the username that is stored
    }

    public void loadProfile(String username) throws IOException {
        // this will call all methods required to login and load a users profile
        // From Christion: On a successful login this method should open up the
        // user.json
        /*
         * {
         * "A_O_T": 2.0,
         * "Budgets": [],
         * "Income": 0,
         * "Name": "FirstName LastName",
         * "Scores": [],
         * "SumDebits": 0
         * }
         */
        new WriteReadHandle().WriteHandle("user.json", userLogIn(new WriteReadHandle().ReadHandle("user.json"), new WriteReadHandle().ReadHandle("transactions.json")));

    }

    // this method will verify if the the username and password given by the user
    // matches what was
    // found in the database
    public boolean isUsernameAndPassword(String username, String password) throws IOException {
        getCredentials();
        if (!this.username.equals(username) || !this.password.equals(password)) {
            System.out.println("Incorrect username or password");
            return false;
        }
        loadProfile(username);
        return true;
    }
    public native String userLogIn(String USER_INFO_JSON, String TRANS_INFO_JSON);
}
