/**
 * Accomplished using the EduTools plugin by JetBrains https://plugins.jetbrains.com/plugin/10081-edutools
 *
 * To modify the template, go to Preferences -> Editor -> File and Code Templates -> Other
 */

fun main() {
    println("? ${(1..100).joinToString(" ")}")
    val a = readInt()
    println("? ${(1..100).map { it shl 7 }.joinToString(" ")}")
    val b = readInt()
    val ans = (a shr 7 shl 7) + (b and ((1 shl 7) - 1).toInt())
    println("! $ans")
}

fun readInt() = readLine()!!.toInt()