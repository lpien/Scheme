/**
 * 
 * @author Lauren
 * lpien@u.rochester.edu
 *
 * @param <AnyType>
 */
public class printConsumer <AnyType> implements Consumer<AnyType>{
	public int total;
	public int count;
	
	public printConsumer(int t){
		total = t;
		count = 0;
	}
	
	public void accept(AnyType actor){
		count++;
		if(total>40){
		if(count <= 20){
			System.out.println(actor.toString());
		}
		if(count == 21){
			System.out.println("...");
		}
		if(count >= total - 20){
			System.out.println(actor.toString());
		}
		}
		else{
			System.out.println(actor.toString());
		}
	}

}
