object EvaluationApp extends App {
  // basic literals
  println("-> Basic literals and expressions")
  // using def
  println("\n-> Using def to define methods")

  // val
  println("\n-> Using val to define values")

  // call-by-name parameters
  println("\n-> Using call-by-name parameters")

  println(2 + 2)

  println(s"2+2=${2+2}")

  def pi: Double = 3.14 

  def radius : Double = 5 

  println(2*radius*pi)

  def square(x: Double): Double = x * x
   
  def sumOfSquares(x: Double, y: Double): Double = square(x) + square(y)
 
  println(s"sumOfSquares(3, 2 + 2) = ${sumOfSquares(3, 2 + 2)}")

  def expr = {
    val x = { print("x"); 1}
    lazy val y = { print("y"); 2}
    def z = { print("z"); 3}
    z + y + x + z + y + x
  }
  println(s"\nexpr = $expr")

  def loop: Int = loop
  def itWillNotWork(v : Int, b: Int) = v
  def itWillWork(v : Int, b: => Int) = v
  itWillWork(4, loop)
  //itWillNotWork(4, loop)

}

