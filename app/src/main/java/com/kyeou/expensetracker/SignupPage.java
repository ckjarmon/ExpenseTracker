package com.kyeou.expensetracker;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.EditText;
import android.widget.TextView;

import java.io.IOException;
import java.io.OutputStream;

public class SignupPage extends AppCompatActivity {

    String name, username, password;
    float budget;
    EditText nameInput, usernameInput, budgetInput, passwordInput;
    TextView errorText;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_signup_page);
    }

    public void gatherInput(View view) throws IOException{
        nameInput = findViewById(R.id.fullNameInput);
        usernameInput = findViewById(R.id.usernameInput);
        passwordInput = findViewById(R.id.passwordSignupInput);
        budgetInput = findViewById(R.id.budgetInput);
        errorText = findViewById(R.id.errorText);

        name = nameInput.getText().toString();
        username = usernameInput.getText().toString();
        password = passwordInput.getText().toString();
        budget = Float.parseFloat(budgetInput.getText().toString());

        //MICHEAL: Write some code reject budget if the number input < 0;
        if(budget <= 0){
            errorText.setText("Budget Must Be Greater Than Zero");
        }else{
            OutputStream os = openFileOutput("user.json", MODE_PRIVATE);
            OutputStream od = openFileOutput("transactions.json", MODE_PRIVATE);
            os.close(); od.close();

            new WriteReadHandle().WriteHandle("transactions.json", "[]");
            new WriteReadHandle().WriteHandle("user.json", userSignUp(new WriteReadHandle().ReadHandle("user.json"), new WriteReadHandle().ReadHandle("transactions.json")));
            addBudget(budget);
            setName(name);
            setUsername(username);
            setPassword(password);
            new WriteReadHandle().WriteHandle("user.json", getUSERSJSON());
            //new WriteReadHandle().WriteHandle("transactions.json", "[]");
            Intent intent = new Intent(this, MainActivity.class);
            startActivity(intent);
        }


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