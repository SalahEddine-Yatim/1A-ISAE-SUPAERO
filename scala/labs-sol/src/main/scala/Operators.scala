object OperatorsApp extends App {
  // defining and and or operators
  def and(b1: Boolean, b2: Boolean): Boolean =
    if (b1) b2 else false

  def or(b1: Boolean, b2: Boolean): Boolean =
    if (b1) true else b2

  // testing
  print("-> testing and...")
  assert(and(true, true))
  assert(! and(false, true))
  assert(! and(true, false))
  assert(! and(false, false))
  println(" OK!")

  print("-> testing or...")
  assert(or(true, true))
  assert(or(false, true))
  assert(or(true, false))
  assert(! or(false, false))
  println(" OK!")

  // defining a "false boolean" to verify short circuit operators
  def shouldNotBeCalled = { assert(false); true }

  // does not work...
  // or(true, shouldNotBeCalled)

  // defining operators using call-by-name
  def andSS(b1: Boolean, b2: => Boolean): Boolean =
    if (b1) b2 else false

  def orSS(b1: Boolean, b2: => Boolean): Boolean =
    if (b1) true else b2

  // testing
  print("-> testing new and...")
  assert(andSS(true, true))
  assert(! andSS(false, shouldNotBeCalled))
  assert(! andSS(true, false))
  assert(! andSS(false, shouldNotBeCalled))
  println(" OK!")

  print("-> testing new or...")
  assert(orSS(true, shouldNotBeCalled))
  assert(orSS(false, true))
  assert(orSS(true, shouldNotBeCalled))
  assert(! orSS(false, false))
  println(" OK!")
}
