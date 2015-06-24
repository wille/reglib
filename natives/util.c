#include <jni.h>

#ifndef NULL
#define NULL 0
#endif

jstring getstring(JNIEnv * env, char* buffer) {
	return (*env)->NewStringUTF(env, buffer);
}

char* getcstring(JNIEnv * env, jstring string) {
	return (*env)->GetStringUTFChars(env, string, NULL);
}

jobject getjavahandle(JNIEnv * env, int handle) {
	jclass clazz = (*env)->FindClass(env, "reglib/Handle");
	jmethodID constructor = (*env)->GetMethodID(env, clazz, "<init>", "(I)V");

	jobject obj = (*env)->NewObject(env, clazz, constructor, handle);
	return obj;
}

jobject createlist(JNIEnv * env) {
	jclass clazz = (*env)->FindClass(env, "java/util/ArrayList");

	jmethodID method = (*env)->GetMethodID(env, clazz, "<init>", "()V");

	jobject list = (*env)->NewObject(env, clazz, method);

	return list;
}

void addtolist(JNIEnv * env, jobject list, jobject obj) {
	jclass clazz = (*env)->FindClass(env, "java/util/ArrayList");

	(*env)->CallBooleanMethod(env, list, (*env)->GetMethodID(env, clazz, "add", "(Ljava/lang/Object;)Z"));
}

jobject getvalue(JNIEnv * env, char* name, char* data) {
	jclass clazz = (*env)->FindClass(env, "reglib/RegistryValue");
	jmethodID constructor = (*env)->GetMethodID(env, clazz, "<init>", "(Ljava/lang/String;Ljava/lang/String)V");

	jobject obj = (*env)->NewObject(env, clazz, constructor, getstring(env, name), getstring(env, data));
	return obj;
}
