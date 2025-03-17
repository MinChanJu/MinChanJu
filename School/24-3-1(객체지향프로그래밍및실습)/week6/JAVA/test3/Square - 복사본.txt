package test3;

import test2.MathClass;

import java.util.Arrays;

public class Square extends MathClass {
    private double side;

    public Square(double[] point1, double[] point2, double[] point3, double[] point4) {
        setVertices(Arrays.asList(point1, point2, point3, point4));
        side = calculateDistance(point1, point2);
    }

    public double getArea() {
        return side * side;
    }
}