package com.example.intent2;




import android.os.Bundle;
import android.app.Activity;
import android.view.Menu;
import android.view.View;
import android.util.Log ; 
import android.view.KeyEvent;
import android.view.View.OnClickListener;
import android.content.Intent;
import android.widget.Button;
import android.widget.Toast;





public class MainActivity extends Activity {

	 String tag = "Events" ;
	 int request_Code = 1;

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		 Log.d(tag, "In the onCreate() event");
		   Button btn = (Button) findViewById(R.id.btn_OK) ;
		   btn.setOnClickListener(new OnClickListener() {

				@Override
				public void onClick(View arg0) {
					Intent i1 = new Intent(getApplicationContext(),
							MainActivity2.class);
					
					startActivity(i1);

				}
			});
		 
	}
		 public void onActivityResult(int requestCode, int resultCode, Intent data)
		    {
		        if (requestCode == request_Code) {
		            if (resultCode == RESULT_OK) {
		                Toast.makeText(this,data.getData().toString(),
		                    Toast.LENGTH_SHORT).show();
		            }
		        }
		    }

		 
		 

	

}
