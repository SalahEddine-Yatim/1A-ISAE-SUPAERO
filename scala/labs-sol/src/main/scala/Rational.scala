class Rational(n: BigInt, d: BigInt) {

  import GCDApp._

  private val currentGcd =
    if (d > 0) gcd(n, d) else -gcd(n, d)

  val num = n / currentGcd
  val den = d / currentGcd

  override def toString =
    if (num == 0)
      "0"
    else if (den == 1)
      s"${num}"
    else s"${num}/${den}"

  def isTheSameAs(that: Rational) =
    (num == that.num) && (den == that.den)

  def +(that: Rational) =
    new Rational(num * that.den + that.num * den,
      den * that.den)

  def -(that: Rational) =
    new Rational(num * that.den - that.num * den,
      den * that.den)

  def *(that: Rational) =
    new Rational(num * that.num, den * that.den)

  def /(that: Rational) =
    new Rational(num * that.den, den * that.num)
}

object Rational {
  val zero = Rational(0)
  val one  = Rational(1)

  def apply(num: BigInt, den: BigInt) =
    new Rational(num, den)

  def apply(n: BigInt) =
    new Rational(n, 1)
}

object RationalApp extends App {
  import Rational._

  // creating rationals and printing them
  val i  = Rational(7)
  val r1 = Rational(7, -49)
  val r2 = Rational(2, 5)

  println(s"zero  = $zero")
  println(s"i     = $i")
  println(s"r1    = $r1")
  println(s"r2    = $r2")

  // verifying add
  print("-> verifying +...")
  assert((zero + i)  isTheSameAs i)
  assert((zero + r1) isTheSameAs r1)
  assert((i + r1)    isTheSameAs Rational(48, 7))
  assert((i + r2)    isTheSameAs Rational(37, 5))
  assert((r1 + r2)   isTheSameAs Rational(9, 35))
  assert((r1 + r2)   isTheSameAs (r2 + r1))
  println(" OK!")

  // verifying sub
  print("-> verifying -...")
  assert((zero - zero) isTheSameAs zero)
  assert((i - i)       isTheSameAs zero)
  assert((r1 - r1)     isTheSameAs zero)
  assert((r2 - r2)     isTheSameAs zero)
  assert((i - zero)    isTheSameAs i)
  assert((zero - i)    isTheSameAs Rational(- i.num, i.den))
  assert((r1 - zero)   isTheSameAs r1)
  assert((zero - r1)   isTheSameAs Rational(- r1.num, r1.den))
  assert((i - r1)      isTheSameAs Rational(50, 7))
  assert((r1 - i)      isTheSameAs Rational(-50, 7))
  assert((r1 - r2)     isTheSameAs Rational(-19, 35))
  assert((r2 - r1)     isTheSameAs Rational(19, 35))
  println(" OK!")

  // verifying mul
  print("-> verifying *...")
  assert((i * zero)  isTheSameAs zero)
  assert((zero * i)  isTheSameAs zero)
  assert((zero * r1) isTheSameAs zero)
  assert((zero * r2) isTheSameAs zero)
  assert((i * i)     isTheSameAs Rational(49))
  assert((i * r1)    isTheSameAs Rational(-1))
  assert((i * r2)    isTheSameAs Rational(14, 5))
  assert((r1 * r2)   isTheSameAs Rational(- 2, 35))
  assert((r1 * r2)   isTheSameAs (r2 * r1))
  println(" OK!")

  // verifying div
  print("-> verifying /...")
  assert((i / i)     isTheSameAs one)
  assert((r1 / r1)   isTheSameAs one)
  assert((r2 / r2)   isTheSameAs one)
  assert((zero / i)  isTheSameAs zero)
  assert((zero / r1) isTheSameAs zero)
  assert((zero / r2) isTheSameAs zero)
  assert((i / r1)    isTheSameAs Rational(-49))
  assert((i / r2)    isTheSameAs Rational(35, 2))
  assert((r1 / i)    isTheSameAs Rational(-1, 49))
  assert((r2 / i)    isTheSameAs Rational(2, 35))
  assert((r2 / r1)   isTheSameAs Rational(-14, 5))
  assert((r2 / r1)   isTheSameAs Rational(-14, 5))
  assert((r1 / r2)   isTheSameAs Rational(-5, 14))
  println(" OK!")
}
