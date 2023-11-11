class Point(val x: Double, val y: Double) {

  import math._

  val module = sqrt(x * x + y * y)

  override def toString() =
    s"($x, $y)"

  def translate(dx: Double, dy: Double) =
    new Point(x + dx, y + dy)

  def distance(that: Point) = {
    val dx = x - that.x
    val dy = y - that.y
    sqrt(dx * dx + dy * dy)
  }
}

object Point {
  val origin = new Point(0, 0)

  def apply(x: Double, y: Double) =
    new Point(x, y)
}

object PointApp extends App {
  import Point._

  // creating p1
  val p1 = new Point(1, 2)
  val p2 = new Point(2, 3)
  println(s"p1 abscissa: ${p1.x}")
  println(s"p2 ordinate: ${p2.y}")
  println(s"p1 module: ${p1.module}")

  // p1 is immutable!
  // p1.x = 3

  // printing p1
  println(p1.toString())
  println(s"p1: $p1")

  // translating p1: we obtain a NEW point p2!
  val p3 = p1.translate(2, 3)
  println(s"p3: $p3")

  // computing the distance between p1 and p2
  val d = p1.distance(p2)
  println(s"distance between p1 and p2: $d")

  // using companion object
  println(s"origin: ${origin}")
  val p4 = Point(5, 6)
  println(s"p4: $p4")
}
