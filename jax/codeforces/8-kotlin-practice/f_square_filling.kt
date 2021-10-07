private fun readLn() = readLine()!!
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }

val dx = arrayOf(
    intArrayOf(0, 1, 1),
    intArrayOf(-1, -1, 0),
    intArrayOf(-1, -1, 0),
    intArrayOf(0, 1, 1),
)
val dy = arrayOf(
    intArrayOf(1, 0, 1),
    intArrayOf(-1, 0, -1),
    intArrayOf(0, 1, 1),
    intArrayOf(-1, 0, -1),
)

fun main() {
    val (n, m) = readInts()

    val grid = Array(n) {
        readStrings().map { it.toInt() }
    }
//    println(grid.contentToString())

    fun valid(x: Int, y: Int): Boolean {
        return x in 0 until n && y in 0 until m
    }

    fun check(x: Int, y: Int): Int {
        for (i in 0..3) {
            var flag = true
            for (j in 0..2) {
                val x_ = x + dx[i][j]
                val y_ = y + dy[i][j]

//                println("x_ = $x_ y = $y_")

                if (!valid(x_, y_)) {
                    flag = false
                    continue
                }
                if (grid[x_][y_] != 1) {
                    flag = false
                    break
                }
            }

//            println("$i $flag")

            if (flag) return i
        }
        return -1
    }

    val ans = ArrayList<String>()

    for (x in 0 until n) {
        for (y in 0 until m) {
//            println("$x $y")
            if (grid[x][y] == 1) {
                when (check(x, y)) {
                    0 -> ans.add("${x + 1} ${y + 1}")
                    -1 -> {
                        println(-1)
                        return
                    }
                }
            }
        }
    }

    println(ans.size)
    println(ans.joinToString("\n"))
}