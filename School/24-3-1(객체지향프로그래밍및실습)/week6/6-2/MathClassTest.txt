public class MathClassTest {
	public static void main(String[] args) {
		Square mv = new Square(20.2, 32.5);
		
		System.out.print("Perimeter : ");
		System.out.print(mv.calculatePerimeter());
		System.out.print(", Area : ");
		System.out.print(mv.calculateArea());
	}
}