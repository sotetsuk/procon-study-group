#! /usr/bin/env ruby
include Math
def c p;c=[(2.0*p[0]+p[2])/3.0,(2.0*p[1]+p[3])/3.0,(p[0]+2.0*p[2])/3.0,(p[1]+2.0*p[3])/3.0];c+=[(c[2]-c[0])*cos(TH)-(c[3]-c[1])*sin(TH)+c[0],(c[2]-c[0])*sin(TH)+(c[3]-c[1])*cos(TH)+c[1]];end
TH=PI*60.0/180.0
b,e=[0,0],[100,0]
[b,->(n,p,f=nil){(f=->(n,p){t=c(p);n==0?[]:[f[n-1,p[0,2]+t[0,2]],t[0,2],f[n-1,t[0,2]+t[4,2]],t[4,2],f[n-1,t[4,2]+t[2,2]],t[2,2],f[n-1,t[2,2]+p[2,2]]]})[n,p]}[gets.chomp.to_i,b+e],e].flatten.each_slice(2){|r,s|puts"%.8f %.8f"%[r,s]}
