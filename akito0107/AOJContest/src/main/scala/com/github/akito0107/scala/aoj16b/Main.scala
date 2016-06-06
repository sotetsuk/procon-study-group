package com.github.akito0107.scala.aoj16b

import scala.annotation.tailrec

/**
 * Created by akito on 6/5/16.
 */
object Main {
  def main(args: Array[String]): Unit = {
    val (n, s) = (io.StdIn.readLine().toInt, io.StdIn.readLine().split(' ').map(_.toInt).toStream)

    @tailrec
    def partition(r: Int, list: Stream[Int], acc: (Stream[Int], Stream[Int]) = (Stream(), Stream())): (Stream[Int], Stream[Int]) = list match {
      case Stream() => acc
      case x #:: list if x < r => partition(r, list, (acc._1 :+ x, acc._2))
      case x #:: list if x >= r => partition(r, list, (acc._1, acc._2 :+ x))
    }
    val (last, list) = (s.last, s.init)
    // val (smaller, larger) = partition(last, list)
    val (smaller, larger) = list.partition( i => i < last)
    println(s"${smaller.mkString(" ")} [${last}] ${larger.mkString(" ")}")
  }
}
