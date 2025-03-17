public class CheckWalk {
	public static void main(String[] args) {
		int gate = 0;
		int x = 0;

		for (int i = 1; i < 5; i++) {
			if (args[i].equals("1")){
				x = 1;
				for (int j = 0; j < 4-i; j++) {
					x *= 2;
				}
				gate += x;
			}
		}
		
		if (args[0].equals("1")) {
			if ( (gate == 1) || (gate == 3) ) {
				System.out.println("True");
			} else {
				System.out.println("False");
			}
		} else {
			if ( (gate == 6) || (gate == 8) ) {
				System.out.println("True");
			} else {
				System.out.println("False");
			}
		}
	}
}