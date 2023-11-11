import org.scalacheck.Gen
import org.scalacheck.Properties
import org.scalacheck.Prop.{forAll, BooleanOperators}
import Rational._

object RationalSpecification extends Properties("Rational") {
  val myRationalGen = for {
    n <- Gen.choose(-100, 100)
    d <- Gen.choose(-100, 100) suchThat (_ != 0)
  } yield Rational(n, d)

  property("add commutativity") =
    forAll(myRationalGen, myRationalGen) {
      (r1, r2) => (r1 + r2).isTheSameAs(r2 + r1)
    }

  property("add neutral") =
    forAll(myRationalGen) {
      (r) => (r + zero).isTheSameAs(r)
    }

  property("min zero") =
    forAll(myRationalGen) {
      (r) => (r - r).isTheSameAs(zero)
    }

  property("mul commutativity") =
    forAll(myRationalGen, myRationalGen) {
      (r1, r2) => (r1 * r2).isTheSameAs(r2 * r1)
    }

  property("mul neutral") =
    forAll(myRationalGen) {
      (r) => (r * one).isTheSameAs(r)
    }

  property("mul abs") =
    forAll(myRationalGen) {
      (r) => (r * zero).isTheSameAs(zero)
    }

  property("div neutral") =
    forAll(myRationalGen) {
      (r) => (r / one).isTheSameAs(r)
    }

  property("div own equals one") =
    forAll(myRationalGen) {
      (r) => (r / r).isTheSameAs(one)
    }
}
