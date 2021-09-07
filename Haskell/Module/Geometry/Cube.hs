modue Geometry.Cube
(
    volume,
    area
) where

import qualified Geometry.Cuboid as Cuboid

volume :: Float -> Float
volume s = Cuboid.volume s s s

area :: Float -> Float
area s = Cuboid.area s s s  
