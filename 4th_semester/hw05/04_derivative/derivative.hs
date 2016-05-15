import System.IO

data Polynome = X
              | Const Int
              | Polynome :+: Polynome
              | Polynome :-: Polynome
              | Polynome :*: Polynome
              | Polynome :^: Int
              deriving Show
              
derive :: Polynome -> Polynome
derive p = case p of
           X -> Const 1
           Const n -> Const 0
           p1 :+: p2 -> derive p1 :+: derive p2
           p1 :-: p2 -> derive p1 :-: derive p2
           p1 :*: p2 -> (derive p1 :*: p2) :+: (p1 :*: derive p2)
           p :^: n -> Const n :*: (p :^: (n - 1)) :*: derive p

simplifyMonome :: Polynome -> Polynome
simplifyMonome m = case m of 
                   Const a :+: Const b -> Const (a + b)
                   Const a :-: Const b -> Const (a - b)
                   Const a :*: Const b -> Const (a * b)
                   Const a :^: b -> Const (a ^ b)
                   
                   m :+: Const 0 -> simplifyMonome m
                   m :-: Const 0 -> simplifyMonome m
                   m :*: Const 0 -> Const 0
                   m :*: Const 1 -> simplifyMonome m 
                     
                   Const 0 :+: m -> simplifyMonome m
                   Const 0 :-: m -> simplifyMonome (Const (-1) :*: simplifyMonome m)
                   Const 0 :*: m -> Const 0
                   Const 1 :*: m -> simplifyMonome m
                     
                   m :^: 0 -> Const 1
                   m :^: 1 -> simplifyMonome m
                   
                   _ -> m
           
simplify :: Polynome -> Polynome
simplify p = case p of
             X -> X
             Const n -> Const n
 
             p1 :+: p2 -> simplifyMonome (simplify p1 :+: simplify p2)
             p1 :-: p2 -> simplifyMonome (simplify p1 :-: simplify p2)
             p1 :*: p2 -> simplifyMonome (p1 :*: simplify p2)
             p :^: n -> simplifyMonome (simplify p :^: n)
             
main = do
        putStrLn (show $ simplify $ derive ((X :^: 3) :+: (Const 3 :*: X) :-: Const 1) )     
             
             
             