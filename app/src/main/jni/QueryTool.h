//
// Created by ly on 2016/7/3.
//
//   java中的原始类型和本地方法中的 类型的对应
//   Java类型　　本地类型　　字节(bit)
//　　boolean　 　jboolean　　 8, unsigned
//　　byte　　　　jbyte　　　　8
//　　char　　　　jchar　　　　16, unsigned
//　　short　　　 jshort　　　 16
//　　int　　　　 jint　　　　 32
//　　long　　　　jlong　　　　64
//　　float　　　 jfloat　　　 32
//　　double　　　jdouble　　　64
//　　void　　　　void　　　　 n/a

//　　Object	  jobject	   任何Java对象，或者没有对应java类型的对象
//    Class	      jclass	   Class对象
//　　String	  jstring	   字符串对象
//    Object[]	  jobjectArray 任何对象的数组
//　　boolean[]	  jbooleanArray	布尔型数组
//　　byte[]	  jbyteArray	比特型数组
//　　char[]      jcharArray	字符型数组
//　　short[]	  jshortArray	短整型数组
//　　int[]	      jintArray	    整型数组
//　　long[]	  jlongArray	长整型数组
//　　float[]	  jfloatArray	浮点型数组
//　　double[]	  jdoubleArray	双浮点型数组



//    下面是访问String的一些方法：
//    GetStringUTFChars将jstring转换成为UTF-8格式的char*
//    GetStringChars将jstring转换成为Unicode格式的char*
//    ReleaseStringUTFChars释放指向UTF-8格式的char*的指针
//    ReleaseStringChars释放指向Unicode格式的char*的指针
//    NewStringUTF创建一个UTF-8格式的String对象
//    NewString创建一个Unicode格式的String对象
//    GetStringUTFLengt获取 UTF-8格式的char*的长度　
//    GetStringLength获取Unicode格式的char*的长 度

//    获取数组元素指针的对应关系：

//    函数	                    Java 数组类型	本地类型
//    GetBooleanArrayElements	jbooleanArray	jboolean
//    GetByteArrayElements	    jbyteArray	    jbyte
//    GetCharArrayElements	    jcharArray	    jchar
//    GetShortArrayElements	    jshortArray	    jshort
//    GetIntArrayElements	    jintArray	    jint
//    GetLongArrayElements	    jlongArray	    jlong
//    GetFloatArrayElements	    jfloatArray	    jfloat
//    GetDoubleArrayElements	jdoubleArray	jdoubl

//    使用java对象的数组
//    GetObjectArrayElement     SetObjectArrayElement

//   使用Java对象

//   使用Java对象函数	描述
//   GetFieldID	        得到一个实例的域的ID
//   GetStaticFieldID	得到一个静态的域的ID
//   GetMethodID	    得到一个实例的方法的ID
//   GetStaticMethodID	得到一个静态方法的ID
//　　
//　　释放数组元素指针的对应关系：
//　　 Function　　　　　　　　　　　　Array Type
//　　 ReleaseBooleanArrayElements　　 boolean
//　　 ReleaseByteArrayElements　　　　byte
//　　 ReleaseCharArrayElements　　　　char
//　　 ReleaseShortArrayElements　　　 short
//　　 ReleaseIntArrayElements　　　　 int
//　　 ReleaseLongArrayElements　　　　long
//　　 ReleaseFloatArrayElements　　　 float
//　　 ReleaseDoubleArrayElements　　　double

//     JNI字段描述符
//     Java 类型   符号
//     Boolean     Z
//     Byte        B
//     Char        C
//     Short       S
//     Int         I
//     Long        J
//     Float       F
//     Double      D
//     Void        V
//     objects     以"L"开头，以";"结尾，中间是用"/" 隔开的包及类名。
//                 比如：Ljava/lang/String;如果是嵌套类，则用$来表示嵌套。例如 "(Ljava/lang/String;Landroid/os/FileUtils$FileStatus;)Z"
//    另外数组类型的简写,则用"["加上如表A所示的对应类型的简写形式进行表示
//    比如：[I 表示 int [];
//          [L/java/lang/objects;表示Objects[],
//          [F 表示 float[ ]
//          [[I 表示 int  [ ][ ]
//          [[F 表示 float[ ][ ]

//    JNI方法描述符    例如：
//    Java层方法                                  JNI函数签名
//    void Func()                                 ()V
//    String test ( )                             Ljava/lang/String;
//    void Func(int, int)                         (II)V
//    int Func(String,String)                     (Ljava/lang/String;Ljava/lang/String;)I
//    int f (int i, Object object)                (ILjava/lang/Object;)I
//    void set (byte[ ] bytes)                    ([B)V

//   jni调用Java方法
//jobject     (*CallObjectMethod)(JNIEnv*, jobject, jmethodID, ...);
//jobject     (*CallObjectMethodV)(JNIEnv*, jobject, jmethodID, va_list);
//jobject     (*CallObjectMethodA)(JNIEnv*, jobject, jmethodID, jvalue*);
//jboolean    (*CallBooleanMethod)(JNIEnv*, jobject, jmethodID, ...);
//jboolean    (*CallBooleanMethodV)(JNIEnv*, jobject, jmethodID, va_list);
//jboolean    (*CallBooleanMethodA)(JNIEnv*, jobject, jmethodID, jvalue*);
//jbyte       (*CallByteMethod)(JNIEnv*, jobject, jmethodID, ...);
//jbyte       (*CallByteMethodV)(JNIEnv*, jobject, jmethodID, va_list);
//jbyte       (*CallByteMethodA)(JNIEnv*, jobject, jmethodID, jvalue*);
//jchar       (*CallCharMethod)(JNIEnv*, jobject, jmethodID, ...);
//jchar       (*CallCharMethodV)(JNIEnv*, jobject, jmethodID, va_list);
//jchar       (*CallCharMethodA)(JNIEnv*, jobject, jmethodID, jvalue*);
//jshort      (*CallShortMethod)(JNIEnv*, jobject, jmethodID, ...);
//jshort      (*CallShortMethodV)(JNIEnv*, jobject, jmethodID, va_list);
//jshort      (*CallShortMethodA)(JNIEnv*, jobject, jmethodID, jvalue*);
//jint        (*CallIntMethod)(JNIEnv*, jobject, jmethodID, ...);
//jint        (*CallIntMethodV)(JNIEnv*, jobject, jmethodID, va_list);
//jint        (*CallIntMethodA)(JNIEnv*, jobject, jmethodID, jvalue*);
//jlong       (*CallLongMethod)(JNIEnv*, jobject, jmethodID, ...);
//jlong       (*CallLongMethodV)(JNIEnv*, jobject, jmethodID, va_list);
//jlong       (*CallLongMethodA)(JNIEnv*, jobject, jmethodID, jvalue*);
//jfloat      (*CallFloatMethod)(JNIEnv*, jobject, jmethodID, ...) __NDK_FPABI__;
//jfloat      (*CallFloatMethodV)(JNIEnv*, jobject, jmethodID, va_list) __NDK_FPABI__;
//jfloat      (*CallFloatMethodA)(JNIEnv*, jobject, jmethodID, jvalue*) __NDK_FPABI__;
//jdouble     (*CallDoubleMethod)(JNIEnv*, jobject, jmethodID, ...) __NDK_FPABI__;
//jdouble     (*CallDoubleMethodV)(JNIEnv*, jobject, jmethodID, va_list) __NDK_FPABI__;
//jdouble     (*CallDoubleMethodA)(JNIEnv*, jobject, jmethodID, jvalue*) __NDK_FPABI__;
//void        (*CallVoidMethod)(JNIEnv*, jobject, jmethodID, ...);
//void        (*CallVoidMethodV)(JNIEnv*, jobject, jmethodID, va_list);
//void        (*CallVoidMethodA)(JNIEnv*, jobject, jmethodID, jvalue*);