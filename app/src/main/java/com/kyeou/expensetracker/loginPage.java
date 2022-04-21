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
import java.io.OutputStream;

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
/*
        File path = getFilesDir();
        File file = new File(path, "transactionsJSON.json");
        file.createNewFile();
        FileOutputStream stream = new FileOutputStream(file);
        try {
            stream.write(message.getBytes());
        } finally {
            stream.close();
        } */
/*
        File path = getFilesDir();
        File file = new File(path, "transactions.json");
        file.createNewFile();

        path = getFilesDir();
         file = new File(path, "user.json");
        file.createNewFile();
*/
        OutputStream os = openFileOutput("user.json", MODE_PRIVATE);
        OutputStream od = openFileOutput("transactions.json", MODE_PRIVATE);


        new WriteReadHandle().WriteHandle("user.json", userLOGIN(new WriteReadHandle().ReadHandle("user.json"), new WriteReadHandle().ReadHandle("transactions.json")));
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



    public native String userLOGIN(String USER_INFO_JSON, String TRANS_INFO_JSON);
}