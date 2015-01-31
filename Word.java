import java.util.*;

/**
 * 
 * @author Lauren
 * lpien@u.rochester.edu
 *
 */
public class Word implements Comparable<Word>{
	String s;
	int c;
	
	public Word(String str, int count){
		s = str;
		c = count;
	}

	
	public String toString(){
		String cString = String.format("%06d", c);
		String wordString = cString + "  " + s.toString();
		return wordString;
	}
	
	public int compareTo(Word arg0) {
		return s.compareToIgnoreCase(arg0.s);
	}
}
