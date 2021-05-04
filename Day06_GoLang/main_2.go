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

    set := make(map[string]int)
    members := 0

    total := 0

	scanner := bufio.NewScanner(file)
    for scanner.Scan() {
       	line := scanner.Text()

       	if line != "" {
       		//fill set
       		//fmt.Println(line)

   			for c := range line {
   				if val, ok := set[string(line[c])]; !ok {
   					val = val
   					set[string(line[c])] = 0
   				}

				set[string(line[c])] = set[string(line[c])] + 1
			}

			members = members + 1
       	} else {
       		//evaluate set

       		for key, value := range set {
    			key = key

    			if value == members {
    				total = total + 1
      			}
			}

       		set = make(map[string]int)
       		members = 0
       	}
    }
    fmt.Printf("The total of the different sets is %d\n", total)
}
