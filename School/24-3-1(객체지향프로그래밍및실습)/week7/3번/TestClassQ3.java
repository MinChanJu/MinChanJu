class Person {
    String name;

    public Person(String name) {
        this.name = name;
    }

    public void description() {
        System.out.println("This is a person named " + name);
    }
}

class Employee extends Person {
    String jobTitle;

    public Employee(String name, String jobTitle) {
        super(name);
        this.jobTitle = jobTitle;
    }

    @Override
    public void description() {
        System.out.println("This is an employee named " + name + " with job title: " + jobTitle);
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (obj == null || getClass() != obj.getClass()) return false;
        
        Employee other = (Employee) obj;
        return name.equals(other.name) && jobTitle.equals(other.jobTitle);
    }

    @Override
    public int hashCode() {
        int result = name.hashCode();
        result = 31 * result + jobTitle.hashCode();
        return result;
    }
}

class Student extends Person {
    String major;

    public Student(String name, String major) {
        super(name);
        this.major = major;
    }

    @Override
    public void description() {
        System.out.println("This is a student named " + name + " majoring in: " + major);
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (obj == null || getClass() != obj.getClass()) return false;
        
        Student other = (Student) obj;
        return name.equals(other.name) && major.equals(other.major);
    }

    @Override
    public int hashCode() {
        int result = name.hashCode();
        result = 31 * result + major.hashCode();
        return result;
    }
}

public class TestClassQ3 {
    public static void main(String[] args) {
        Employee emp1 = new Employee("Alice", "Software Engineer");
        Employee emp2 = new Employee("Alice", "Software Engineer");
        Student stu1 = new Student("Bob", "Computer Science");
        Student stu2 = new Student("Bob", "Computer Science");

        System.out.println("emp1 equals emp2: " + emp1.equals(emp2)); // true

        System.out.println("stu1 equals stu2: " + stu1.equals(stu2)); // true

        System.out.println("emp1 hashCode: " + emp1.hashCode());
        System.out.println("emp2 hashCode: " + emp2.hashCode());

        System.out.println("stu1 hashCode: " + stu1.hashCode());
        System.out.println("stu2 hashCode: " + stu2.hashCode());
    }
}
