import java.util.*;

class Employee
{
	public Employee(String n, double s, int year, int month, int day)
	{
		name = n;
		salary = s;
		GregorianCalendar calendar = new GregorianCalendar(year, month-1, day);
		hireDay = calendar.getTime();
	}
	public String getName()
	{
		return name;
	}
	public double getSalary()
	{
		return salary;
	}
	public Date getHireDay()
	{
		return (Date)hireDay.clone();
	}
	public void raiseSalary(double byPercent)
	{
		double raise = salary * byPercent / 100;
		salary += raise;
	}

	private String name;
	private double salary;
	private Date hireDay;
}
class Manager extends Employee
{
	Manager(String n, double s, int year, int month, int day)
	{
		super(n, s, year, month, day);
		bonus = 0;
	}
	public void setSalary(double b)
	{
		bonus = b;
	}
	public double getSalary()
	{
		double baseSalary = super.getSalary();
		return baseSalary + bonus;
	}
	private double bonus;
}
public class TestEmployee
{
	public static void main(String[] args)
	{
		Manager boss = new Manager("kaer", 100000, 1786, 8, 12);
		boss.setSalary(10000);
		Employee[] staff = new Employee[4];
		staff[0] = boss;
		staff[1] = new Employee("Lisa", 75000, 1987, 3, 31);
		staff[2] = new Employee("July", 56000, 1995, 8, 22);
		staff[3] = new Employee("Dora", 40000, 1994, 4, 4);

		for (Employee e : staff){
			e.raiseSalary(5);
		}
		for (Employee e : staff){
			System.out.println("name = " + e.getName() + ", salary = " + e.getSalary() + ", hireDay = " + e.getHireDay());
		}
	}
}

