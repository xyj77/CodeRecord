# -*- coding: utf-8 -*-
def space_efficient_lcs(str_a, str_b):
  if len(str_a) == 0 or len(str_b) == 0:
    return 0
  dp = [0 for _ in range(len(str_b) + 1)]
  for i in range(1, len(str_a) + 1):
    left_up = 0
    dp[0] = 0
    for j in range(1, len(str_b) + 1):
      left = dp[j-1]
      up = dp[j]
      if str_a[i-1] == str_b[j-1]:
        dp[j] = left_up + 1
      else:
        dp[j] = max([left, up])
      left_up = up
  print dp[len(str_b)]
  

a = input()
b = input()
  
space_efficient_lcs(a, b)