fun readLn() = readLine()!!
fun readInt() = readLn().toInt()
fun readInts() = readLn().split(" ").map { it.toInt() }

fun main() {
	repeat(readInt()) {
		solve()
	}
}

fun solve() {
	val n = readInt()

	val (a, va) = readInts()
	val (c, vc) = readInts()
	val dv = vc - va
	val b = readInt()
	val dd = b - a

	if (dd < dv) {
		println(va + dd)
	} else {
		println(vc)
	}
}
