import java.util.Scanner

object Main {
  def main(args: Array[String]) {
    val sc = new Scanner(System.in)
    val N = sc.nextInt()
    val arr: Array[Int] = Array.fill(N)(sc.nextInt())

    var cnt = 0
    for((x, i) <- arr.zipWithIndex) {
      var minj = i
      for(j <- i until arr.length) {
        if(arr(minj) > arr(j)) minj = j
      }
      if(i != minj) cnt += 1
      val t = arr(i); arr(i) = arr(minj); arr(minj) = t  // swap
    }
    println(arr.mkString(" "))
    println(cnt)
  }
}