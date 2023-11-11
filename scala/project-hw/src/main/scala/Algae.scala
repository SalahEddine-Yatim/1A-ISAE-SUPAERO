object Algae extends LSystem {

  abstract class Letter
  case object A extends Letter
  case object B extends Letter

  def axiom = List(A)

  def rewrite(w: Word): Word = {
    w flatMap {
      case A => List(A, B)
      case B => List(A)
    }
  }

}



object AlgaeApp extends App {
  // print each step from 1 to 5 for Algae
  Algae.show(5)
}
