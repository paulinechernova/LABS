package com.example.thirdtask

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import kotlinx.android.synthetic.main.activity_photo.*

class PhotoActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_photo)
    }

    override fun onResume() {
        super.onResume()
        nameTextView.setText(intent.getStringExtra("name"))
        photoView.setImageURI(intent.getParcelableExtra("photo"))
    }

    override fun onStart() {
        super.onStart()
        nameTextView.setText(intent.getStringExtra("name"))
        photoView.setImageURI(intent.getParcelableExtra("photo"))
    }

}
