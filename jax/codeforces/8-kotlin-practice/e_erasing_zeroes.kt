private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()

fun main() {
    repeat(readInt()) {
        solve()
    }
}

fun solve() {
    val s = readLn()

    val a = s.withIndex().filter { it.value == '1' }

    var ans = 0

    for (i in 1..a.lastIndex) {
        ans += a[i].index - a[i - 1].index - 1
    }

    println(ans)
}