import java.util.Scanner

object Main {
  def main(args: Array[String]) {
    val sc = new Scanner(System.in)
    val n = sc.nextInt()
    val arr: Array[Int] = Array.fill(n)(sc.nextInt())

    val (sortedArr, gList, m, cnt) = shellSort(arr)
    println(m)
    println(gList.toList.take(m).mkString(" "))
    println(cnt)
    sortedArr.foreach(println)
  }

  def insertionSort(arr: Array[Int], g: Int): (Array[Int], Int) = {
    val ret = arr.clone()
    var cnt = 0

    for((v, i) <- ret.zipWithIndex) {
      var j = i - g
      while(j >= 0 && ret(j) > v) {
        ret(j + g) = ret(j)
        cnt += 1
        j -= g
      }
      ret(j + g) = v
    }

    return (ret, cnt)
  }

  def shellSort(arr: Array[Int]): (Array[Int], Array[Int], Int, Int) = {
    var ret: Array[Int] = arr.clone()
    val gList = Array.fill(ret.length)(-1)
    var cnt = 0

    var g = arr.length
    var m = 0
    while(g > 0) {
      gList(m) = g
      var (sortedArr, c) = insertionSort(ret, g)
      ret = sortedArr
      g = g / 2
      m += 1
      cnt += c
    }

    return (ret, gList, m, cnt)
  }
}
