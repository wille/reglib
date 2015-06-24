jstring getstring(JNIEnv * env, char* buffer);

char* getcstring(JNIEnv * env, jstring string);

jobject getjavahandle(JNIEnv * env, int handle);

jobject createlist(JNIEnv * env);

void addtolist(JNIEnv * env, jobject list, jobject obj);

jobject getvalue(JNIEnv * env, char* name, char* data);
