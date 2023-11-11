object EitherApp extends App {
  def sqrt(x: Double): Either[String, Double] = ???

  def printSqrt(a: Double, b: Double, c: Double) = {
    println(for {
      x <- sqrt(a)
      y <- sqrt(b)
      z <- sqrt(c)
    } yield (x, y, z))
  }

  printSqrt( 1.0,  2.0,  3.0)
  printSqrt(-1.0,  2.0,  3.0)
  printSqrt( 1.0, -2.0,  3.0)
  printSqrt( 1.0, -2.0, -3.0)
}
