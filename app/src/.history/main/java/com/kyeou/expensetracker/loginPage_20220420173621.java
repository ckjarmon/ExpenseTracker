package com.kyeou.expensetracker;

import androidx.annotation.RequiresPermission;
import androidx.appcompat.app.AppCompatActivity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;

import java.io.File;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class loginPage extends AppCompatActivity {
    static {
        System.loadLibrary("expensetracker");
    }

    String email, password;

    EditText emailInput, passwordInput;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_login_page);
    }

    public void logIn(View view) throws IOException {
        // when all is said and done the parameter should be what is read from the
        // stream of user.json, if its blank
        // it should just return ""
        
        // File path = getFilesDir();
        WriteHandle("user.json", userLOGIN(enw WriteHandle(filename, ttw); ReadHandle("user.json"), TRANS_INFO_JSON));
        Intent intent = new Intent(this, MainActivity.class);
        startActivity(intent);

    }

    public void signUp(View view) throws IOException {
        Intent intent = new Intent(this, NewUserFunds.class);
        startActivity(intent);
    }

    public void gatherInput(View view) throws IOException {
        emailInput = findViewById(R.id.emailInput);
        passwordInput = findViewById(R.id.passwordInput);

        email = emailInput.getText().toString();
        password = passwordInput.getText().toString();
    }

    public void WriteHandle(String filename, String ttw) throws IOException {

        File path = getFilesDir();
        File file = new File(path, filename);
        file.createNewFile();
        FileOutputStream stream = new FileOutputStream(file);

        FileWriter out = new FileWriter(file);

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
        // file.createNewFile();
        FileReader in = new FileReader(file);
        String ret = "";

        try {

            int content;
            while ((content = in.read()) != -1) {
                // System.out.print((char) content);
                ret += (char) content;
            }
        } finally {
            if (in != null) {
                in.close();
            }
        }
        return ret;
    }

    public native String userLOGIN(String USER_INFO_JSON, String TRANS_INFO_JSON);
}