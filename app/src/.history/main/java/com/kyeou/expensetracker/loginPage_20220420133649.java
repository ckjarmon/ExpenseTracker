package com.kyeou.expensetracker;

import androidx.appcompat.app.AppCompatActivity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;

public class loginPage extends AppCompatActivity {
    String email, password;

    EditText emailInput, passwordInput;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_login_page);
    }

    public void logIn(View view) throws IOException {

        Intent intent = new Intent(this, MainActivity.class);
        startActivity(intent);
//when all is said and done the parameter should be what is read from the stream of user.json, if its blank
        //it should just return ""
String s = userManage("");
        File path = getFilesDir();
      File file = new File(path, "user.json");
        FileOutputStream stream = new FileOutputStream(file);
       try {
            stream.write(s.getBytes());
      } finally {
            stream.close();
        }
    }

    public void signUp(View view) throws IOException {
        Intent intent = new Intent(this, NewUserFunds.class);
        startActivity(intent);
    }

    public void gatherInput(View view) throws IOException{
        emailInput = findViewById(R.id.emailInput);
        passwordInput = findViewById(R.id.passwordInput);

        email = emailInput.getText().toString();
        password = passwordInput.getText().toString();
    }


    public native String userManage(String USER);
}