object FactorialApp extends App {
  def time(body: => BigInt): (BigInt, Double) = {
    val startTime = System.nanoTime()
    (body, (System.nanoTime() - startTime) / 1000)
  }

  // recursive version of factorial
  def factorial(n: BigInt): BigInt =
    if (n == 0) 1 else n * factorial(n - 1)

  // simple tests for factorial
  print("-> testing factorial...")
  assert(factorial(0) == 1)
  assert(factorial(1) == 1)
  assert(factorial(2) == 2)
  assert(factorial(3) == 6)
  assert(factorial(4) == 24)
  assert(factorial(5) == 120)
  println(" OK!")

  // tail-recursive version of factorial
  def factorialTR(n: BigInt): BigInt = {
    @scala.annotation.tailrec
    def factorialAux(n: BigInt, acc: BigInt): BigInt =
      if (n == 0) acc else factorialAux(n - 1, n * acc)

    factorialAux(n, 1)
  }

  // simple tests for tail-recursive factorial
  print("-> testing tail-recursive factorial...")
  assert(factorialTR(0) == 1)
  assert(factorialTR(1) == 1)
  assert(factorialTR(2) == 2)
  assert(factorialTR(3) == 6)
  assert(factorialTR(4) == 24)
  assert(factorialTR(5) == 120)
  println(" OK!")

  // testing both methods with huge values
  // println("10000! = " + factorial(10000))
  println("10000! (with TR) = " + factorialTR(10000))

  // comparing execution times for n = 1000
  println("-> comparing execution times")
  println(s"execution time for 1000! (classic): ${time(factorial(1000))._2} ms")
  println(s"execution time for 1000! (TR): ${time(factorialTR(1000))._2} ms")
}
