package com.kyeou.expensetracker;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.util.Log;
import android.widget.ArrayAdapter;
import android.widget.TextView;

import java.util.ArrayList;

public class ReportResult extends AppCompatActivity {
    static {
        System.loadLibrary("expensetracker");
    }
TextView rankText, userText, dateText, scoreText;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_report_result);


        rankText = findViewById(R.id.ranks);
        userText = findViewById(R.id.rname);
        dateText = findViewById(R.id.rdate);
        scoreText = findViewById(R.id.rscore);



        String user_name = getUSERINFO("Name");
        String report_date = getRankDate();
       // String rt = getRankList();

        userText.setText("Name: " + user_name.substring(1, user_name.length()-1));
        rankText.setText(getRankList());
        dateText.setText("Date: " + Reports.month + "/" + Reports.year);
        scoreText.setText(showBS());

     }




public native String getRankList();
public native String getRankDate();
public native String getUSERINFO(String stringCALL);
public native String showBS();
}
