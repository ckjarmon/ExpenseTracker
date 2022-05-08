package com.kyeou.expensetracker;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.util.Pair;

import android.app.ProgressDialog;
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

import com.google.android.gms.auth.api.signin.GoogleSignIn;
import com.google.android.gms.auth.api.signin.GoogleSignInAccount;
import com.google.android.gms.auth.api.signin.GoogleSignInClient;
import com.google.android.gms.auth.api.signin.GoogleSignInOptions;
import com.google.android.gms.common.api.Scope;
import com.google.android.gms.tasks.OnFailureListener;
import com.google.android.gms.tasks.OnSuccessListener;
import com.google.android.material.datepicker.MaterialDatePicker;
import com.google.android.material.datepicker.MaterialPickerOnPositiveButtonClickListener;
import com.google.api.client.extensions.android.http.AndroidHttp;
import com.google.api.client.googleapis.extensions.android.gms.auth.GoogleAccountCredential;
import com.google.api.client.json.gson.GsonFactory;
import com.google.api.services.drive.Drive;
import com.google.api.services.drive.DriveScopes;

import java.io.IOException;
import java.util.Calendar;
import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.app.ActivityCompat;
import androidx.core.content.ContextCompat;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.Collections;

import static android.Manifest.permission.READ_EXTERNAL_STORAGE;
import static android.Manifest.permission.WRITE_EXTERNAL_STORAGE;

public class Reports extends AppCompatActivity implements View.OnClickListener{
    //variables
    Spinner monthSelection, yearSelection;
    static String month;
    static int year;

    DriveServiceHelper driveServiceHelper;
    GoogleSignInClient client;
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

        GoogleSignInOptions signInOptions = new GoogleSignInOptions.Builder(GoogleSignInOptions.DEFAULT_SIGN_IN)
                .requestScopes(new Scope(DriveScopes.DRIVE_FILE))
                .requestEmail()
                .build();

        client = GoogleSignIn.getClient(this,signInOptions);
        findViewById(R.id.backupToDriveButton).setOnClickListener(this);

        //noinspection deprecation
        //startActivityForResult(client.getSignInIntent(),400);

    }

    @Override
    public void onClick(View v){
        switch (v.getId()){
            case R.id.backupToDriveButton:
                signIn();
                break;
        }
    }

    private void signIn(){
        Intent signInIntent = client.getSignInIntent();
        startActivityForResult(signInIntent,9001);
    }
    
/*
    private void requestSignIn() {
        GoogleSignInOptions signInOptions = new GoogleSignInOptions.Builder(GoogleSignInOptions.DEFAULT_SIGN_IN)
                .requestScopes(new Scope(DriveScopes.DRIVE_FILE))
                .requestEmail()
                .build();

        GoogleSignInClient client = GoogleSignIn.getClient(this,signInOptions);
        findViewById(R.id.backupToDriveButton).setOnClickListener(this);

        //noinspection deprecation
        startActivityForResult(client.getSignInIntent(),400);
    }//requestSignIn */

    @Override
    protected void onActivityResult(int requestCode, int resultCode, @Nullable Intent data){
        super.onActivityResult(requestCode, resultCode, data);

        switch (requestCode){
            case 400:
                if(resultCode == RESULT_OK){
                    handleSignInIntent(data);
                }
                break;
        }
    }//onActivityResult

    private void handleSignInIntent(Intent data) {
        GoogleSignIn.getSignedInAccountFromIntent(data)
                .addOnSuccessListener(new OnSuccessListener<GoogleSignInAccount>() {
                    @Override
                    public void onSuccess(GoogleSignInAccount googleSignInAccount) {
                        GoogleAccountCredential credential = GoogleAccountCredential.usingOAuth2(Reports.this, Collections.singleton(DriveScopes.DRIVE_FILE));

                        credential.setSelectedAccount(googleSignInAccount.getAccount());

                        Drive googleDriveService = new Drive.Builder(
                                AndroidHttp.newCompatibleTransport(),
                                new GsonFactory(),
                                credential)
                                .setApplicationName("Expense Tracker")
                                .build();

                        driveServiceHelper = new DriveServiceHelper(googleDriveService);
                    }
                })
                .addOnFailureListener(new OnFailureListener() {
                    @Override
                    public void onFailure(@NonNull Exception e) {

                    }
                });
    }//handleSignInIntent

    public void uploadPdfFile(View v){
        ProgressDialog progressDialog = new ProgressDialog(Reports.this);
        progressDialog.setTitle("Uploading to Google Drive");
        progressDialog.setMessage("Please wait...");
        progressDialog.show();

        String filePath = "/data/data/com.kyeou.expensetracker/files/";
        driveServiceHelper.createFilePDF(filePath).addOnSuccessListener(new OnSuccessListener<String>() {
            @Override
            public void onSuccess(String s) {
                progressDialog.dismiss();

                Toast.makeText(getApplicationContext(),"Uploaded successfully", Toast.LENGTH_LONG).show();
            }
        })
                .addOnFailureListener(new OnFailureListener() {
                    @Override
                    public void onFailure(@NonNull Exception e) {
                        progressDialog.dismiss();
                        Toast.makeText(getApplicationContext(),"Check your google drive api key",Toast.LENGTH_LONG).show();
                    }
                });

    }//UploadPdfFile


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