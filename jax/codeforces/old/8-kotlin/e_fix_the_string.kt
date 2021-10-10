/**
 * Accomplished using the EduTools plugin by JetBrains https://plugins.jetbrains.com/plugin/10081-edutools
 *
 * To modify the template, go to Preferences -> Editor -> File and Code Templates -> Other
 */

fun main() {
    repeat(readInt()) {
        solve()
    }
}

fun readLn() = readLine()!!
fun readInt() = readLn().toInt()

fun solve() {
    val n = readInt()

    val s = readLn()

    val ps = readLn().withIndex().filter { it.value == '1' }

    val ranges = ArrayList<Pair<Int, Int>>()

    var l = 0
    while (l < ps.size) {
        var r = l + 1
        while (r < ps.size && ps[r].index == ps[r - 1].index + 2) {
            ++r
        }

        ranges.add(Pair(ps[l].index, ps[r - 1].index + 3))
        l = r
    }

    for (i in 1 until ranges.size) {
        if (ranges[i - 1].second >= ranges[i].first) {
            println(-1)
            return
        }
    }

    var ans = 0
    for ((l, r) in ranges) {
        ans += if (r - l == 3) {
            calc1(s, l)
        } else {
            calc2(s, l, r)
        }
    }

    println(ans)
}

const val s1 = "(())"
const val s2 = "()()"

fun calc1(s: String, l: Int): Int {
    var c1 = 0
    var c2 = 0

    for (i in 0..3) {
        if (s[l + i] != s1[i]) {
            ++c1
        }

        if (s[l + i] != s2[i]) {
            ++c2
        }
    }

    return if (c1 < c2) c1 else c2
}

fun calc2(s: String, l: Int, r: Int): Int {
    var ret = 0
    for (i in l..r step 2) {
        if (s[i] != '(') {
            ++ret
        }
    }

    for (i in l + 1..r step 2) {
        if (s[i] != ')') {
            ++ret
        }
    }
    return ret
}