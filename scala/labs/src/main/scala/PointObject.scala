object PointObjectApp extends App {
  // building a point object
  object p1 {
    val x = 1
    val y = 2
    val module = math.sqrt(x * x + y * y)

    override def toString() =
      s"($x, $y)"
  }

  println(s"p1 abscissa: ${p1.x}")
  println(s"p1 module: ${p1.module}")
  println(s"p1: ${p1.toString()}")
  println(s"p1: $p1")

  // building a new point...
  object p2 {
    val x = 2
    val y = 3
    val module = math.sqrt(x * x + y * y)

    override def toString() =
      s"($x, $y)"
  }
}
