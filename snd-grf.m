xs = [-0.927418589592 -0.978767096996 -0.979860723019 -0.928484678268 -0.990639925003]

ys = [-0.315679132938 -0.0835983902216 0.102196574211 0.295677155256 -0.0570458732545]

zs = [-0.200602740049 -0.187153190374 -0.171548739076 -0.224702715874 0.124008491635]

xyzs = sqrt(xs.*xs+ys.*ys+zs.*zs)

xsn = xs./xyzs
ysn = ys./xyzs
zsn = zs./xyzs

xf = [0.744594131527 0.811416681793 0.744594131527 0.608562511344 0.614470885241]

yf = [0.067 -0.0501282051282 -0.191 -0.331826923077 -0.0140291262136]

zf = [-0.043 -0.0653846153846 -0.074 -0.0335096153846 -0.298737864078]

xyzf = sqrt(xf.*xf+yf.*yf+zf.*zf)
xfn = xf./xyzf
yfn = yf./xyzf
zfn = zf./xyzf

cmat = [
 -0.978733 -0.0245197   0.203665  0.0128649
  0.121826   0.729311   0.673252  0.0488694
  0.165042  -0.683746   0.710813  0.0247305
         0          0          0          1
]

% [x y z 1]'=cmat*[x0 y0 z0 1]'
% cam cord = conv mat * sound coord
plot3 (xsn,ysn,zsn,'-b',xfn,yfn,zfn,'-r')
title("plot")
xlabel("x")
ylabel("y")
zlabel("z")

