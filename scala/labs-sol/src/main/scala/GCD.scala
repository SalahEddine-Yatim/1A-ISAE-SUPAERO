object GCDApp extends App {
  // define gcd
  @scala.annotation.tailrec
  def gcd(x: BigInt, y: BigInt): BigInt =
    if (x < 0)
      gcd(-x, y)
    else if (y < 0)
      gcd(x, -y)
    else if (x == 0)
      y
    else
      gcd(y % x, x)

  // testing GCD
  print("-> testing gcd on some values...")
  assert(gcd(12, 4) == 4)
  assert(gcd(-4, 12) == 4)
  assert(gcd(10, 10) == 10)
  assert(gcd(5, 6) == 1)
  assert(gcd(20, -5) == 5)
  println(" OK!")
}
