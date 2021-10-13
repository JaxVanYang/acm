fun readLn() = readLine()!!
fun readInt() = readLn().toInt()

fun removeZeroes(n: Int): Int {
	var ret = n
	while (ret % 10 == 0) {
		ret /= 10
	}
	return ret;
}
fun f(n: Int) = removeZeroes(n + 1)

fun main() {
	var n = readInt()

	val st = HashSet<Int>()
	while (st.add(n)) n = f(n)
	println(st.size)
}
