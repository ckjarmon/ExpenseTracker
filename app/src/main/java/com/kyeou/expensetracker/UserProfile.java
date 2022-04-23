package com.kyeou.expensetracker;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;

import java.io.IOException;

public class UserProfile extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_user_profile);
    }

    public void exitPage(View view) throws IOException {
        Intent intent = new Intent(this, MainActivity.class);
        startActivity(intent);
    }

    public void reports(View view) throws IOException {
        Intent intent = new Intent(this, Reports.class);
        startActivity(intent);
    }

    public void personalInformation(View view) throws IOException {
        Intent intent = new Intent(this, PersonalInformation.class);
        startActivity(intent);
    }

    public void signOut(View view) throws IOException {
        Intent intent = new Intent(this, loginPage.class);
        startActivity(intent);
    }
}