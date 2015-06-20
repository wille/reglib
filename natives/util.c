#include <jni.h>

#define NULL 0

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
