object OptionApp extends App {
  def add(a: Option[Int], b: Option[Int]): Option[Int] = {
    (a, b) match {
      case (None, _) => None
      case (_, None) => None
      case (Some(x), Some(y)) => Some(x + y)
    }
  }

  val x1 = Some(1)
  val x2 = Some(2)

  assert(add(x1, x2) equals Some(3))
  println(s"Some(1) + Some(2) = ${add(x1, x2)}")

  assert(add(x1, None) equals None)
  println(s"Some(1) + None    = ${add(x1, None)}")

  assert(add(None, x2) equals None)
  println(s"None    + Some(2) = ${add(None, x2)}")
}
