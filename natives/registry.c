#include <windows.h>
#include <jni.h>

#include "reglib_NativeRegistry.h"
#include "util.h"

#define RESERVED 0
#define DEFAULT_KEY_TYPE REG_OPTION_NON_VOLATILE

JNIEXPORT jint JNICALL Java_reglib_NativeRegistry_createKey(JNIEnv * env, jclass z, jint hKey, jstring lpSubKey) {
	int phkResult;
	int lpdwDisposition;

	int response = RegCreateKeyEx(hKey, getcstring(env, lpSubKey), RESERVED, NULL, DEFAULT_KEY_TYPE, KEY_WRITE, NULL, &phkResult, &lpdwDisposition);

	RegCloseKey(phkResult);

	return response;
}
