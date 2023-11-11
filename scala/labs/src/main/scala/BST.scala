sealed abstract class BST{

    def insert(value: Int): BST
    def contains(value:Int): Boolean
    override def equals(other: Any): Boolean

}

object EmptyBST extends BST {
    def insert(value: Int): BST = 
        new NodeBST(value, EmptyBST , EmptyBST)

    def contains(value: Int): Boolean = false

    override def equals(other: Any): Boolean = other match {
        case other: EmptyBST.type => true 
        case _                    => false 
    }
    
    
// //On peut utilser les fonction par defaut 
// case object NilInt extends ListInt {
// ...
// }
// case class ConsInt(head: Int, tail: ListInt) extends ListInt {
// ...
// }

// It also:
// adds default methods for ==, hashCode, toString, copy
// creates a default companion object with an apply method allowing
// to create Cons objects without new


}

class NodeBST(val value: Int , val left:BST , val right: BST) extends BST {
    
    def insert(v: Int): BST = 
        if (v == value)
            this 
        else if (v == value)
            NodeBST (value, left.insert(v) , right)
        else
            NodeBST (value , left ,right.insert(v))
            


    def contains(v: Int): Boolean =  
        if (v == value)
            true
        else if (v < value)
            left.contains(v)
        else 
            right.contains(v)

    override def equals(other: Any): Boolean = other match {

        //NodeBST est une arrbre nnon vide 
        case other: NodeBST if value == other.value =>
            left.equals(other.left) && right.equals(other.right)
        case _ => false 

    }
}

object NodeBST {

    def apply(value: Int ,left: BST, right: BST) =
        new NodeBST(value , left , right)
}

object BSTApp extends App {
    //Ajouter des test
}


