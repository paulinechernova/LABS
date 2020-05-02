package com.example.secondtask

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import com.google.android.material.snackbar.Snackbar
import kotlinx.android.synthetic.main.activity_main.*

class MainActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        multiply.setOnClickListener { v -> if (firstNum.text.isEmpty() || secondNum.text.isEmpty() )
            Snackbar.make(v, "Заполните все поля", Snackbar.LENGTH_LONG).show()
        else {
            result.text = (firstNum.text.toString().toDouble() * secondNum.text.toString().toDouble()).toString()
        }
        }
        divide.setOnClickListener { v -> if (firstNum.text.isEmpty() || secondNum.text.isEmpty() )
            Snackbar.make(v, "Заполните все поля", Snackbar.LENGTH_LONG).show()
        else {
            if ( secondNum.text.toString().toDouble() == 0.0  )
                Snackbar.make(v, "Деление на ноль запрещено", Snackbar.LENGTH_LONG).show()
            else result.text = (firstNum.text.toString().toDouble() / secondNum.text.toString().toDouble()).toString()
        }
        }
        minus.setOnClickListener { v -> if (firstNum.text.isEmpty() || secondNum.text.isEmpty() )
            Snackbar.make(v, "Заполните все поля", Snackbar.LENGTH_LONG).show()
        else {
            result.text = (firstNum.text.toString().toDouble() - secondNum.text.toString().toDouble()).toString()
        }
        }
        plus.setOnClickListener{ v -> if (firstNum.text.isEmpty() || secondNum.text.isEmpty() )
            Snackbar.make(v, "Заполните все поля", Snackbar.LENGTH_LONG).show()
        else {
            result.text = (firstNum.text.toString().toDouble() + secondNum.text.toString().toDouble()).toString()
        }
        }
    }
}
