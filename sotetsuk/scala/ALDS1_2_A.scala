import java.util.Scanner

object Main {
  def main(args: Array[String]) {
    val sc = new Scanner(System.in)
    val n = sc.nextInt
    val list: Array[Int] = Array.fill(n)(sc.nextInt)

    var flag = true
    var count = 0
    while (flag) {
      flag = false
      for (j <- n-1 to 1 by -1) {
        if (list(j) < list(j - 1)) {
          val tmp = list(j - 1)
          list(j - 1) = list(j)
          list(j) = tmp
          count += 1
          flag = true
        }
      }
    }
    println(list.toList.mkString(" "))
    println(count)
  }
}
