package com.github.akito0107.aoj15b

import scala.annotation.tailrec

/**
 * Created by akito on 6/5/16.
 */
object Main {
  def main(args: Array[String]): Unit = {
    val (n, s) = (io.StdIn.readLine().toInt, io.StdIn.readLine().split(' ').map(_.toInt).toList)

    var cnt = 0
    @tailrec
    def merge(left: List[Int], right: List[Int], acc: List[Int] = List()): List[Int] = (left, right) match {
      case (Nil, _) => acc ++ right
      case (_, Nil) => acc ++ left
      case (x :: xs, y :: ys) if x <= y => merge(xs, right, acc :+ x)
      case (x :: xs, y :: ys) if x > y => merge(left, ys, acc :+ y)
    }

    def mergeStream(ls: Stream[Int], rs: Stream[Int]): Stream[Int] = (ls, rs) match {
      case (Stream.Empty, _) => rs
      case (_, Stream.Empty) => ls
      case (l #:: lsx, r #:: rsx) if l <= r => l +: mergeStream(lsx, rs)
      case (l #:: lsx, r #:: rsx) if l > r => r +: mergeStream(ls, rsx)
    }

    def mergeSort(list: List[Int]): List[Int] = list match {
      case x :: Nil => list
      case _ =>
        val (l1, l2) = list.splitAt(list.size / 2)
        cnt += l1.size + l2.size
        merge(mergeSort(l1), mergeSort(l2))
    }
    println(mergeSort(s).mkString(" "))
    println(cnt)
  }
}
