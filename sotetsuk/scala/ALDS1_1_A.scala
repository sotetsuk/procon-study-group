import java.util.Scanner

object Main {
  def main(args: Array[String]) {
    val sc = new Scanner(System.in)
    val n = sc.nextInt
    val arr: Array[Int] = Array.fill(n)(sc.nextInt)

    var v, j = 0
    for (i <- 1 to n - 1) {
      println(arr.toList.mkString(" "))
      v = arr(i)
      j = i - 1
      while (j >= 0 && arr(j) > v) {
        arr(j + 1) = arr(j)
        j -= 1
      }
      arr(j + 1) = v
    }
    println(arr.toList.mkString(" "))
  }
}
