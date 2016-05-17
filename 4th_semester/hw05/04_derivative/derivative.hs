import System.IO

data Expression = X
              | Const Int
              | Expression :+: Expression
              | Expression :-: Expression
              | Expression :*: Expression
              | Expression :/: Expression
              | Expression :^: Int
              deriving Show
              
derive :: Expression -> Expression
derive p = case p of
           X -> Const 1
           Const n -> Const 0
           p1 :+: p2 -> derive p1 :+: derive p2
           p1 :-: p2 -> derive p1 :-: derive p2
           p1 :*: p2 -> (derive p1 :*: p2) :+: (p1 :*: derive p2)
           p1 :/: p2 -> ((derive p1 :*: p2) :-: (p1 :*: derive p2)) :/: (p2 :*: p2)
           p :^: n -> Const n :*: (p :^: (n - 1)) :*: derive p

simplifyMonomial :: Expression -> Expression
simplifyMonomial m = case m of 
                   Const a :+: Const b -> Const (a + b)
                   Const a :-: Const b -> Const (a - b)
                   Const a :*: Const b -> Const (a * b)
                   Const a :/: Const b -> Const (a `div` b)
                   Const a :^: b -> Const (a ^ b)
                   
                   m :+: Const 0 -> simplifyMonomial m
                   m :-: Const 0 -> simplifyMonomial m
                   m :*: Const 0 -> Const 0
                   m :*: Const 1 -> simplifyMonomial m 
                   m :/: Const 1 -> simplifyMonomial m
                     
                   Const 0 :+: m -> simplifyMonomial m
                   Const 0 :-: m -> simplifyMonomial (Const (-1) :*: simplifyMonomial m)
                   Const 0 :*: m -> Const 0
                   Const 1 :*: m -> simplifyMonomial m
                   Const 0 :/: m -> Const 0
                     
                   m :^: 0 -> Const 1
                   m :^: 1 -> simplifyMonomial m
                   
                   _ -> m
           
simplify :: Expression -> Expression
simplify p = case p of
             X -> X
             Const n -> Const n
 
             p1 :+: p2 -> simplifyMonomial (simplify p1 :+: simplify p2)
             p1 :-: p2 -> simplifyMonomial (simplify p1 :-: simplify p2)
             p1 :*: p2 -> simplifyMonomial (simplify p1 :*: simplify p2)
             p1 :/: p2 -> simplifyMonomial (simplify p1 :/: simplify p2)
             p :^: n -> simplifyMonomial (simplify p :^: n)
             
main = do
        putStrLn (show $ simplify $ derive ((X :^: 3) :+: (Const 3 :*: X) :-: Const 1) )     
             
             
             