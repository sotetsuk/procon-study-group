import scala.io.StdIn

object Main {
  def main(args: Array[String]) {
    val arr: Array[String] = StdIn.readLine().split(" ")
    val stack: MyStack = new MyStack(1000)
    for(v <- arr) {
      calc(stack, v)
    }
    println(stack.pop())
  }

  def calc(stack: MyStack, v: String): Unit = {
    if(v != "+" && v != "-" && v != "*") {
      stack.push(v)
      return
    }

    val y = stack.pop.toInt
    val x = stack.pop.toInt

    if(v == "+") {
      stack.push((x + y).toString)
    } else if(v == "-") {
      stack.push((x - y).toString)
    } else {
      stack.push((x * y).toString)
    }
  }
}

class MyStack(n: Int) {
  val arr: Array[String] = Array.fill(n)("")
  var p = 0

  def pop(): String = {
    p -= 1
    val ret = arr(p)
    arr(p) = ""
    return ret
  }

  def push(v: String): Unit = {
    arr(p) = v
    p += 1
  }
}
