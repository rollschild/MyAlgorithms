package main

func hammingWeight(num uint32) int {
	var pc [256]byte
	for i := range pc {
		pc[i] = pc[i/2] + byte(i&1)
	}

	return int(
		pc[byte(num>>0)] +
			pc[byte(num>>8)] +
			pc[byte(num>>16)] +
			pc[byte(num>>24)] +
			pc[byte(num>>32)] +
			pc[byte(num>>40)] +
			pc[byte(num>>48)] +
			pc[byte(num>>56)])
}
