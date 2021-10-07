fun main() {
	val n = readLine()!!.toInt()
	val s = readLine()!!
	val fl = readLine()!!.split(" ").map { it.toInt() }

	fun f(c: Char) = '0' + fl[c - '1']

	val l = s.indexOfFirst { c -> f(c) > c }
		.takeIf { it >= 0 } ?: s.length
	val r = s.withIndex().indexOfFirst { (i, c) -> i > l && f(c) < c }
		.takeIf { it >= 0 } ?: s.length
	
	val ans =
		s.substring(0, l) +
		s.substring(l, r).map { c -> f(c) }.joinToString("") +
		s.substring(r)

	println(ans)
}
