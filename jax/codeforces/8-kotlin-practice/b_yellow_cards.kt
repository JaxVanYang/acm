fun readLn() = readLine()!!
fun readStrs() = readLn().split(" ")
fun readInt() = readLn().toInt()
fun readInts() = readStrs().map { it.toInt() }

fun max(a: Int, b: Int) = if (a > b) a else b
fun min(a: Int, b: Int) = if (a < b) a else b

fun main() {
	var a1 = readInt()
	var a2 = readInt()
	var k1 = readInt()
	var k2 = readInt()
	var n = readInt()

	if (k2 < k1) {
		k1 = k2.also { k2 = k1 }
		a1 = a2.also { a2 = a1 }
		// println("a1 = ${a1} a2 = ${a2} k1 = ${k1} k2 = ${k2}")
	}

	val maxV = if (k1 * a1 >= n) {
		n / k1
	} else {
		a1 + min(a2, (n - k1 * a1) / k2)
	}

	n -= a1 * (k1 - 1) + a2 * (k2 - 1)
	val minV = max(0, min(n, a1 + a2))

	println("${minV} ${maxV}")
}
