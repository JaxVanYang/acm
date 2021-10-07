fun readLn() = readLine()!!
fun readInt() = readLn().toInt()
fun readStrs() = readLn().split(" ")
fun readInts() = readStrs().map { it.toInt() }

fun main() {
	repeat (readInt()) {
		val (a, b) = readInts()
		println(a + b)
	}
}
