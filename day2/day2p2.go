package main

import (
	"fmt"
	"os"
	"slices"
	"strconv"
	"strings"
)

//const are defined in MAIN file

func day2() {
	contents, err := os.ReadFile("input")
	if err != nil {
		fmt.Print(err)
	}
	sum := 0

	// there must be a better way to do it, but I'm a beginner
	lines := strings.Split(string(contents), "\n")
	for _, line := range lines {
		holder := strings.Split(line, ":")
		// game_id, _ := strconv.Atoi(strings.Split(holder[0], " ")[1])

		sets := strings.Split(holder[1], ";")
		reds := []int{}
		greens := []int{}
		blues := []int{}

		for _, set := range sets {
			cubes := strings.Split(set, ",")

			for _, cube := range cubes {
				cube = strings.Trim(cube, " ")
				color := strings.Split(cube, " ")[1]
				value, _ := strconv.Atoi(strings.Split(cube, " ")[0])

				switch color {
				case "red":
					reds = append(reds, value)
				case "green":
					greens = append(greens, value)
				case "blue":
					blues = append(blues, value)
				}

			}

		}
		red_min := slices.Max(reds)
		green_min := slices.Max(greens)
		blue_min := slices.Max(blues)
		sum += red_min * green_min * blue_min
	}

	fmt.Println("Sum: ", sum)
}
