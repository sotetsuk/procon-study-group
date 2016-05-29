#!/usr/bin/env ruby
I=10e10
gets
c=0
puts ->(x,f=nil){(f=->(x){(s=x.size)==1?x:(a=f[x[0..s/2-1]]<<I;b=f[x[s/2..-1]]<<I;r=[];s.times do;r<<(a[0]<=b[0]?a.shift: b.shift);end;c+=s;r)})[x]}[gets.split.map(&:to_i)].join(' '),c
