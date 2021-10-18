package main

import (
	"bufio"
	"fmt"
	"os"
	//"strings"
	//"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	
	scanner.Scan()
	text := scanner.Text()
	fmt.Println(text)

	//num1 := strconv.Atoi(num)

	/*for i := 0; i < num1; i++ {
		commandArr := bufio.NewReader(os.Stdin)
		commandArr = strings.Fields(commandArr)
	}*/
}

func arriveAtClinic(catName string, infectionLevel int)  {
	
}

func updateInfectionLevel(catName string, increaseInfectionLevel int)  {
	
}

func treated(catName string)  {
	
}

func query()  {
	
}