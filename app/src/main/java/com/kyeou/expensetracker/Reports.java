package com.kyeou.expensetracker;

import androidx.appcompat.app.AppCompatActivity;
import androidx.core.util.Pair;

import android.app.DatePickerDialog;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.DatePicker;
import android.widget.EditText;
import android.widget.Spinner;
import android.widget.TextView;

import com.google.android.material.datepicker.MaterialDatePicker;
import com.google.android.material.datepicker.MaterialPickerOnPositiveButtonClickListener;

import java.io.IOException;
import java.util.Calendar;

public class Reports extends AppCompatActivity {

    Spinner monthSelection, yearSelection;
    String month, year;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_reports);

        monthSelection = (Spinner) findViewById(R.id.monthSelection);
        yearSelection = (Spinner) findViewById(R.id.yearSelection);

        ArrayAdapter<String> monthsItems = new ArrayAdapter<String>(Reports.this,
                android.R.layout.simple_list_item_1, getResources().getStringArray(R.array.months));
        monthsItems.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
        monthSelection.setAdapter(monthsItems);

        ArrayAdapter<String> yearItems = new ArrayAdapter<String>(Reports.this,
                android.R.layout.simple_list_item_1, getResources().getStringArray(R.array.years));
        monthsItems.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
        yearSelection.setAdapter(yearItems);
    }

    public void gatherInput(View view) throws IOException{

        month = monthSelection.getSelectedItem().toString();
        year = yearSelection.getSelectedItem().toString();


        genReport(Integer.parseInt(month), Integer.parseInt(year));
        Log.d("test", month);
        Log.d("test", year);
    }



    public void exitPage(View view) throws IOException {
        Intent intent = new Intent(this, UserProfile.class);
        startActivity(intent);
    }

public native String genReport(int m, int y);
}