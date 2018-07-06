public class stringArray{
	public static void main(String [] argv){
	//	String [][]strl = new String [][]{new String[3], new String[]{"hello"}};
		String [][] strl = new String[3][];
		for (int i = 0; i < strl.length; i++){
			System.out.println(strl[i]);
		}
		strl[0] = new String [4];
		strl[0][2] = "hello";

		for (int i=0; i<strl[0].length; i++){
			System.out.println(strl[0][i]);
		}
	}
}
