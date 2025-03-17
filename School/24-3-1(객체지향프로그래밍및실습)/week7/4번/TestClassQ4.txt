import java.util.ArrayList;
import java.util.List;

class Cat {
    String name;
    int age;

    public Cat(String name, int age) {
        this.name = name;
        this.age = age;
    }

    @Override
    public String toString() {
        return "Cat[name=" + name + ", age=" + age + "]";
    }
}

class Dog {
    String breed;
    int weight;

    public Dog(String breed, int weight) {
        this.breed = breed;
        this.weight = weight;
    }

    @Override
    public String toString() {
        return "Dog[breed=" + breed + ", weight=" + weight + "]";
    }
}

class Circle {
    double radius;

    public Circle(double radius) {
        this.radius = radius;
    }

    @Override
    public String toString() {
        return "Circle[radius=" + radius + "]";
    }
}

class Rectangle {
    double length;
    double width;

    public Rectangle(double length, double width) {
        this.length = length;
        this.width = width;
    }

    @Override
    public String toString() {
        return "Rectangle[length=" + length + ", width=" + width + "]";
    }
}

class MyList {
    private List<Object> list;

    public MyList() {
        this.list = new ArrayList<>();
    }

    public void append(Object obj) {
        list.add(obj);
    }

    public void remove(Object obj) {
        list.remove(obj);
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder("MyList: [");
        for (int i = 0; i < list.size(); i++) {
            sb.append(list.get(i));
            if (i < list.size() - 1) {
                sb.append(", ");
            }
        }
        sb.append("]");
        return sb.toString();
    }
}

public class TestClassQ4 {
    public static void main(String[] args) {
        MyList myList = new MyList();

        Cat cat = new Cat("Whiskers", 3);
        Dog dog = new Dog("Labrador", 30);
        Circle circle = new Circle(5.5);
        Rectangle rectangle = new Rectangle(4.5, 3.0);

        myList.append(cat);
        myList.append(dog);
        myList.append(circle);
        myList.append(rectangle);

        System.out.println(myList);

        myList.remove(dog);

        System.out.println("After removing the dog:");
        System.out.println(myList);
    }
}
