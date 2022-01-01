package sort

// BubbleSort is a simple sorting algorithm that repeatedly steps through
// the list to be sorted, compares each pair of adjacent items and swaps
// them if they are in the wrong order. The pass through the list is repeated
// until no swaps are needed, which indicates that the list is sorted.
func BubbleSort(data []int) {
	dataLen := len(data)
	swapped := false

	for i := 0; i < dataLen-1; i++ {
		for j := 0; j < dataLen-1; j++ {
			if data[j] > data[j+1] {
				data[j], data[j+1] = data[j+1], data[j]
				swapped = true
			}
		}
		if !swapped {
			break
		}
	}
}
