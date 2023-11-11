object EvaluationApp extends App {
  // basic literals
  println("-> Basic literals and expressions")
  println(2 + 2)
  println(3.14 * 4)
  println(true)
  println(s"2 + 2 = ${2 + 2}")

  // using def
  println("\n-> Using def to define methods")
  def pi = 3.14
  def radius = 10

  println(s"2 * pi * radius = ${(2 * pi) * radius}")

  // cannot redefine!
  // def radius = 20

  // using def with parameters
  def square(x: Double) = x * x
  def sumOfSquares(x: Double, y: Double) =
    square(x) + square(y)

  println(s"sumOfSquares(3, 2 + 2) = ${sumOfSquares(3, 2 + 2)}")

  // val
  println("\n-> Using val to define values")
  val x = 2 + 3
  val y = square(x)

  println(s"x = $x, y = $y")

  def expr = {
    val x = { print("x"); 1}
    lazy val y = { print("y"); 2}
    def z = { print("z"); 3}
    z + y + x + z + y + x
  }

  println(s"\nexpr = $expr")

  // println(s"sumOfSquares = $sumOfSquares")

  val sumOfSquaresVal = sumOfSquares(_, _)

  println(s"what is sumOfSquaresVal(3, 4): ${sumOfSquaresVal(3, 4)}")
  println(s"what is sumOfSquaresVal: ${sumOfSquaresVal}")

  // call-by-name parameters
  println("\n-> Using call-by-name parameters")
  def loop: Int = loop

  def itWillNotWork(v : Int, b: Int) = v

  def itWillWork(v : Int, b: => Int) = v

  itWillWork(4, loop)
  // itWillNotWork(4, loop)
}
