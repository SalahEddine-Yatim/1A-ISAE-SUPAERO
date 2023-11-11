// imports for LSystem implementation
import doodle.syntax.all._
import doodle.turtle._
import doodle.turtle.Instruction._

// imports for PNG generation
// import doodle.core._
import doodle.image.syntax.all._
import doodle.java2d._
import cats.effect.unsafe.implicits.global
import doodle.core.format._

object DoodleEx extends App {
  val ex1 = Turtle.draw(List(forward(10), turn(-30.degrees), forward(20)))
  ex1.write[Png]("./images/ex-turtle-simple.png")
  println(ex1)

  val ex2 = Turtle.draw(List(forward(10), Branch(List(turn(90.degrees), forward(10))), turn(-30.degrees), forward(20)))
  ex2.write[Png]("./images/ex-turtle-branch.png")
  println(ex2)
}


