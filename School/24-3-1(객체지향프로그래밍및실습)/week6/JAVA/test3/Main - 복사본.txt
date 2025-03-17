package test3;

import test2.MathClass;

public class Main {
    public static void main(String[] args) {
        MathClassTest.testSquare();
    }
}

class MathClassTest {
    public static void testSquare() {
        double[] point1 = {0, 0};
        double[] point2 = {4, 0};
        double[] point3 = {4, 4};
        double[] point4 = {0, 4};

        new Square(point1, point2, point3, point4) {
            {
                System.out.println("Perimeter: " + getPerimeter());
                System.out.println("Area: " + getArea());
            }
        };
    }
}