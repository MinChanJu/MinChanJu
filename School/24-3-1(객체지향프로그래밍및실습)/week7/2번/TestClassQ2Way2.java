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
}

public class TestClassQ2Way2 {
    public static void main(String[] args) {
        Person[] people = new Person[] {
            new Employee("Alice", "Software Engineer"),
            new Student("Bob", "Computer Science")
        };

        for (Person person : people) {
            person.description();
        }
    }
}
