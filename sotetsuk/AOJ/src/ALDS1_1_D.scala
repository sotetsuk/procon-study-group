import java.util.Scanner

object ALDS1_1_D { // -> Main
  def main(args: Array[String]) {
    val sc = new Scanner(System.in)
    val n = sc.nextInt
    val list = List.fill(n)(sc.nextInt)

    var minr = 1e10.toInt
    var ans = -1e10.toInt
    for (r <- list) {
      ans = math.max(ans, r - minr)
      minr = math.min(minr, r)
    }
    println(ans)
  }
}