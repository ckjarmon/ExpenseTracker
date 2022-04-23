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

    float budget;

    EditText budgetInput;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_new_user_funds);
    }

    public void gatherInput(View view) throws IOException {
        budgetInput = findViewById(R.id.initialBudgetText);
        budget = Float.parseFloat(budgetInput.getText().toString());
        addBudget(budget);
        new WriteReadHandle().WriteHandle("user.json", getUSERSJSON());


        Intent intent = new Intent(this, MainActivity.class);
        startActivity(intent);


    }

    public void exitPage(View view) throws IOException {
        Intent intent = new Intent(this, MainActivity.class);
        startActivity(intent);
    }

    public native void addBudget(float amount);

    public native String getUSERSJSON();
}