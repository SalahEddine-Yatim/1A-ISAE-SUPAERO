object PascalApp extends App {
  // define pascal
  def pascal(r: Int, c: Int): Int =
    if (c < 0 || r < 0 || c > r)
      0
    else if (c == 0 || c == r)
      1
    else
      pascal(r - 1, c - 1) + pascal(r - 1, c)

  // testing pascal
  print("-> testing pascal...")
  assert(pascal(0, 0) == 1)
  assert(pascal(1, 0) == 1)
  assert(pascal(1, 1) == 1)
  assert(pascal(2, 0) == 1)
  assert(pascal(2, 1) == 2)
  assert(pascal(2, 2) == 1)
  assert(pascal(3, 0) == 1)
  assert(pascal(3, 1) == 3)
  assert(pascal(3, 2) == 3)
  assert(pascal(3, 3) == 1)
  println(" OK!")
}
