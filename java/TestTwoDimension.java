public class TestTwoDimension{
	public static void main(String [] argv){
		int [][] arr;//定义二维多维数组
		arr = new int [2][];	//当成一个一维数组初始化，数组元素是长度为2的一维数组
		for (int i=0; i<arr.length; i++){
			System.out.println(arr[i]);
		}
		arr[0] = new int [4];	//初始化arr数组第一个元素,第一个元素是一个数组，初始化为长度为4，元素为int的数组
		arr[0][1] = 6;	//第二个元素的初始化
		arr[0][3] = 8;
		System.out.println("arr[0]..");
		for (int i=0; i<arr[0].length; i++){
			System.out.println(arr[0][i]);
		}
	}	
}
