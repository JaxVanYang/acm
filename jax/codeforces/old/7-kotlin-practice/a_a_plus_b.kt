fun readLn() = readLine()!!
fun readInt() = readLn().toInt()
fun readStrings() = readLn().split(" ")
fun readInts() = readStrings().map { it.toInt() }

fun main() {
	repeat(readInt()) {
		val (a, b) = readInts()
		println(a + b)
	}
}
