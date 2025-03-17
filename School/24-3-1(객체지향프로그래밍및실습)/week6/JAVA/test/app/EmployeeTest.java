// EmployeeTest.java
package test.app;

import test.example.Employee;
import java.util.Date;

public class EmployeeTest {
    public static void main(String[] args) {
        Employee[] employees = {
            new Employee("Kim Lee", "123-45-6789"),
            new Employee("Wooyeon Choi", "987-65-4321", new Date()),
            new Employee("Antoni Cook", "456-78-9012")
        };
        
        for (Employee employee : employees) {
            System.out.println("Name: " + employee.getName());
            System.out.println("SSN: " + employee.getSSN());
            System.out.println("Hire Date: " + employee.getHireDate());
            System.out.println();
        }
    }
}