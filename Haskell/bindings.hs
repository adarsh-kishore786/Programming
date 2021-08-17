-- where

areaOfCylinder :: (RealFloat a) => a -> a -> a
areaOfCylinder r h = arOfBase + arOfCurve
    where arOfBase  = 2 * pi * r^2
          arOfCurve = 2 * pi * r * h

-- let
areaOfCylinder' :: (RealFloat a) => a -> a -> a
areaOfCylinder' r h =
    let sideArea = 2 * pi * r * h
        topArea  = pi * r^2
    in sideArea + 2 * topArea

calcBmis :: (RealFloat a) => [(a, a)] -> [a]
calcBmis xs = [bmi | (w, h) <- xs, let bmi = w / h^2 ]
