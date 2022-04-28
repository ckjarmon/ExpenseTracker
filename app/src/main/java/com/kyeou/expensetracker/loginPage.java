package com.kyeou.expensetracker;

import androidx.annotation.RequiresPermission;
import androidx.appcompat.app.AppCompatActivity;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.EditText;

import java.io.IOException;
import java.io.OutputStream;



import androidx.annotation.NonNull;
import androidx.annotation.Nullable;

import android.widget.TextView;

import com.google.android.gms.auth.api.signin.GoogleSignIn;
import com.google.android.gms.auth.api.signin.GoogleSignInAccount;
import com.google.android.gms.auth.api.signin.GoogleSignInClient;
import com.google.android.gms.auth.api.signin.GoogleSignInOptions;
import com.google.android.gms.auth.api.signin.GoogleSignInStatusCodes;
import com.google.android.gms.common.Scopes;
import com.google.android.gms.common.SignInButton;
import com.google.android.gms.common.api.ApiException;
import com.google.android.gms.common.api.Scope;
import com.google.android.gms.tasks.OnCompleteListener;
import com.google.android.gms.tasks.Task;

public class loginPage extends AppCompatActivity implements
        View.OnClickListener {

    private static final int RC_SIGN_IN = 9001;
    private GoogleSignInClient mGoogleSignInClient;

    static {
        System.loadLibrary("expensetracker");
    }

    String username, password;

    EditText usernameInput, passwordInput;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_login_page);

        GoogleSignInOptions gso = new GoogleSignInOptions.Builder(GoogleSignInOptions.DEFAULT_SIGN_IN)
                .requestScopes(new Scope(Scopes.DRIVE_APPFOLDER))
                .requestEmail()
                .build();

        mGoogleSignInClient = GoogleSignIn.getClient(this, gso);

        findViewById(R.id.googleButton).setOnClickListener(this);
    }

    private void signIn() {
        Intent signInIntent = mGoogleSignInClient.getSignInIntent();
        startActivityForResult(signInIntent, RC_SIGN_IN);
    }

    @Override
    public void onClick(View v) {
        switch (v.getId()) {
            case R.id.googleButton:
                signIn();
                break;
            case R.id.signOutButton:
                //signOut();
                Intent intent = new Intent(this, loginPage.class);
                startActivity(intent);
                break;
            /*case R.id.disconnect_button:
                revokeAccess();
                break;*/
        }
    }

    @Override
    public void onStart() {
        super.onStart();

        GoogleSignInAccount account = GoogleSignIn.getLastSignedInAccount(this);
        if (account != null && GoogleSignIn.hasPermissions(account, new Scope(Scopes.DRIVE_APPFOLDER))) {
            //updateUI(account);
            Intent intent = new Intent(this, MainActivity.class);
            startActivity(intent);
        } else {
            /*updateUI(null);*/

        }
    }

    public void logIn(View view) throws IOException {
        // when all is said and done the parameter should be what is read from the
        // stream of user.json, if its blank
        // it should just return ""
        /*
         * File path = getFilesDir();
         * File file = new File(path, "transactionsJSON.json");
         * file.createNewFile();
         * FileOutputStream stream = new FileOutputStream(file);
         * try {
         * stream.write(message.getBytes());
         * } finally {
         * stream.close();
         * }
         */
        /*
         * File path = getFilesDir();
         * File file = new File(path, "transactions.json");
         * file.createNewFile();
         * 
         * path = getFilesDir();
         * file = new File(path, "user.json");
         * file.createNewFile();
         * 
         */

        usernameInput = findViewById(R.id.usernameInput3);
        passwordInput = findViewById(R.id.passwordInput);

        username = usernameInput.getText().toString();
        password = passwordInput.getText().toString();

        Intent intent = new Intent(this, MainActivity.class);
        startActivity(intent);

    }

    public void signUp(View view) throws IOException {
        Intent intent = new Intent(this, SignupPage.class);
        startActivity(intent);
    }

}