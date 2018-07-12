public class Adderss{
	private final String detail;
	private final String postCode;

	public Adderss(){
		this.detail = "";
		this.postCode = "";
	}
	public Adderss(String detail, String postCode){
		this.detail = detail;
		this.postCode = postCode;
	}
	public String getDetail(){
		return this.detail;
	}
	public String getPostCode(){
		return this.postCode;
	}
	public boolean equals(Object obj){
		if (obj instanceof Adderss){
			Adderss ad = (Adderss)obj;
			if (this.getDetail().equals(ad.getDetail()) && this.getPostCode().equals(ad.getPostCode())){
				return true;
			}
		}
		return false;
	}
	public int hashCode(){
		return detail.hashCode() + postCode.hashCode();
	}
}
