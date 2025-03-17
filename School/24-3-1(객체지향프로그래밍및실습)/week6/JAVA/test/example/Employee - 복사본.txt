// Employee.java
package test.example;

import java.util.Date;

public class Employee {
    private String name;
    private String ssn;
    private Date hireDate;
    
    {
        // Initialization block
        hireDate = new Date();
    }
    
    public Employee(String name, String ssn) {
        this.name = name;
        this.ssn = ssn;
    }
    
    public Employee(String name, String ssn, Date hireDate) {
        this.name = name;
        this.ssn = ssn;
        this.hireDate = hireDate;
    }
    
    public String getName() {
        return name;
    }
    
    public String getSSN() {
        return ssn;
    }
    
    public Date getHireDate() {
        return hireDate;
    }
}