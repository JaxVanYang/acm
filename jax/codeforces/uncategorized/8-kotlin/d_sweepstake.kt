fun readLn() = readLine()!!
fun readStrs() = readLn().split(" ")
fun readInts() = readStrs().map { it.toInt() }

fun main() {
	val (n, m) = readInts()

	val a = Array(m) {
		readInts()
	}

	val fCnt = IntArray(n + 1) { 0 }
	val lCnt = IntArray(n + 1) { 0 }
	val hashCnt = IntArray((n + 1) * n) { 0 }

	fun hash(f: Int, l: Int) = f * n + l

	for (i in 0 until m) {
		fCnt[a[i][0]]++
		lCnt[a[i][1]]++
		hashCnt[hash(a[i][0], a[i][1])]++
	}

	var ans = 1
	val x = a[0][0]
	val y = a[0][1]

	for (i in 1..n) {
		for (j in 1..n) {
			if (i == j) continue

			val c2 = hashCnt[hash(i, j)]
			val c1 = fCnt[i] + lCnt[j] - c2 * 2
			
			when {
				x == i && y == j -> ans = max(ans, 1)
				x == i || y == j -> ans = max(ans, c2 + 1)
				else -> ans = max(ans, c2 + c1 + 1)
			}
		}
	}

	println(ans)
}

fun max(a: Int, b: Int) = if (a > b) a else b
