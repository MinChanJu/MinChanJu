public class Employee {
	private String Name;
	private String SSN;
	private String HireDate;

	public Employee() {
		this.Name = "";
		this.SSN = "";
		this.HireDate = "";
	}
	
	public Employee(String Name, String SSN, String HireDate) {
		this.Name = Name;
		this.SSN = SSN;
		this.HireDate = HireDate;
	}

	public void printinfo() {
		System.out.println("Name : " + this.Name + ", SSN : " + this.SSN + ", HireDate : " + this.HireDate);
	}
}