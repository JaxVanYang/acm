fun readLn() = readLine()!!
fun readInt() = readLn().toInt()
fun readStrings() = readLn().split(" ")
fun readLongs() = readStrings().map { it.toLong() }
fun readInts() = readStrings().map { it.toInt() }

fun solve() {
    val (a, b, k) = readLongs()

    val c = a - b;

    println(k / 2 * c + k % 2 * a)
}

fun main() {
    repeat(readInt()) {
        solve()
    }
}