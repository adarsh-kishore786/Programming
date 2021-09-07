module Geometry
(
    sphereVolume,
    sphereArea,
    cubeVolume,
    cubeArea,
    cuboidVolume,
    cuboidArea
) where

sphereVolume :: Float -> Float
sphereVolume R = (4.0/3.0) * pi * (R^3)

sphereArea :: Float -> Float
sphereArea R = 4 * pi * (R^2)

cuboidVolume :: Float -> Float -> Float -> Float
cuboidVolume l b h = l * b * h

cuboidArea :: Float -> Float -> Float -> Float
cuboidArea l b h = 2 * (l * b + b * h + h * l)

cubeVolume :: Float -> Float
cubeVolume a = cuboidVolume a a a

cubeArea :: Float -> Float
cubeArea a = cuboidArea a a a
