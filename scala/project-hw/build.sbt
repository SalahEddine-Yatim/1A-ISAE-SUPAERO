import Dependencies._

ThisBuild / scalaVersion := "2.13.10"
ThisBuild / organization := "fr.isae-supaero"
ThisBuild / version      := "2022-2023"

lazy val root = (project in file(".")).
  settings(
    name := "l-system",
    libraryDependencies += scalaTest % Test,
    libraryDependencies += "org.creativescala" %% "doodle" % "0.18.0",
  )
