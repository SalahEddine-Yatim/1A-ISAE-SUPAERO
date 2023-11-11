import org.scalacheck.Properties
import org.scalacheck.Prop.{forAll, BooleanOperators}
import GCDApp._

object GCDSpecification extends Properties("GCD") {
  def reflexivity(x: BigInt) =
    if (x >= 0) gcd(x, x) == x else gcd(x, x) == -x

  property("reflexivity") = forAll { reflexivity(_) }

  def symmetry(x: BigInt, y: BigInt) =
    gcd(x, y) == gcd(y, x)

  property("symmetry") = forAll { symmetry(_, _) }

  def substract(x: BigInt, y: BigInt) =
    (x <= y) ==> (gcd(x, y) == gcd(x, y - x))

  property("substract") = forAll { substract(_, _) }
}
