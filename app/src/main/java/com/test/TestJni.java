package com.test;

import android.util.Log;

import com.bean.SkillFul;

import java.util.ArrayList;

public class TestJni {
    static {
        System.loadLibrary("MyJniSo");
    }

    /**
     * jni修改java对象属性值，并回调java方法
     * @param skillFul
     */
    public static native void ModifyObj(SkillFul skillFul);

    /**
     * 将数组传递到jni并给java多个对象赋值，并返回对象列表
     * @param ints
     * @return
     */
    public static native ArrayList<SkillFul> getArrayObj(int[] ints);
}
