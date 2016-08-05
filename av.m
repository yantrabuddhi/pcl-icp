function [sx, sy, sz]=av(ix, iy, iz, stp)
sx=[];sy=[];sz=[];
stpx=floor(size(ix)/stp);

for i=[1:1:stpx]
avx=0;
avy=0;
avz=0;
  for j=[1:1:stp]
  avx=avx+ix([(i-1)*stp+j]);
  avy=avy+iy([(i-1)*stp+j]);
  avz=avz+iz([(i-1)*stp+j]);
  endfor
  avx=avx/stp;
  avy=avy/stp;
  avz=avz/stp;
  sx=[sx(1:end);avx];
  sy=[sy(1:end);avy];
  sz=[sz(1:end);avz];
endfor
endfunction