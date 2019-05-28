package com.hxd.music;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

import com.hxd.player.Test;

public class MainActivity extends AppCompatActivity {



    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Test test = new Test();
        TextView tv = findViewById(R.id.sample_text);
        tv.setText(test.stringFromJNI());

        test.TestFFmpeg();
    }


}
