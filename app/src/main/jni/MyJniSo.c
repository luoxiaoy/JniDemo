#include <jni.h>
#include <stdio.h>
#include "log.h"

JNIEXPORT void JNICALL
Java_com_test_TestJni_ModifyObj(JNIEnv *env, jclass type, jobject skillFul) {
    //访问java对象的类
    jclass job = (*env)->GetObjectClass(env,skillFul);
    if(job == NULL){
        LOGE("=========== jni %s","对象为空");
        return;
    }
    //获得得SkillFul类的属性id
    jfieldID strFieldId = (*env)->GetFieldID(env,job,"strSkill","Ljava/lang/String;");
    jfieldID intFieldid = (*env)->GetFieldID(env,job,"intSkill","I");
    jfieldID boolFiedid = (*env)->GetFieldID(env,job,"booleanSkill","Z");
    //获得属性值
    jstring strSkill = (*env)->GetObjectField(env,skillFul,strFieldId);
    jint intSkill = (*env)->GetIntField(env,skillFul,intFieldid);
    jboolean boolSkill = (*env)->GetBooleanField(env,skillFul,boolFiedid);
    //输出jstring需要先转换为char *类型
    const char * charSkill = (*env)->GetStringUTFChars(env,strSkill,0);
    LOGE("==== 修改前的值:%s == %d ==  %d",charSkill,intSkill,boolSkill);
    //修改属性值
    (*env)->SetIntField(env,skillFul,intFieldid,250);
    //这里个Java对象的String属性赋值，需要先将本地的string类型转换为UTF-8格式的String对象NewStringUTF
    (*env)->SetObjectField(env,skillFul,strFieldId,(*env)->NewStringUTF(env,"修改后的str"));
    (*env)->SetBooleanField(env,skillFul,boolFiedid,1);

    // java 反射
    //1 . 找到java代码的 class文件，,注意这里需要包名
    jclass MainActivity = (*env)->FindClass(env,"com/ly/jnidemo/MainActivity");
    if (MainActivity == 0){
        LOGE("====find class MainActivity error");
        return;
    }
    LOGE("=====find class ");
    //2 寻找class里面的方法
    jmethodID jmethodObj = (*env)->GetMethodID(env,MainActivity,"setSkill","(Lcom/bean/SkillFul;)V");
    if (jmethodObj == 0){
        LOGE("=====find method setSkill error");
        return;
    }
    LOGE("=====find method ");
    //  默认构造函数，不传参数
    jmethodID construction_id = (*env)->GetMethodID(env,MainActivity,"<init>", "()V");
    // 3 通过NewObject来创建对象
    jobject mainActiviyObj = (*env)->NewObject(env,MainActivity,construction_id);
    //回调Java方法
    (*env)->CallVoidMethod(env,mainActiviyObj,jmethodObj,skillFul);

    //用完之后释放指向UTF-8格式的char*的指针
    (*env)->ReleaseStringUTFChars(env,strSkill,charSkill);
}


JNIEXPORT jobject JNICALL
Java_com_test_TestJni_getArrayObj(JNIEnv *env, jclass type, jintArray ints_) {
    //获取数组的长度
    int length = (*env)->GetArrayLength(env,ints_);

    jint *ints = (*env)->GetIntArrayElements(env, ints_, NULL);
    //JNI返回arraylist类型
    jclass arrayList_cla = (*env)->FindClass(env,"java/util/ArrayList");
    //获取默认初始化的构造方法id
    jmethodID construct = (*env)->GetMethodID(env,arrayList_cla,"<init>","()V");
    jobject arrayList_obj = (*env)->NewObject(env,arrayList_cla,construct,"");
    //获得arraylist的add()方法
    jmethodID arrayList_add = (*env)->GetMethodID(env,arrayList_cla,"add","(Ljava/lang/Object;)Z");
    //找到java代码的 class文件,注意这里需要包名
    jclass SkillFul = (*env)->FindClass(env,"com/bean/SkillFul");
    if (SkillFul == 0){
        LOGE("====find class MainActivity error");
    } else{
        LOGE("=====find class ");
    }
    //  默认构造函数，不传参数
    jmethodID construct_Skillful = (*env)->GetMethodID(env,SkillFul,"<init>","()V");
    if (construct_Skillful == 0){
        LOGE("====find method MainActivity error");
    } else{
        LOGE("=====find method ");
    }
    int i = 0;
    //这里注意for循环会报这个错误,需要将i的初始化移出来
    //Error:(74, 5) error: 'for' loop initial declarations are only allowed in C99 or C11 mode
    for(; i < length; i++) {
        //通过NewObject来创建对象
        jobject obj_Skillful = (*env)->NewObject(env,SkillFul,construct_Skillful);
        jfieldID intFieldid = (*env)->GetFieldID(env,SkillFul,"intSkill","I");
        //赋值
        (*env)->SetIntField(env,obj_Skillful,intFieldid,ints[i]);
        (*env)->CallBooleanMethod(env,arrayList_obj,arrayList_add,obj_Skillful);
    }
    (*env)->ReleaseIntArrayElements(env, ints_, ints, 0);
    return arrayList_obj;
}