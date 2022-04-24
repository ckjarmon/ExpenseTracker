package com.kyeou.expensetracker;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;

import java.io.IOException;

//import com.kyeou.expensetracker.databinding.ActivityMainBinding;

public class MainActivity extends AppCompatActivity {
    public static final String EXTRA_MESSAGE = "com.kyeou.expensetracker.MESSAGE";

    // Used to load the 'expensetracker' library on application startup.

    TextView userText, balanceText, budgetText, scoreText;

    static {
        System.loadLibrary("expensetracker");
    }

    // private ActivityMainBinding binding;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        try {
            new WriteReadHandle().WriteHandle("user.json", userLogIn(new WriteReadHandle().ReadHandle("user.json"), new WriteReadHandle().ReadHandle("transactions.json")));
        } catch (IOException e) {
            e.printStackTrace();
        }

        userText = findViewById(R.id.user);
        balanceText = findViewById(R.id.balance);
        budgetText = findViewById(R.id.budget);
        scoreText = findViewById(R.id.score);

        String user_name = getUSERINFO("Name");
        String balance = getUSERINFO("Balance");
        String budget = getUSERINFO("Budget");
        String score = getUSERINFO("Score");

        userText.setText("Hi " + user_name.substring(1, user_name.length()-1) + ",");
        balanceText.setText("Balance: " + balance);
        budgetText.setText("Budget: " + budget);
        scoreText.setText("Score: " + score);

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
    public native String userLogIn(String USER_INFO_JSON, String TRANS_INFO_JSON);
    // public native String stringFromJNI2();
}