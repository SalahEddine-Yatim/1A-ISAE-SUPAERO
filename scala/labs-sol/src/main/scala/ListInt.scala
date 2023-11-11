sealed abstract class ListInt {
  def head: Int
  def tail: ListInt
  def isEmpty: Boolean
  def size: Int
  def isTheSameAs(that: ListInt): Boolean
}

case object NilInt extends ListInt {
  def head = ???
  def tail = ???
  def isEmpty = true
  def size = 0
  def isTheSameAs(that: ListInt) = (that == NilInt)
}

case class ConsInt(val head: Int, val tail: ListInt) extends ListInt {
  def isEmpty = false

  def size = 1 + tail.size

  def isTheSameAs(that: ListInt) =
    if (that == NilInt || head != that.head)
      false
    else tail.isTheSameAs(that.tail)
}

object ListIntApp extends App {
  val l1  = ConsInt(1, NilInt)
  val l2  = ConsInt(2, ConsInt(1, NilInt))
  val l   = ConsInt(42, ConsInt(1, ConsInt(17, NilInt)))

  // testing isEmpty
  print("-> testing isEmpty...")
  assert(NilInt.isEmpty)
  assert(! l1.isEmpty)
  assert(! l2.isEmpty)
  assert(! l.isEmpty)
  println(" OK!")

  // testing isTheSameAs
  print("-> testing isTheSameAs...")
  assert(NilInt isTheSameAs NilInt)
  assert(l1     isTheSameAs l1)
  assert(l2     isTheSameAs l2)
  assert(l      isTheSameAs l)
  assert(l1     isTheSameAs ConsInt(1, NilInt))
  assert(l2     isTheSameAs ConsInt(2, ConsInt(1,NilInt)))
  assert(l      isTheSameAs ConsInt(42, ConsInt(1, ConsInt(17,NilInt))))
  assert(!( NilInt isTheSameAs l1))
  assert(!( NilInt isTheSameAs l2))
  assert(!( NilInt isTheSameAs l))
  assert(!( l1  isTheSameAs NilInt))
  assert(!( l1  isTheSameAs l2))
  assert(!( l1  isTheSameAs l))
  assert(!( l   isTheSameAs NilInt))
  assert(!( l   isTheSameAs l1))
  assert(!( l   isTheSameAs l2))
  println(" OK!")

  // testing head
  print("-> testing head...")
  assert(l1.head == 1)
  assert(l2.head == 2)
  assert(l.head  == 42)
  println(" OK!")

  // testing tail
  print("-> testing tail...")
  assert(l1.tail isTheSameAs NilInt)
  assert(l2.tail isTheSameAs l1)
  assert(l.tail  isTheSameAs ConsInt(1, ConsInt(17, NilInt)))
  println(" OK!")

  // testing size
  print("-> testing size...")
  assert(NilInt.size == 0)
  assert(l1.size     == 1)
  assert(l2.size     == 2)
  assert(l.size      == 3)
  println(" OK!")
}
