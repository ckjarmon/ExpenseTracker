package com.kyeou.expensetracker;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;

import androidx.appcompat.app.AppCompatActivity;

import java.io.IOException;

//import com.kyeou.expensetracker.databinding.ActivityMainBinding;

public class MainActivity extends AppCompatActivity {
    public static final String EXTRA_MESSAGE = "com.kyeou.expensetracker.MESSAGE";

    // Used to load the 'expensetracker' library on application startup.

    static {
        System.loadLibrary("expensetracker");
    }

    // private ActivityMainBinding binding;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);





         String user_name = getUSERINFO("Name");
       String balance = getUSERINFO("Balance");
        String budget = getUSERINFO("Budget");
        String score = getUSERINFO("Score");

        // Button btn = findViewById(R.id.addExpense);
        // btn.setOnClickListener(new View.OnClickListener(){
        // @Override
        // public void onClick(View v){
        // setContentView(R.layout.activity_add_expense);
        // }
        // });
    }

    // for example add_expense_function

    public void addBExpense(View view) {
        Intent intent = new Intent(this, AddExpense.class);
        startActivity(intent);
    }

    public void hamburgerMenu(View view) {
        Intent intent = new Intent(this, UserProfile.class);
        startActivity(intent);
    }

    public void editFunds(View view) {
        Intent intent = new Intent(this, NewUserFunds.class);
        startActivity(intent);
    }


    /**
     * A native method that is implemented by the 'expensetracker' native library,
     * which is packaged with this application.
     */
     public native String getUSERINFO(String stringCALL);

    // public native String stringFromJNI2();
}