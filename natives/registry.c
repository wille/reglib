#include <windows.h>
#include <jni.h>

#include "reglib_NativeRegistry.h"
#include "util.h"

#define RESERVED 0
#define DEFAULT_KEY_TYPE REG_OPTION_NON_VOLATILE

int open(int hKey, char* lpSubKey, int* response) {
	int phkResult;

	response = RegOpenKeyEx(hKey, lpSubKey, 0, KEY_SET_VALUE, &phkResult);

	return phkResult;
}

JNIEXPORT jint JNICALL Java_reglib_NativeRegistry_createKey(JNIEnv * env, jclass z, jint hKey, jstring lpSubKey) {
	int phkResult;
	int lpdwDisposition;

	int response = RegCreateKeyEx(hKey, getcstring(env, lpSubKey), RESERVED, NULL, DEFAULT_KEY_TYPE, KEY_WRITE, NULL, &phkResult, &lpdwDisposition);

	RegCloseKey(phkResult);

	return response;
}

JNIEXPORT jint JNICALL Java_reglib_NativeRegistry_deleteKey(JNIEnv * env, jclass z, jint hKey, jstring lpSubKey) {
	int response;
	int handle = open(hKey, getcstring(env, lpSubKey), &response);

	if (response != ERROR_SUCCESS) {
		return response;
	}

	response = RegDeleteKeyEx(handle, getcstring(env, lpSubKey), KEY_WOW64_64KEY, RESERVED);

	return response;
}
