package reglib;

public class NativeRegistry {
	
	public static native Handle openKey(int hKey, String lpSubKey);

}
