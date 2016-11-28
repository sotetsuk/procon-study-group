package com.github.akito0107.aoj15c

import scala.annotation.tailrec

/**
 * Created by akito on 6/5/16.
 */
object Main {
  def main(args: Array[String]): Unit = {
    val n = io.StdIn.readLine().toInt

    def calc(p: ((Double, Double), (Double, Double))) = {
      val (p1, p2) = (p._1, p._2)
      val s = ((2 * p1._1 + p2._1) / 3, (2 * p1._2 + p2._2) / 3)
      val t = ((p1._1 + 2 * p2._1) / 3, (p1._2 + 2 * p2._2) / 3)
      val u = (s._1 + (t._1 - s._1) * Math.cos(Math.toRadians(60)) - (t._2 - s._2) * Math.sin(Math.toRadians(60)),
        s._2 + (t._1 - s._1) * Math.sin(Math.toRadians(60)) + (t._2 - s._2) * Math.cos(Math.toRadians(60)))
      Seq((p1, s), (s, u), (u, t), (t, p2))
    }

    @tailrec
    def kochCurve(n: Int, acc: Seq[((Double, Double), (Double, Double))]): Unit = n match {
      case 0 => acc.map(p => Seq(p._1, p._2)).flatten.distinct.foreach(t => println(s"${t._1} ${t._2}"))
      case _ => kochCurve(n - 1, acc.map(calc).flatten)
    }
    kochCurve(n, Seq(((0.0, 0.0), (100.0, 0.0))))
  }
}
