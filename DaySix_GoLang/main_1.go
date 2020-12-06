package main 
	
import ( 
	"bufio"
	"fmt"
	"os"
)

func main() {
  	args := os.Args
	
	if len(args) != 2 {
    	fmt.Println("Wrong parameters passed. Please run using again using the correct syntax:\n\n./main_1 <input_file_name>")
    	os.Exit(1)
	}

 	file, err := os.Open(args[1])
    if err != nil {
    	os.Exit(2)
    }

    set := make(map[string]bool)
    total := 0

	scanner := bufio.NewScanner(file)
    for scanner.Scan() {
       	line := scanner.Text()

       	if line != "" {
       		//fill set
       		//fmt.Println(line)

     			for c := range line {
     					set[string(line[c])] = true
          }

       	} else {
       		//evaluate set
       		total = total + len(set)

       		set = make(map[string]bool)
       	}
    }
    fmt.Printf("The total of the different sets is %d\n", total)
}
