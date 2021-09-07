module Geometry.Sphere
(
    volume,
    area
) where

volume :: Float -> Float
volume R = (4.0/3.0) * pi * (R^3)

area :: Float -> Float
area R = 4 * pi * (R^2)
