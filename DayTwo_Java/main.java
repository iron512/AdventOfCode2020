import java.io.File;  // Import the File class
import java.io.FileNotFoundException;  // Import this class to handle errors
import java.util.Scanner; // Import the Scanner class to read text files

import java.util.List;
import java.util.ArrayList;

public class HelloWorld {
	public static void main( String[] args ) {
		if (args.length != 1) {
			System.out.println("Wrong parameters passed. Please run using again using the correct syntax:\n\njava main.java <input_file_name>\n");
			System.exit(1);
		}

		List<Password> psw = new ArrayList<Password>();

		try {
			File f = new File(args[0]);
			Scanner reader = new Scanner(f);
			while (reader.hasNextLine()) {
				String[] data = reader.nextLine().split("-| |: ");
				//Regex splitting: one of ": ", "-" or " " is ok

				int min = Integer.parseInt(data[0]);
				int max = Integer.parseInt(data[1]);
				char chr = data[2].charAt(0);
				String buffer = data[3];

				psw.add(new Password(min,max,chr,buffer));
			}
			reader.close();
		} catch (FileNotFoundException e) {
			System.out.println("The provided file is not correct. Please try again.");
		}
		
		int countS = 0;
		int countT = 0;
		for (Password p : psw) {
			if (p.checkStandardPolicy()) 
				countS++;

			if (p.checkTobogganPolicy())
				countT++;
		}

		System.out.println("The password matching the standard criteria are " + countS + ", while the ones matching the Toboggan Corporate Policies are " + countT);
	}
}

public class Password {
		int min;
		int max;
		char chr;
		String buffer;

		public Password(int min, int max, char chr, String buffer) {
			this.min = min;
			this.max = max;
			this.chr = chr;
			this.buffer = buffer;
		}

		public String toString() {
			return buffer + " (" + chr + ", " + min + "/" + max + ")";
		}

		public boolean checkStandardPolicy() {
			int count = 0;

			for (char ch: this.buffer.toCharArray()) {
				if (ch == this.chr)
					count++;
			}

			return (count >= min) && (count <= max);
		}

		public boolean checkTobogganPolicy() {
			return this.buffer.charAt(min-1) == this.chr ^ this.buffer.charAt(max-1) == this.chr;
		}
	}