import java.io.*;
public class FileStreamDemo
{
	public static void main(String []args) throws IOException
	{
		File inFile = new File("face.gif");
		File outFile = new File("newFace.gif");

		FileInputStream inStream = new FileInputStream(inFile);
		FileOutputStream outStream = new FileOutputStream(outFile);

		byte []inOutb = new byte[inStream.available()];
		inStream.read(inOutb);
		outStream.write(inOutb);

		inStream.close();
		outStream.close();
	}
}
