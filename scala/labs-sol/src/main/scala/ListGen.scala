sealed abstract class ListGen[A] {
  def head: A
  def tail: ListGen[A]
  def headOption: Option[A]
  def tailOption: Option[ListGen[A]]
  def isEmpty: Boolean
  def isDefined: Boolean = ! this.isEmpty
  def size: Int
}

case class Nil[A]() extends ListGen[A] {
  def head = throw new NoSuchElementException
  def tail = throw new NoSuchElementException
  def headOption = None
  def tailOption = None
  def isEmpty = true
  def size = 0
}

case class Cons[A](val head: A, val tail: ListGen[A]) extends ListGen[A] {
  def headOption = Some(head)
  def tailOption = Some(tail)
  def isEmpty = false
  def size = 1 + tail.size
}

object ListGenApp extends App {
  val nilS = Nil[String]()
  val l1 = Cons[String]("hello", Cons[String]("world", nilS))
  val l2 = Cons(1, Cons(2, Nil[Int]()))

  // deconstructing using Cons
  val Cons(h, t) = l2
  println(s"$h, $t")

  def getHeadDefault[A](l: ListGen[A], default: A): A =
    if (l.isDefined) l.head else default

  def getHeadDefaultAlt[A](l: ListGen[A], default: A): A =
    l.headOption.getOrElse(default)

  // val lWrong = Cons(1, nilS)

  // val nil = Nil()
  // val l3 = Cons(Some(2), nil)

}
