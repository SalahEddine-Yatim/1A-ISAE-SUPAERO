object FunctionsEx {
  val f1  = (x: String) => s"f1($x)"
  val f2  = (x: String) => s"f2($x)"
  val f3  = (x: String) => (f1(x), f2(x))
  val f4  = (x: (String, String)) => s"f4(${x._1}, ${x._2})"
  val f5  = (x: String, y: String) => s"f5($x, $y)"
  val f5t = f5.tupled
  val f5c = f5.curried
  val f6  = (x: String) => { (y: String, z: String) => s"f7($x, $y, $z)" }
  val f7  =
    (f: String => String, x: String) => (f andThen f)(x)

  // examples from the slides

  // f1
  // f1("x")

  // f1 andThen f2
  // (f1 andThen f2)("x")
  // f1 compose f2
  // (f1 compose f2)("x")

  // f3("x")
  // f3 andThen f3
  // f3 andThen f4
  // (f3 andThen f4)("x")
  // f4 andThen f3
  // (f4 andThen f3)("x", "y")

  // f3 andThen f5
  // f3 andThen f5.tupled
  // (f3 andThen f5.tupled)("x")

  // f5c
  // f5c("x")
  // f5c("x")("y")
  // f1 andThen f5c
  // (f1 andThen f5c)("x")
  // (f1 andThen f5c)("x")("y")
  // (f1 andThen f5c("x"))("y")

  // f1 andThen (f6("x").curried)
  // (f1 andThen (f6("x").curried))("y")("z")

  // f7(f1, "x")
  // f7((s: String) => s + s, "x")


  // methods
  def m1(x: String, y: String) = s"m1($x, $y)"
  def m2(x: String) = s"m2($x)"
  def m3(f: String => String, x: String) = (f andThen f)(x)
  def m4(x:String): ((String => String) => String) = m3(_, x)

  // examples

  // val mf1 = m1
  // val mf2 = m1(_, _)
  // val mf3: String => String = m1("x", _)
  // m3(m2, "x")
}
