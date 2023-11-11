import Dependencies._

ThisBuild / scalaVersion := "2.13.1"
ThisBuild / organization := "fr.isae-supaero"
ThisBuild / version      := "2022-2023"

lazy val root = (project in file(".")).
  settings(
    name := "eisc101-labs",
    libraryDependencies += scalaTest % Test,
    libraryDependencies += scalaCheck % Test,
    initialCommands in console += "import HigherOrderApp._, StreamsApp._"
  )
