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
  def reverse(l: List[Int]): List[Int] = ???

  // arithmetics
  def largestInteger = ???//Voir worksheet

  def sumOddSquares = ???//VoirWorksheet

  def collatz(n: Int): Int = 
    if (n == 1)
      1
      else if (n %2 ==0)
        collatz(n / 2)
      else
        collatz(3 * n + 1)

  println(collatz(123456789))

  def collatzConj = (1 to 1000).forall( elt => collatz(elt) == 1)

  println(collatzConj)

  // strings
  import FactorialApp._

  def factStr = factorial(1000).toString

  def numZeroFact = factStr.count( x => x == '0')
  
  def iLoveScala = println(List("i", "love", "scala")
    .map( (s => s.toUpperCase))
    .foldRight("") ( (s , acc) => s++ " " ++ acc))

  iLoveScala

  def countSequence(sub: String): (String => Int) = 
    (s:String) => s.sliding(sub.size).count(elt => elt ==sub)

  def countSeq123Fact = countSequence("123")(factStr)

  println(countSeq123Fact)
  
  def indexSequence(sub: String): (String => List[Int]) = 
    (s : String) => s.sliding(sub.size).zipWithIndex.filter(elt => elt._1 == sub ).toList.unzip._2

  def indexSeq123Fact = indexSequence("123")(factStr)

  println(indexSeq123Fact)
}
