fun readLn() = readLine()!!
fun readStrings() = readLn().split(" ")
fun readInt() = readLn().toInt()
fun readInts() = readStrings().map { it.toInt() }

fun main() {
    val n = readInt()

    val a = readInts().withIndex().map { (i, v) -> Pair(v, i) }.sortedByDescending { it.first }

    var cnt = 0
    a.withIndex().forEach { (i, p) ->
        cnt += i * p.first + 1
    }

    println(cnt)

    val seq = a.map { it.second + 1 }.joinToString(" ")
    println(seq)
}