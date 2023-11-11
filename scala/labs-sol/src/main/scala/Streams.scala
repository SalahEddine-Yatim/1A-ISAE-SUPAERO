object StreamsApp extends App {
  // trying streams
  def loop: Int = loop
  def s: LazyList[Int] =
    1 #:: 2 #:: loop #:: 3 #:: LazyList.empty

  // s.exists( _ % 2 == 0)
  // s.exists( _ % 3 == 0)

  // from
  def from(n: BigInt): LazyList[BigInt] =
    n #:: from(n + 1)

  // infinite sequence of 2, 3, 4
  def infSeqI: LazyList[Int] =
    2 #:: 3 #:: 4 #:: infSeqI

  infSeqI(44)
  infSeqI.take(10)

  def infSeqB: LazyList[Boolean] =
    true #:: false #:: infSeqB

  (infSeqI zip infSeqB).take(12).toList
  (infSeqI zip infSeqB).map(
    x => if (x._2) -x._1 else x._1 ).take(10).toList

  def l = List('a', 'b', 'c', 'd', 'e')
  infSeqI zip l
  l zip infSeqI

  // Eratosthene's sieve
  def sieve(s: LazyList[BigInt]): LazyList[BigInt] =
    s.head #:: sieve(s.tail filter (_ % s.head != 0))

  // Viete's series
  def prodFrom(p: Double, d: Double): LazyList[Double] = {
    val den = math.sqrt(2 + d)
    val prod = p * (2 / den)
    prod #:: prodFrom(prod, den)
  }

  val pi = prodFrom(2.0, 0.0)

  def stop(s: LazyList[Double], prev: Option[Double], eps: Double): LazyList[Double] =
    prev match {
      case None     =>
        s.head #:: stop(s.tail, Some(s.head), eps)
      case Some(d)  =>
        if (math.abs(s.head - d) < eps)
          LazyList.empty
        else
          s.head #:: stop(s.tail, Some(s.head), eps)
    }
}
