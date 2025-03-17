package test2;

import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        MathClass mathClass = new MathClass();

        double[] point1 = {0, 0};
        double[] point2 = {3, 0};
        double[] point3 = {3, 4};
        double[] point4 = {0, 4};

        mathClass.setVertices(Arrays.asList(point1, point2, point3, point4));

        System.out.println("Vertices:");
        for (double[] vertex : mathClass.getVertices()) {
            System.out.println("(" + vertex[0] + ", " + vertex[1] + ")");
        }

        System.out.println("Perimeter: " + mathClass.getPerimeter());

        double distance = mathClass.calculateDistance(point1, point3);
        System.out.println("Distance between (0, 0) and (3, 4): " + distance);
    }
}