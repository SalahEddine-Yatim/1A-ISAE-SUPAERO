// imports for Turtle
import doodle.turtle._

// imports for image generation
import doodle.syntax.all._
import doodle.image.Image
import doodle.core._
import doodle.image.syntax.all._
import cats.effect.IO
import cats.effect.unsafe.implicits.global
import doodle.core.format._

// imports for PNG generation
import doodle.java2d._

abstract class LSystem {

  type Letter

  type Word = List[Letter]

  def axiom: Word

  def rewrite(w: Word): Word

  def toStream: LazyList[Word] = {
    def to_stream (Mot : Word) : LazyList[Word] = {
      Mot #:: to_stream(rewrite(Mot))
    }
    to_stream(axiom)
  }

  def show(w: Word): String = w.mkString("")

  def show(upTo: Int): Unit =
    (1 to upTo).foreach(i => println(show(toStream(i))))

}

abstract class LSystemTurtle extends LSystem {

  def compile(w: Word): List[Instruction]

  def toImage(upTo: Int, filename: String, rotate: Boolean = false): Unit =
    Turtle
      .draw(compile(toStream(upTo)))
      .transform(Transform.rotate(if (rotate) 90.degrees else 0.degrees))
      .write[Png]("./images/" + filename + s"-$upTo.png")
}
