public class ArrayUtils
{
	public static int search(String []array, String target)
	{
		for (int i = 0; i < array.length; i++){
			if (array[i] != null && array[i].equals(target)){
				return i;
			}
			return -1;
		}
		return 0;
	}
}
