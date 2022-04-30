package com.kyeou.expensetracker;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.EditText;

import java.io.IOException;
import java.io.OutputStream;

public class SignupPage extends AppCompatActivity {

    String name, username;
    float budget;
    EditText nameInput, usernameInput, budgetInput;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_signup_page);
    }

    public void gatherInput(View view) throws IOException{
        nameInput = findViewById(R.id.fullNameInput);
        usernameInput = findViewById(R.id.usernameInput);
        budgetInput = findViewById(R.id.budgetInput);

        name = nameInput.getText().toString();
        username = usernameInput.getText().toString();
        budget = Float.parseFloat(budgetInput.getText().toString());


        OutputStream os = openFileOutput("user.json", MODE_PRIVATE);
        OutputStream od = openFileOutput("transactions.json", MODE_PRIVATE);
        os.close(); od.close();


        new WriteReadHandle().WriteHandle("user.json", userSignUp(new WriteReadHandle().ReadHandle("user.json"), new WriteReadHandle().ReadHandle("transactions.json")));
        addBudget(budget);
        setName(name);
        setUsername(username);
        setPassword("Micheal set this to the variable name of the password input lmao");
        new WriteReadHandle().WriteHandle("user.json", getUSERSJSON());
        new WriteReadHandle().WriteHandle("transactions.json", "[]");
        Intent intent = new Intent(this, MainActivity.class);
        startActivity(intent);




    }

    public void exitPage(View view) throws IOException{
        Intent intent = new Intent(this, loginPage.class);
        startActivity(intent);
    }

    public native String userSignUp(String USER_INFO_JSON, String TRANS_INFO_JSON);
    public native void addBudget(float amount);
    public native void setName(String name);
    public native void setUsername(String name);
    public native void setPassword(String pswd);
    public native String getUSERSJSON();

    public native String getTRANSJSON();
}