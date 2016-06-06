package com.github.akito0107.scala.aoj16c

import scala.annotation.tailrec
import scala.collection.mutable.ArrayBuffer
import scala.io.StdIn

/**
 * Created by akito on 6/5/16.
 */
object Main {
  def main(args: Array[String]): Unit = {
    @tailrec
    def scan(n: Int, acc: ArrayBuffer[(String, Int)] = ArrayBuffer()): ArrayBuffer[(String, Int)] = n match {
      case 0 => acc
      case _ =>
        val str = io.StdIn.readLine().split(" ")
        val t = (str(0), str(1).toInt)
        scan(n - 1, acc += t)
    }
    val s = scan(io.StdIn.readLine().toInt).toList
    def quicksort(list: List[(String, Int)]): List[(String, Int)] = list match {
      case Nil => list
      case x :: xs =>
        val (smaller, larger) = xs.partition(p => p._2 < x._2)
        quicksort(smaller) ++ List(x) ++ quicksort(larger)
    }
    val res = quicksort(s)
    val sorted = s.sortBy(_._2)
    res.zip(sorted).filter(x => x._1._1 != x._2._1).size match {
      case 0 => println("Stable")
      case _ => println("Not Stable")
    }
    res.foreach(t => println(s"${t._1} ${t._2}"))
  }
}
