package com.kyeou.expensetracker;

import androidx.appcompat.app.AppCompatActivity;
import androidx.core.util.Pair;

import android.app.DatePickerDialog;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.DatePicker;
import android.widget.EditText;
import android.widget.TextView;

import com.google.android.material.datepicker.MaterialDatePicker;
import com.google.android.material.datepicker.MaterialPickerOnPositiveButtonClickListener;

import java.io.IOException;
import java.util.Calendar;

public class Reports extends AppCompatActivity implements DatePickerDialog.OnDateSetListener {

    TextView startDateText, endDateText;
    Button startDateButton, endDateButton;
    int counter = 0;

    int[][] dates = new int[2][3];

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_reports);

        startDateText = findViewById(R.id.startDateText);
        findViewById(R.id.startDateButton).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                showDatePickerDialog();
            }
        });

        endDateText = findViewById(R.id.endDateText);
        findViewById(R.id.endDateButton).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                showDatePickerDialog();
            }
        });

    }

    public void showDatePickerDialog() {
        DatePickerDialog datePickerDialog = new DatePickerDialog(
                this,
                this,
                Calendar.getInstance().get(Calendar.YEAR),
                Calendar.getInstance().get(Calendar.MONTH),
                Calendar.getInstance().get(Calendar.DAY_OF_MONTH));
        datePickerDialog.show();
    }

    public void exitPage(View view) throws IOException {
        Intent intent = new Intent(this, UserProfile.class);
        startActivity(intent);
    }

    @Override
    public void onDateSet(DatePicker datePicker, int year, int month, int dayOfMonth) {
        if (counter % 2 == 0) {
            dates[0][0] = month;
            dates[0][1] = dayOfMonth;
            dates[0][2] = year;
            String date = month + "/" + dayOfMonth + "/" + year;
            startDateText.setText(date);
            counter++;
            return;
        } else if (counter % 2 == 1) {
            dates[1][0] = month;
            dates[1][1] = dayOfMonth;
            dates[1][2] = year;
            counter++;
            String date = month + "/" + dayOfMonth + "/" + year;
            endDateText.setText(date);
            return;
        }
    }
    public native void genReport( int month1, int year1, int month2, int year2);
}