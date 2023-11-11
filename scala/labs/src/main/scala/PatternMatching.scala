object PatternMatchingApp extends App {
  import scala.util.Random._

  val x = nextInt(10)

  val s = x match {
    case 0 => "zero"
    case 1 => "one"
    case 2 => "two"
    case _ => "many"
  }
  println(s)
  println()

  import ListIntApp._

  def fooType(x: Any) = x match {
    case x:Int     => "this is an integer!"
    case x:String  => "this is a string!"
    case x:ListInt => "this is a list!"
    case _         => "this is something else..."
  }

  println(fooType(1))
  println(fooType("hello"))
  println(fooType(NilInt))
  println(fooType(ConsInt(1, NilInt)))
  println(fooType(2.3))
  println()

  def fooTypeCond(x: Any) = x match {
    case x:ListInt if x.size == 2 => "this is a list of size 2!"
    case x:ListInt                => "this is a list!"
    case _                        => "this is something else..."
  }

  println(fooTypeCond(NilInt))
  println(fooTypeCond(ConsInt(1, NilInt)))
  println(fooTypeCond(ConsInt(1, ConsInt(2, NilInt))))
  println()

  // testing lists as case classes
  // remove comments when NilInt and ConsInt are case classes!
  val l1  = ConsInt(1, NilInt)
  val l2  = ConsInt(2, ConsInt(1, NilInt))

  def snoc(l:ListInt , element: Int) : ListInt = l match {
    case NilInt => ConsInt(element, NilInt)
    case ConsInt(h, t) => ConsInt(h,snoc(t,element))

  }

  def reverse(l:ListInt) : ListInt = l match {
    case NilInt => NilInt
    case ConsInt(h, t) => snoc(reverse(t),h)
  }

  val ConsInt(h2, t2) = l2
  println(s"head of l2: $h2")
  println(s"tail of l2: $t2")

  val ConsInt(h1, _) = l1
  println(s"head of l1: $h1")

  def foo(l: ListInt) = l match {
    case NilInt        => "Empty list..."
    case ConsInt(1, _) => "List starting with 1"
    case ConsInt(_, t) => s"List finishing with $t"
  }

  println(s"foo(l1) = ${foo(l1)}")
  println(s"foo(l2) = ${foo(l2)}")
  println()

  // snoc
  println(s"snoc(l1, 2) = ${snoc(l1, 2)}")
  println(s"snoc(l2, 6) = ${snoc(l2, 6)}")
  println()

  // // reverse
  println(s"reverse(NilInt) = ${reverse(NilInt)}")
  println(s"reverse(l1) = ${reverse(l1)}")
  println(s"reverse(l2) = ${reverse(l2)}")
}
