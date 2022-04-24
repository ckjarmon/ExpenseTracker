package com.kyeou.expensetracker;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.EditText;

import java.io.IOException;

public class NewUserFunds extends AppCompatActivity {

    double balance, budget;
    String cardNumber;

    EditText balanceInput, budgetInput, cardNumberInput;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_new_user_funds);
    }

    public void gatherInput(View view) throws IOException {
        balanceInput = findViewById(R.id.initialBalanceText);
        budgetInput = findViewById(R.id.initialBudgetText);
        cardNumberInput = findViewById(R.id.creditCardNumberText);

        balance = Double.parseDouble(balanceInput.getText().toString());
        budget = Double.parseDouble(budgetInput.getText().toString());
        cardNumber = cardNumberInput.getText().toString();

        Intent intent = new Intent(this, MainActivity.class);
        startActivity(intent);
    }

    public void exitPage(View view) throws IOException {
        Intent intent = new Intent(this, MainActivity.class);
        startActivity(intent);
    }
}