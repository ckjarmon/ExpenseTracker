package com.kyeou.expensetracker;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;

public class AddExpense extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_add_expense);
    }



//get data that user types and write it to a file
    public void gatherFieldTest(View view)  throws IOException {
        String message  = "WRITE TEST!!!!!"; //whatever user types
        File path = getFilesDir();
        File file = new File(path, "transactionsJSON.json");
        file.createNewFile();
        FileOutputStream stream = new FileOutputStream(file);
        try {
            stream.write(message.getBytes());
        } finally {
            stream.close();
        }
    }

}