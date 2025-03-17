public class Square {
	private double width;
	private double height;
	
	public Square(double width, double height) {
		this.width = width;
		this.height = height;
	}

	public double calculatePerimeter() {
		return 2 * (width + height);
	}
	
	public double calculateArea() {
		return (width * height);
	}
}