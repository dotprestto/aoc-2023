package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

//const are defined in MAIN file

func day1() {
	contents, err := os.ReadFile("input")
	if err != nil {
		fmt.Print(err)
	}
	sum := 0

	// there must be a better way to do it, but I'm a beginner
	lines := strings.Split(string(contents), "\n")
	for _, line := range lines {
		holder := strings.Split(line, ":")
		game_id, _ := strconv.Atoi(strings.Split(holder[0], " ")[1])
		is_possible := true

		sets := strings.Split(holder[1], ";")
		for _, set := range sets {
			cubes := strings.Split(set, ",")
			for _, cube := range cubes {
				cube = strings.Trim(cube, " ")
				color := strings.Split(cube, " ")[1]
				value, _ := strconv.Atoi(strings.Split(cube, " ")[0])

				switch color {
				case "red":
					if value > MAX_RED {
						is_possible = false
					}
				case "green":
					if value > MAX_GREEN {
						is_possible = false
					}
				case "blue":
					if value > MAX_BLUE {
						is_possible = false
					}
				}

			}

			if !is_possible {
				break
			}

		}
		if is_possible {
			sum += game_id
		}
	}

	fmt.Println("Sum: ", sum)
}
