package com.kyeou.expensetracker;

import android.app.DatePickerDialog;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.DatePicker;
import android.widget.EditText;
import android.widget.ImageButton;
import android.widget.TextView;
import android.widget.Button;

import androidx.appcompat.app.AppCompatActivity;

import java.io.File;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.util.Calendar;

public class AddExpense extends AppCompatActivity implements DatePickerDialog.OnDateSetListener {

    // This is for the Calendar
    private TextView datetext;

    // These are for input fields to add expense
    String description, amount;
    EditText descriptionInput;
    EditText amountInput;
    Button addButton;

    int month, day, year;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_add_expense);

        // Calendar function
        datetext = findViewById(R.id.date_text);
        findViewById(R.id.show_dialog).setOnClickListener(new View.OnClickListener() {
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

    // get data that user types and write it to a file
    public void gatherFieldTest(View view) throws IOException {

        descriptionInput = findViewById(R.id.descriptionField);
        amountInput = findViewById(R.id.amountField);

        description = descriptionInput.getText().toString();
        amount = amountInput.getText().toString();
        String newline = "\r\n";

        // instad of writing all that data directly to the file, call the JNI addTrans
        // function to return the json string to then overrride what is in the json file
        File path = getFilesDir();
        File file = new File(path, "transactionsJSON.json");
        file.createNewFile();
        FileOutputStream stream = new FileOutputStream(file);
        try {
            /*
             * stream.write(description.getBytes());
             * stream.write(newline.getBytes());
             * stream.write(amount.getBytes());
             * stream.write(newline.getBytes());
             * stream.write(dateMessage.getBytes());
             * stream.write(newline.getBytes());
             * stream.write(paymentType.getBytes());
             */
            stream.write(    ( addTrans(   description, day, month, year, Float.valueOf(amount).floatValue(), ReadHandle("transactionsJSON.json")  )).getBytes()   );

            recordDebits(ReadHandle("user.json"), ReadHandle("transactionsJSON.json"));
            WriteHandle("user.json", getUSERSJSON());
            WriteHandle("transactionsJSON.json", getTRANSJSON());
        } finally {
            stream.close();
        }

        Intent intent = new Intent(this, MainActivity.class);
        startActivity(intent);
    }

    @Override
    public void onDateSet(DatePicker datePicker, int year, int month, int dayOfMonth) {
        this.day = dayOfMonth;
        this.year = year;
        this.month = month;

        String date = month + "/" + dayOfMonth + "/" + year;

        datetext.setText(date);
    }

    public void WriteHandle(String filename, String ttw) throws IOException {


        File path = getFilesDir();
        File file = new File(path, filename);
        file.createNewFile();
        FileOutputStream stream = new FileOutputStream(file);



        FileWriter out = new FileWriter(file);

        try {
            out.write(ttw);
        } finally {

            if (out != null) {
                out.close();
            }
        }

    }

    public String ReadHandle(String filename) throws IOException {
        File file = new File(filename);
        //file.createNewFile();
        FileReader in = new FileReader(file);
        String ret = "";

        try {

            int content;
            while ((content = in.read()) != -1) {
                //System.out.print((char) content);
                ret += (char)content;
            }
        } finally {
            if (in != null) {
                in.close();
            }
        }
        return ret;
    }


    public void exitPage(View view) throws IOException {
        Intent intent = new Intent(this, MainActivity.class);
        startActivity(intent);
    }

    public native String addTrans(String name, int day, int month, int year, float amount, String JSON);

    public native void recordDebits(String USER, String JSON);

    public native String getUSERSJSON();

    public native String getTRANSJSON();

}