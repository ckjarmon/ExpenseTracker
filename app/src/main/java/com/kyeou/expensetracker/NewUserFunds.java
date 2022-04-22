package com.kyeou.expensetracker;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.EditText;
import android.widget.TextView;

import java.io.IOException;

public class NewUserFunds extends AppCompatActivity {

    double budget;

    EditText budgetInput;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_new_user_funds);
    }

    public void gatherInput(View view) throws IOException {
        budgetInput = findViewById(R.id.initialBudgetText);
        budget = Double.parseDouble(budgetInput.getText().toString());



        Intent intent = new Intent(this, MainActivity.class);
        startActivity(intent);


    }

    public void exitPage(View view) throws IOException {
        Intent intent = new Intent(this, MainActivity.class);
        startActivity(intent);
    }
}