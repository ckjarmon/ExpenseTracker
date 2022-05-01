package com.kyeou.expensetracker;

import androidx.annotation.RequiresPermission;
import androidx.appcompat.app.AppCompatActivity;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.EditText;

import java.io.IOException;
import java.io.OutputStream;

public class loginPage extends AppCompatActivity {

    static {
        System.loadLibrary("expensetracker");
    }

    String username, password;

    EditText usernameInput, passwordInput;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_login_page);
    }

    public void logIn(View view) throws IOException {


        usernameInput = findViewById(R.id.usernameInput3);
        passwordInput = findViewById(R.id.passwordInput);

        username = usernameInput.getText().toString();
        password = passwordInput.getText().toString();



if (checkPassword(password) && checkUsername(username)) {
    Intent intent = new Intent(this, MainActivity.class);
    startActivity(intent);
}//end if
        else {
            //Micheal: create pop telling user shit is wrong
        }
    }

    public void signUp(View view) throws IOException {
        Intent intent = new Intent(this, SignupPage.class);
        startActivity(intent);
    }


public native boolean checkPassword(String pass);
    public native boolean checkUsername(String pass);


}