object OperatorsApp extends App {
  // defining and and or operators
  def and(b1: Boolean, b2: => Boolean): Boolean =  if (!b1) false else b2

  def or(b1: Boolean, b2: => Boolean): Boolean =  if (b1) true else (b2)

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
}
