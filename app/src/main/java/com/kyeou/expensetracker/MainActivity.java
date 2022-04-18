package com.kyeou.expensetracker;

import androidx.appcompat.app.AppCompatActivity;
import com.kyeou.expensetracker.databinding.ActivityMainBinding;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;






public class MainActivity extends AppCompatActivity {
    public static final String EXTRA_MESSAGE = "com.kyeou.expensetracker.MESSAGE";

    // Used to load the 'expensetracker' library on application startup.

        static {System.loadLibrary("expensetracker");}


    //private ActivityMainBinding binding;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }




    public void sendMessage(View view) {
        Intent intent = new Intent(this, DisplayMessageActivity.class);
        EditText editText = (EditText) findViewById(R.id.editTextTextPersonName);
        //String message = editText.getText().toString();
        String message = jniUSER();
        intent.putExtra(EXTRA_MESSAGE, message);
        startActivity(intent);
    }


    /**
     * A native method that is implemented by the 'expensetracker' native library,
     * which is packaged with this application.
     */
    public native String jniUSER();
    //public native String stringFromJNI2();
}