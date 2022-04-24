package com.kyeou.expensetracker;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.EditText;

import java.io.IOException;

public class PersonalInformation extends AppCompatActivity {

    String name, username;
    EditText nameInput, usernameInput;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_personal_information);
    }

    public void gatherInput(View view) throws IOException {
        nameInput = findViewById(R.id.nameInput);
        usernameInput = findViewById(R.id.userInput);

        name = nameInput.getText().toString();
        username = usernameInput.getText().toString();

        setName(username);
        new WriteReadHandle().WriteHandle("user.json", getUSERSJSON());
        Intent intent = new Intent(this, UserProfile.class);
        startActivity(intent);
    }

    public void exitPage(View view) throws IOException {
        Intent intent = new Intent(this, MainActivity.class);
        startActivity(intent);
    }

    public native void setName(String name);
    public native String getUSERSJSON();

}