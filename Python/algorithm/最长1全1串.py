#-*- coding = utf-8 -*-
if __name__ == '__main__':
    n, k = [int(x) for x in raw_input().split(' ')]

    bin_list = [int(x) for x in raw_input().split(' ')]
    
    zero_ind = [i for i, x in enumerate(bin_list) if x == 0]
 
    head, tail = 0, 0+k
    max_l = 0
    if len(zero_ind) == 0:
        print(n)
    elif len(zero_ind) == n:
        print(k)
    else:
        while tail <= len(zero_ind):
            if head == 0:
                if zero_ind[tail] > max_l:
                    max_l = zero_ind[tail]
            elif tail == len(zero_ind):
                if n - zero_ind[head] + 1 > max_l:
                    max_l = n - zero_ind[head] + 1
            else:
                if zero_ind[tail] - zero_ind[head-1] - 1 > max_l:
                    max_l = zero_ind[tail] - zero_ind[head-1] - 1
            head += 1
            tail += 1
        print(max_l)


'''
最长全一串
输入01串长度，和k值
第二行01字符串
可以将其中k个0改成1，求可以获得的最长连续1的长度

输入：
10 2
1 0 0 1 0 1 0 1 0 1

输出：
5

'''