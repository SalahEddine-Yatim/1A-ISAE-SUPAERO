// imports for LSystem implementation
import doodle.syntax.all._
import doodle.turtle.Instruction._

object Plant extends LSystemTurtle {

  abstract class Letter
  case object F extends Letter
  case object X extends Letter
  case object - extends Letter //Lettre -
  case object + extends Letter //Letter +
  case class Branche(otherword: Word) extends Letter //FOnction Branche qui represente [....]

  


  def axiom = List(X)

  def rewrite(w: Word) : Word = {
    w flatMap {
      case X                  => List(F,+,Branche(List(Branche(List(X)),-,X)),-,F,Branche(List(-,F,X)),+,X)
      case F                  => List(F,F)
      case Branche(otherword) => List(Branche(rewrite(otherword))) //Recursion pour chaque branche 
      case other              => List(other)
    }
  }

  def compile(w: Word) = {
    w flatMap {
      case X                  => List(noop)
      case F                  => List(forward(10))
      case +                  => List(turn((-25).degrees))
      case -                  => List(turn(25.degrees))
      case Branche(otherword) => List(Branch(compile(otherword))) //utilisation de fonction Branch de doodleturtle pour revenir au point initial 
    }
  }

}

object PlantApp extends App {
  Plant.toImage(5, "Plant", true)
}
