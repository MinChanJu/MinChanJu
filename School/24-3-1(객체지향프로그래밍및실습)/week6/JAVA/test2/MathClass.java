package test2;

import java.util.ArrayList;
import java.util.List;

public class MathClass {
    private List<double[]> vertices;
    private double perimeter;

    public MathClass() {
        vertices = new ArrayList<>();
        perimeter = 0;
    }

    public List<double[]> getVertices() {
        return vertices;
    }

    public double getPerimeter() {
        return perimeter;
    }

    public void setVertices(List<double[]> vertices) {
        this.vertices = vertices;
        calculatePerimeter();
    }

    public void setPerimeter(double perimeter) {
        this.perimeter = perimeter;
    }

    public double calculateDistance(double[] point1, double[] point2) {
        double x1 = point1[0];
        double y1 = point1[1];
        double x2 = point2[0];
        double y2 = point2[1];
        return Math.sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    }

    public double calculatePerimeter() {
        if (vertices.size() < 2) {
            perimeter = 0;
        } else {
            perimeter = 0;
            for (int i = 0; i < vertices.size(); i++) {
                double[] point1 = vertices.get(i);
                double[] point2 = vertices.get((i + 1) % vertices.size());
                perimeter += calculateDistance(point1, point2);
            }
        }
        return perimeter;
    }
}