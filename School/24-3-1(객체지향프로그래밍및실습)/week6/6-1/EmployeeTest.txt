public class EmployeeTest {
    public static void main(String[] args) {
        Employee[] employees = new Employee[3];
        
        employees[0] = new Employee("Jone", "020207-3151620", "2020-03-02");
        employees[1] = new Employee("Mike", "050829-4623412", "2024-03-04");
        employees[2] = new Employee("David", "040526-3521452", "2022-09-26");

        for (Employee employee : employees) {
            employee.printinfo();
        }
    }
}
