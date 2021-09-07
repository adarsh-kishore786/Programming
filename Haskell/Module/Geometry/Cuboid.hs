module Geometry.Cuboid
(
    volume,
    area
) where

volume :: Float -> Float -> Float -> Float
volume l b h = l * b * h

area :: Float -> Float -> Float -> Float
area l b h = 2 * (l * b + b * h + h * l)
