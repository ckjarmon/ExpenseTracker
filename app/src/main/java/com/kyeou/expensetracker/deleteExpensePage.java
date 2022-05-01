package com.kyeou.expensetracker;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.EditText;

import java.io.IOException;

public class deleteExpensePage extends AppCompatActivity {
    int id;
    EditText idInput;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_delete_expense_page);
    }

    public void gatherInput(View View) throws IOException{
        idInput = findViewById(R.id.idNumInput);
        id = Integer.parseInt(idInput.getText().toString());

        Log.d("Test", idInput.getText().toString());
        deleteTrans(id);
        Intent intent = new Intent(this, MainActivity.class);
        startActivity(intent);
    }
    public native void deleteTrans(int i);
}