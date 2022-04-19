package com.kyeou.expensetracker;

import androidx.appcompat.app.AppCompatActivity;

import android.app.DatePickerDialog;
import android.os.Bundle;
import android.view.View;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.Calendar;

import android.widget.DatePicker;
import android.widget.TextView;

public class AddExpense extends AppCompatActivity implements DatePickerDialog.OnDateSetListener{
    private TextView datetext;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_add_expense);
        datetext = findViewById(R.id.date_text);

        findViewById(R.id.show_dialog).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                showDatePickerDailog();
            }
        });
    }


    private void showDatePickerDailog(){
        DatePickerDialog datePickerDialog = new DatePickerDialog(
            this,
                this,
                Calendar.getInstance().get(Calendar.YEAR),
                Calendar.getInstance().get(Calendar.MONTH),
                Calendar.getInstance().get(Calendar.DAY_OF_MONTH)
        );
        datePickerDialog.show();
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

    @Override
    public void onDateSet(DatePicker datePicker, int year, int month, int dayOfMonth) {
        String date = month + "/" + dayOfMonth + "/" + year;
        datetext.setText(date);
    }
}