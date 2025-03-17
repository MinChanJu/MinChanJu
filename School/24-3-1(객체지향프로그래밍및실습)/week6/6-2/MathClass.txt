public class MathClass {
	private double[] Vertices = new double[3];
	private double Perimeter;
	
	public MathClass() {
		this.Vertices[0] = 0;
		this.Vertices[1] = 0;
		this.Perimeter = 0;
	}

	public MathClass(double x, double y, double peri) {
		this.Vertices[0] = x;
		this.Vertices[1] = y;
		this.Perimeter = peri;
	}

	public double calculateDistance(double x1, double y1, double x2, double y2) {
		return Math.sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
	}

	public double rePeri() {
		return this.Perimeter;
	}
}