sounds = load("sound_points.csv","-ascii");
face = load("face_points.csv","-ascii");
sx=sounds(:,1);
sy=sounds(:,2);
sz=sounds(:,3);
fx=face(:,1);
fy=face(:,2);
fz=face(:,3);
figure(1);
scatter3(sx,sy,sz,[]);
xlabel("x");ylabel("y");zlabel("z");title("sound source");
figure(2);
scatter3(fx,fy,fz,[]);
xlabel("x");ylabel("y");zlabel("z");title("face points");
[ax,ay,az]=av(sx,sy,sz,10);
figure(3);
scatter3(ax,ay,az,[]);
xlabel("x");ylabel("y");zlabel("z");title("avg snd points");

cmat=[0.943789,0.129327,0.304204,0.00736024;
			-0.131484,0.991228,-0.0134787,0.00895614;
			-0.303278,-0.0272767,0.952513,0.0272001;
			0, 0, 0, 1];
s2=[];
for i=[1:1:size(sx)]
sm=[sounds(i,1); sounds(i,2); sounds(i,3);1.0];
op=cmat*sm;
s2=[s2;op(1) op(2) op(3)];
endfor
sx2=s2(:,1);
sy2=s2(:,2);
sz2=s2(:,3);

figure(4);
scatter3(sx2,sy2,sz2,[]);
xlabel("x");ylabel("y");zlabel("z");title("conv snd points");

[ax2,ay2,az2]=av(sx2,sy2,sz2,10);
figure(5);
scatter3(ax2,ay2,az2,[]);
xlabel("x");ylabel("y");zlabel("z");title("avg-conv snd points");
