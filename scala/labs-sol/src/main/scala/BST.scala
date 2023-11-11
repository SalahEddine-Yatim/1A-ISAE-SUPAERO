sealed abstract class BST {
  def insert(v: Int): BST
  def contains(v: Int): Boolean
  override def equals(that: Any): Boolean
}

object EmptyBST extends BST {
  def insert(v: Int): BST =
    NodeBST(v, EmptyBST, EmptyBST)

  def contains(v: Int): Boolean =
    false

  override def equals(that: Any) = that match {
    case that:BST if that.eq(EmptyBST) => true
    case _                             => false
  }
}

class NodeBST(val value: Int, val left: BST, val right: BST) extends BST {
  def insert(v: Int): BST =
    if (v == value)
      this
    else if (v < value)
      NodeBST(value, left.insert(v), right)
    else
      NodeBST(value, left, right.insert(v))

  def contains(v: Int): Boolean =
    if (v == value)
      true
    else if (v < value)
      left.contains(v)
    else
      right.contains(v)

  override def equals(that: Any) = that match {
    case that:NodeBST if value != that.value => false
    case that:NodeBST if value == that.value =>
      left.equals(that.left) && right.equals(that.right)
    case _ => false
  }
}

object NodeBST {
  def apply(value: Int, left: BST, right: BST) =
    new NodeBST(value, left, right)
}

object BSTApp extends App {
  import NodeBST._

  // defining some BST
  val bst1 = NodeBST(2, EmptyBST, EmptyBST)
  val bst2 = NodeBST(15,
    NodeBST(-2, NodeBST(-5, EmptyBST, EmptyBST), NodeBST(3, EmptyBST, EmptyBST)),
    NodeBST(40, NodeBST(20, EmptyBST, EmptyBST), NodeBST(50, EmptyBST, EmptyBST))
  )

  // testing equals
  print("testing equals...")
  assert(EmptyBST == EmptyBST)
  assert(! (EmptyBST == bst1))
  assert(! (EmptyBST == bst2))
  assert(bst1 == bst1)
  assert(bst1 == NodeBST(2, EmptyBST, EmptyBST))
  assert(! (bst1 == EmptyBST))
  assert(! (bst1 == bst2))
  assert(! (bst1 == NodeBST(1, EmptyBST, EmptyBST)))
  assert(! (bst1 == NodeBST(2, NodeBST(1, EmptyBST, EmptyBST), EmptyBST)))
  assert(bst2 == bst2)
  assert(! (bst2 == EmptyBST))
  assert(! (bst2 == bst1))
  println(" OK")

  // testing contains
  print("testing contains...")
  assert(! EmptyBST.contains(0))
  assert(! EmptyBST.contains(1))
  assert(bst1.contains(2))
  assert(! bst1.contains(0))
  assert(bst2.contains(-2))
  assert(bst2.contains(-5))
  assert(bst2.contains(3))
  assert(bst2.contains(40))
  assert(bst2.contains(20))
  assert(bst2.contains(50))
  println(" OK")

  // testing insert
  print("testing insert...")
  assert(EmptyBST.insert(1).contains(1))
  assert(EmptyBST.insert(-1).contains(-1))
  assert(bst1.insert(1).contains(1))
  assert(bst1.insert(2).contains(2))
  assert(bst1.insert(3).contains(3))
  assert(bst2.insert(1).contains(1))
  assert(bst2.insert(100).contains(100))
  assert(bst2.insert(-100).contains(-100))
  println(" OK")
}
