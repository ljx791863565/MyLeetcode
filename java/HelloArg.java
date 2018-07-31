import java.util.*;
import java.text.MessageFormat;
public class HelloArg
{
	public static void main(String []args)
	{
		Locale currentLocale = null;
		if (args.length == 2){
			currentLocale = new Locale(args[0], args[1]);
		}else{
			currentLocale = Locale.getDefault();
		}

		ResourceBundle bundle = ResourceBundle.getBundle("MyResolurce", currentLocale);
		String msg = bundle.getString("msg");
		System.out.println(MessageFormat.format(msg, "yeeku", new Date()));
	}
}
