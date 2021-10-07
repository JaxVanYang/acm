private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()

fun removeZeroes(x: Int): Int =
	if (x % 10 == 0) removeZeroes(x / 10) else x

fun f(x: Int) = removeZeroes(x + 1)

fun main() {
	var n = readInt()
	val st = HashSet<Int>()
	while (st.add(n)) n = f(n)
	println(st.size)
}
