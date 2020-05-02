package com.example.firsttask

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.Toast;

class MainActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        Toast.makeText(getApplicationContext(), "Create", Toast.LENGTH_SHORT).show()
    }
    override fun onStart() {
        super.onStart()
        Toast.makeText(getApplicationContext(), "Start", Toast.LENGTH_SHORT).show()
    }

    override fun onResume() {
        super.onResume()
        Toast.makeText(getApplicationContext(), "Resume", Toast.LENGTH_SHORT).show()
    }

    override fun onPause() {
        super.onPause()
        Toast.makeText(getApplicationContext(), "Pause", Toast.LENGTH_SHORT).show()
    }

    override fun onStop() {
        super.onStop()
        Toast.makeText(getApplicationContext(), "Stop", Toast.LENGTH_SHORT).show()
    }
    override fun onDestroy(){
        Toast.makeText(getApplicationContext(), "Destroy", Toast.LENGTH_SHORT).show()
        super.onDestroy()
    }
}
