fun readLn() = readLine()!!
fun readInt() = readLn().toInt()
fun readStrs() = readLn().split(" ")
fun readInts() = readStrs().map { it.toInt() }

fun main() {
	repeat(readInt()) {
		solve()
	}
}

fun solve() {
	val n = readInt()

	val a = Array(n) {
		val (s, t, flag) = readStrs()

		Pair(calc(s, t), flag.toInt())
	}

	var min = 0
	var max = Int.MAX_VALUE

	for ((v, flag) in a) {
		when (flag) {
			0 -> min = maxOf(min, v + 1)
			1 -> max = minOf(max, v)
		}
	}

	val l = max - min + 1
	if (l > 0) {
		println(l)
		println((min..max).joinToString(" "))
	} else {
		println(0)
	}
}

fun minOf(a: Int, b: Int) = if (a < b) a else b
fun maxOf(a: Int, b: Int) = if (a > b) a else b

fun calc(s: String, t: String): Int {
	val n = s.length
	val m = t.length
	val len = if (n < m) n else m

	for (i in 0 until len) {
		if (s[n - 1 - i] != t[m - 1 - i]) {
			return i
		}
	}

	return len
}
