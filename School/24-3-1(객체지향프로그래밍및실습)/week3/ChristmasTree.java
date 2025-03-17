public class ChristmasTree {
	public static void main(String[] args) {
        	int N = 15;
       		for(int i=0;i<N-1;i++){
            		for(int j=N-1;j>i;j--){
                		System.out.print(" ");
            		}
            		for(int j=0;j<2*i+1;j++){
                		System.out.print("*");
            		}
            		System.out.println();
        	}
        	for(int i=0;i<N;i++){
            		for(int j=0;j<i;j++){
                		System.out.print(" ");
            		}
            		for(int j=2*N;j>2*i+1;j--){
                		System.out.print("*");
            		}
            		System.out.println();
        	}
    	}
}