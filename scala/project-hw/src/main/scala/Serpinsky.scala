// imports for LSystem implementation
import doodle.syntax.all._
import doodle.turtle.Instruction._

object Serpinsky extends LSystemTurtle {

  abstract class Letter
  case object F extends Letter
  case object G extends Letter
  case object - extends Letter //Lettre -
  case object + extends Letter //Lettre +


  def axiom = List(F,-,G,-,G)

  def rewrite(w: Word) : Word = {
     w flatMap {
      case G     => List(G, G)
      case F     => List(F,-,G,+,F,+,G,-,F)
      case other => List(other)
    }
  }

  def compile(w: Word) = {
     w flatMap {
      case G => List(forward(10))
      case F => List(forward(10))
      case + => List(turn(120.degrees))
      case - => List(turn((-120).degrees))
    }
  }

}

object SerpinskyApp extends App {
  Serpinsky.toImage(5, "Serpinsky")
}
