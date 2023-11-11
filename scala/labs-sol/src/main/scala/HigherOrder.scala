object HigherOrderApp extends App {
  import FunctionsEx._

  // some examples to be copied in the console
  (1 to 10).map((x) => x * x).toList
  (1 to 5).map( (x: Int) => x.toString ).map(f1).toList
  (1 to 5).map( x => x.toString ).map(f1).toList
  (1 to 5).map(_.toString).map(f1).toList

  (1 to 5).map(_.toString).map(f1).foldLeft("z")(f5)
  (1 to 5).map(_.toString).map(f1).foldRight("z")(f5)

  // reverse a list
  def reverse(l: List[Int]): List[Int] =
    l.foldLeft(List[Int]())( (x, y) => y :: x )

  // arithmetics
  def largestInteger = (100000 until (0, -1)).filter( _ % 3829 == 0 ).head

  def sumOddSquares = (1 to 10000).map(x => x * x).filter( _ % 2 == 1 ).sum

  @scala.annotation.tailrec
  def collatz(n: Int): Int =
    if (n == 1)
      1
    else if (n % 2 == 0)
      collatz(n / 2)
    else
      collatz(n * 3 + 1)

  def collatzConj = (1 to 1000).map(collatz).map(x => x == 1).foldRight(true) ((x, y) => x && y)
  def collatzConjForall = (1 to 1000).forall(x => collatz(x) == 1)

  // strings
  import FactorialApp._

  def factStr = factorial(1000).toString

  def numZeroFact = factStr.count( _ == '0' )

  def iLoveScala = List("i", "love", "scala").map((x) => x.toUpperCase ++ " ").foldRight("") ((x, y) => x ++ y)

  def countSequence(sub: String): (String => Int) =
    (s: String) => s.sliding(sub.size).count(s => s == sub)

  def countSeq123Fact = countSequence("123")(factStr)

  def indexSequence(sub: String): (String => List[Int]) =
    (s: String) => s.sliding(sub.size).zipWithIndex.filter( { case (s, i) => s == sub } ).toList.unzip._2

  def indexSeq123Fact = indexSequence("123")(factStr)
}
