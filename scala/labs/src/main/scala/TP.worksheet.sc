1-5 
print("coucou")

(BigInt(1) to BigInt(10000000)).map(x => x*x).filter(x => x%2 == 1).sum
