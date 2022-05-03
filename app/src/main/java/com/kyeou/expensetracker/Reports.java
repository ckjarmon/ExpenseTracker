package com.kyeou.expensetracker;

import androidx.appcompat.app.AppCompatActivity;
import androidx.core.util.Pair;
import android.content.pm.PackageManager;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Canvas;
import android.graphics.Paint;
import android.graphics.Typeface;
import android.graphics.pdf.PdfDocument;
import android.os.Bundle;
import android.os.Environment;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;
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
import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.app.ActivityCompat;
import androidx.core.content.ContextCompat;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;

import static android.Manifest.permission.READ_EXTERNAL_STORAGE;
import static android.Manifest.permission.WRITE_EXTERNAL_STORAGE;

public class Reports extends AppCompatActivity {
    //variables
    Spinner monthSelection, yearSelection;
    static String month;
        static int year;



    // constant code for runtime permissions
    private static final int PERMISSION_REQUEST_CODE = 200;


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





    public void exitPage(View view) {
        Intent intent = new Intent(this, UserProfile.class);
        startActivity(intent);
    }

    public void resultsPage(View view) {
        month = monthSelection.getSelectedItem().toString();
        year = Integer.valueOf(yearSelection.getSelectedItem().toString()).intValue();
        //Float.valueOf(yearSelection.getSelectedItem().toString()).floatValue()
        genReport(getMonthInt(month), year);
        Intent intent = new Intent(this, ReportResult.class);
        startActivity(intent);
    }

    public int getMonthInt(String m) {
        switch (m) {
            case "January": return 1;
            case "February": return 2;
            case "March": return 3;
            case "April": return 4;
            case "May": return 5;
            case "June": return 6;
            case "July": return 7;
            case "August": return 8;
            case "September": return 9;
            case "October": return 10;
            case "November": return 11;
            case "December": return 12;


        }
        return 0;
    }

    public native void genReport(int m, int y);

    
}