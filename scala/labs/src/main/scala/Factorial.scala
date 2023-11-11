object FactorialApp extends App {

  def time(body: => BigInt): (BigInt, Double) = {
    val startTime = System.nanoTime()
    (body, (System.nanoTime() - startTime) / 1000)
  }

  // recursive version of factorial
  def factorial(n: BigInt): BigInt = if (n == 0) 1 else n*factorial(n-1)


  // simple tests for factorial
  print("-> testing factorial...")
  assert(factorial(0) == 1)
  assert(factorial(1) == 1)
  assert(factorial(2) == 2)
  assert(factorial(3) == 6)
  assert(factorial(4) == 24)
  assert(factorial(5) == 120)
  println(" OK!")

  println(time(factorial(100))._2)


  // tail-recursive version of factorial
  
  def factorialTR(n: BigInt): BigInt = 
    {
      @scala.annotation.tailrec
      def factorialaux(m : BigInt , acc : BigInt) : BigInt =
        if (m==0) 
          acc
        else
          factorialaux(m-1 , m*acc)
        
      factorialaux(n , 1)

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

  println(time(factorialTR(100))._2)

}
