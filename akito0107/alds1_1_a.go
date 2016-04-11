package main

import (
	"bufio"
	"os"
	"fmt"
	"strconv"
)

// http://qiita.com/tnoda_/items/b503a72eac82862d30c6
func main() {
	var n int
	fmt.Scan(&n)
	arr := make([]int, n, n * 2)
	iterator := nextIntIterator()
	for i := 0; i < n; i++ {
		arr[i] = iterator()
	}
	bubbleSort(&arr)
}

func nextIntIterator() func() int {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	return func() int {
		sc.Scan()
		i, e := strconv.Atoi(sc.Text())
		if e != nil {
			panic(e)
		}
		return i
	}
}

func printArr(arr *[]int) {
	for i, v := range *arr {
		fmt.Printf("%d", v)
		if i - 1 != len(*arr) {
			fmt.Printf(" ")
		}
	}
	fmt.Println()
}

func insertSort(_arr *[]int) {
	arr := *_arr
	printArr(&arr)
	for i := 1; i < len(arr); i++ {
		v := arr[i]
		var j = i - 1
		for j >= 0 && arr[j] > v {
			arr[j + 1] = arr[j]
			j--
		}
		arr[j+1] = v
		printArr(&arr)
	}
}

func bubbleSort(_arr *[]int) {
	arr := *_arr
	var flag int = 1
	var counter int = 0
	for flag > 0 {
		flag = 0
		for i := len(arr) - 1; i >= 1; i-- {
			if arr[i] < arr[i - 1] {
				counter++
				tmp := arr[i]
				arr[i] = arr[i - 1]
				arr[i - 1] = tmp
				flag = 1
			}
		}
	}
	printArr(&arr)
	fmt.Println(counter)
}
