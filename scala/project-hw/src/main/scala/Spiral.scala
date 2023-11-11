// imports for LSystem implementation
import doodle.syntax.all._
import doodle.turtle.Instruction._

object Spiral extends LSystemTurtle {

  abstract class Letter
  case class Branche(otherword: Word) extends Letter
  case class L(l : Double , a:Double , s:Int) extends Letter  //Fonction  L()
  case class R(l : Double , a:Double , s:Int) extends Letter  //Fonction  R()
  case class F(l : Double ) extends Letter  //Fonction F()
  case class Plus(a : Double ) extends Letter  //Fonction  +()
  case class Minus(a : Double ) extends Letter  //Fonction -()

  def axiom : List[Letter] = (1 to 10).toList.flatMap(i => List(Branche(List(Minus(36 * i), L(100, 2.2, 6))))) // initialisation comme liste de Branche  


  def rewrite(w: Word) : Word = {
    w flatMap {
      case L(l,a,s) if s > 0      => List(F(l), Minus(a) , L(l * 0.93, a, s-1))
      case L(l, a, s) if s == 0   => List(F(l), Minus(a), Branche(List(R(l * 0.93, a, 6))), L(l * 0.93, a, 6))
      case R(l, a, s) if s > 0    => List(F(l), Plus(a), R(l * 0.93, a, s - 1))
      case R(l, a, s) if s == 0   => List(F(l), Plus(a), Branche(List(L(l * 0.93, a, 6))), R(l * 0.93, a, 6))
      case Branche(otherword)     => List(Branche(rewrite(otherword))) //Recursion pour chaque branche 
      case other                  => List(other)
    }
  }

  def compile(w: Word) = {
    w flatMap {
      case F(l)               => List(forward(l))
      case Plus(a)            => List(turn(a.degrees))
      case Minus(a)           => List(turn((-a).degrees))
      case Branche(otherword) => List(Branch(compile(otherword))) //utilisation de fonction Branch de doodleturtle pour revenir au point initial
      case other              => None
    }
  }

}

object SpiralApp extends App {
  Spiral.toImage(55, "Spiral", true)
}
