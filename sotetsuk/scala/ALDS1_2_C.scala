import java.util.Scanner

object Main {
  def main(args: Array[String]) {
    val sc = new Scanner(System.in)
    val N = sc.nextInt()
    val arr: Array[String] = Array.fill(N)(sc.next())
    val arrBubble: Array[String] = arr.clone()
    val arrSelect: Array[String] = arr.clone()

    println(bubbleSort(arrBubble))
    checkStable(arr, arrBubble)
    println(selectionSort(arrSelect))
    checkStable(arr, arrSelect)
  }

  def bubbleSort(arr: Array[String]): String = {
    for(i <- 0 until arr.length) {
      for(j <- arr.length-1 until i by -1) {
        if(arr(j).last.toInt < arr(j-1).last.toInt) {
          val t = arr(j); arr(j) = arr(j-1); arr(j-1) = t  // swap
        }
      }
    }
    return arr.mkString(" ")
  }

  def selectionSort(arr: Array[String]): String = {
    for((x, i) <- arr.zipWithIndex) {
      var minj = i
      for(j <- i until arr.length) {
        if(arr(minj).last.toInt > arr(j).last.toInt) minj = j
      }
      val t = arr(i); arr(i) = arr(minj); arr(minj) = t
    }
    return arr.mkString(" ")
  }

  def checkStable(arrOrigin: Array[String], arrSorted: Array[String]): Unit = {
    for((a, i) <- arrOrigin.zipWithIndex) {
      for((b, j) <- arrOrigin.zipWithIndex if i != j && a.last.toInt == b.last.toInt) {
        for((c, k) <- arrSorted.zipWithIndex if a == c) {
          for((d, l) <- arrSorted.zipWithIndex if b == d) {
            if((i - j) * (k - l) < 0) {
              println("Not stable")
              return
            }
          }
        }
      }
    }
    println("Stable")
  }
}