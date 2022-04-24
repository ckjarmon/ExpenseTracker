package com.kyeou.expensetracker;

public class VerifyLogin {
    private String password;
    private String username;

    // loads the required password and username
    public void getCredentials() {
        this.password = AccountLogin.getPassword();// this will get the password that is stored
        this.username = AccountLogin.getUsername();// this will get the username that is stored
    }

    public void loadProfile(String username) {
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

    }

    // this method will verify if the the username and password given by the user
    // matches what was
    // found in the database
    public boolean isUsernameAndPassword(String username, String password) {
        getCredentials();
        if (!this.username.equals(username) || !this.password.equals(password)) {
            System.out.println("Incorrect username or password");
            return false;
        }
        loadProfile(username);
        return true;
    }
}
