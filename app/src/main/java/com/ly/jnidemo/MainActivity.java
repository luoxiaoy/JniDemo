package com.ly.jnidemo;

import android.os.Handler;
import android.os.Message;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.widget.TextView;

import com.bean.SkillFul;
import com.test.TestJni;
import java.util.List;

public class MainActivity extends AppCompatActivity {

    private TextView tvJavaObj;
    private TextView tvJavaListObj;

    private final int JNI_CALL_JAVA = 101;
    private Handler mHandler = new Handler(){
        @Override
        public void handleMessage(Message msg) {
            super.handleMessage(msg);
            switch (msg.what){
                case JNI_CALL_JAVA:
                    SkillFul skillFul = (SkillFul) msg.obj;
                    break;
            }
        }
    };

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        initView();
        initData();
    }

    private void initView() {
        tvJavaObj = (TextView) findViewById(R.id.tv_java_obj);
        tvJavaListObj = (TextView) findViewById(R.id.tv_java_list_obj);
    }

    private void initData() {
        //为修改时的初始化
        SkillFul skillFul = new SkillFul("测试前str",false,72);
        TestJni.ModifyObj(skillFul);
        tvJavaObj.setText("修改后的结果: " + skillFul.strSkill + "=== "+skillFul.booleanSkill + "=== " + skillFul.intSkill);

        int[] ints = new int[10];
        for (int i = 0;i < 10;i++){
            ints[i] = (int)(Math.random() * 100);
        }
        List<SkillFul> skillFulList = TestJni.getArrayObj(ints);
        String text = "";
        for (SkillFul skillFul1:skillFulList){
            text += skillFul1.intSkill + ",";
        }
        tvJavaListObj.setText(text);
    }

    /**
     * jni调用java方法
     * @param skillFul
     */
    public void setSkill(SkillFul skillFul){
        Log.e("test","======= setSkill :" + skillFul.strSkill + "   " + skillFul.intSkill);
    }
}
