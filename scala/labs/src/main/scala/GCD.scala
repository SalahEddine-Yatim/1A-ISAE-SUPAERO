object GCDApp extends App {
  // define gcd
  @scala.annotation.tailrec
  def gcd(x: BigInt, y: BigInt): BigInt = 

    if (x==0)
      if (y<0)
        -y
      else
        y
    
    else if (y==0)
      if(x<0)
        -x
      else 
        x
        
    else if(x<0)
      gcd(-x , y)

    else if(y<0)
      gcd(x , -y)

    else if (x == y)
      x

    else if (x < y)
      gcd(x , y-x)

    else
        gcd(x-y , y)


  // testing gcd
  print("-> testing gcd on some values...")
  assert(gcd(12, 4) == 4)
  assert(gcd(-4, 12) == 4)
  assert(gcd(10, 0) == 10)
  assert(gcd(0, 6) == 6)
  assert(gcd(20, -5) == 5)
  println(" OK!")

}
