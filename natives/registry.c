#include <windows.h>
#include <jni.h>

#include "reglib_NativeRegistry.h"
#include "util.h"

JNIEXPORT jobject JNICALL Java_reglib_NativeRegistry_openKey(JNIEnv * env, jclass z, jint hKey, jstring lpSubKey) {
	int* ihandle;

	RegOpenKeyEx(hKey, getcstring(env, lpSubKey), 0, 0, &ihandle);

	return getjavahandle(env, ihandle);
}
