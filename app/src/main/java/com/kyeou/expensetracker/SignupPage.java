package com.kyeou.expensetracker;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.EditText;

import java.io.IOException;

public class SignupPage extends AppCompatActivity {

    String name, username;
    double budget;
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
        budget = Double.parseDouble(budgetInput.getText().toString());

        Intent intent = new Intent(this, MainActivity.class);
        startActivity(intent);
    }

    public void exitPage(View view) throws IOException{
        Intent intent = new Intent(this, loginPage.class);
        startActivity(intent);
    }
}