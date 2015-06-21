package reglib;

public class NativeRegistry {
	
	public static native Handle openKey(int hKey, String lpSubKey);
	
	public static native Handle createKey(int hKey, String lpSubKey);

}
