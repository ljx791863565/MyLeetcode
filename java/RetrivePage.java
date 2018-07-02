public class RetrivePage{
	private static HttpClient HttpClient = new HttpClient();

	static {
		HttpClient.getHostConfiguration().setProxy("172.17.18.84", 8080);
	}
	public static boolean downloadPage(String path) throws HttpException,
		   IOException{
			   InputStream input = null;
			   OutputStream output = null;
			   PostMethod PostMethod = new PostMpthod(path);
			   NameValuePair[] postData = new NameValuePair[2];
			   postData[0] = 
		   }
}
