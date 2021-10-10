fun readLn() = readLine()!!
fun readInt() = readLn().toInt()

fun main() {
	repeat(readInt()) {
		solve()
	}
}

fun solve() {
	val s = readLn().filter { it != '=' }

	if (s.isEmpty()) {
		println('=')
	} else if (s.all { it == s.first() }) {
		println(s.first())
	} else {
		println('?')
	}
}
