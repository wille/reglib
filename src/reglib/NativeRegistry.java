package reglib;

public class NativeRegistry {
		
	/**
	 * Returns the error code returned by <a href="https://msdn.microsoft.com/en-us/library/windows/desktop/ms724844(v=vs.85).aspx">RegCreateKeyEx</a>
	 * ERROR_SUCCESS (0x0) if succeeded or any of the system <a href="https://msdn.microsoft.com/en-us/library/windows/desktop/ms681382(v=vs.85).aspx">error codes</a> (0-499)
	 * @param hKey {@link reglib.HKEY}
	 * @param lpSubKey the subkey to create
	 * @return
	 */
	public static native int createKey(int hKey, String lpSubKey);
	
	/**
	 * Returns the error code returned by <a href="https://msdn.microsoft.com/en-us/library/windows/desktop/ms724847(v=vs.85).aspx">RegDeleteKeyEx</a>
	 * ERROR_SUCCESS (0x0) if succeeded or any of the system <a href="https://msdn.microsoft.com/en-us/library/windows/desktop/ms681382(v=vs.85).aspx">error codes</a> (0-499)
	 * @param hKey {@link reglib.HKEY}
	 * @param lpSubKey the subkey to delete
	 * @return
	 */
	public static native int deleteKey(int hKey, String lpSubKey);
	
	public static native Object[] enumValues(int hKey, String lpSubKey);

}
