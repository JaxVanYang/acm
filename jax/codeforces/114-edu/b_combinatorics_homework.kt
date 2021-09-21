fun readLn() = readLine()!!
fun readInt() = readLn().toInt()
fun readStrs() = readLn().split(" ")
fun readInts() = readStrs().map { it.toInt() }

fun main() {
	repeat(readInt()) {
		val (a, b, c, m) = readInts()

		val li = listOf(a, b, c).sorted()

		val min = maxOf(0, li[2] - 1 - li[1] - li[0])
		val max = li[0] + li[1] + li[2] - 3

		println(if (min <= m && m <= max) "YES" else "NO")
	}
}
