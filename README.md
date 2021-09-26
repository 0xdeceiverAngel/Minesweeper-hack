# Minesweeper-hack

> WARNING: Just for education purpose

## Describe

slove the game immediately

## Game hash

2001 windows xp game

MD5 9c45d38b74634c9ded60bec640c5c3ca

SHA-1 79d03b17ce9e7ff9595253a402efb856b0888ea0

## Detail
Break point on `Bitblt`,found it will render to small cell for each mine space,look more futher in asm,`ebx` may store the adderss of mine map

![](https://raw.githubusercontent.com/0xdeciverAngel/Minesweeper-hack/main/bitblt.png)

![](https://raw.githubusercontent.com/0xdeciverAngel/Minesweeper-hack/main/position.jpg)



mine position were save at 0x01005360，offset -0x20 were border,so I skip it

```
0x0F is empty space
0x8F is mine
0x10 is border
```

every 32 byte were a row

```
01005360  10 8F 8F 8F 8F 8F 8F 8F 8F 8F 8F 8F 8F 8F 8F 8F 
01005370  8F 8F 8F 8F 8F 8F 8F 8F 8F 8F 8F 8F 8F 8F 8F 10 
01005380  10 8F 8F 8F 8F 8F 8F 0F 8F 8F 0F 8F 0F 8F 8F 8F 
01005390  8F 8F 8F 8F 8F 8F 8F 8F 8F 8F 8F 8F 8F 8F 8F 10 
010053A0  10 8F 8F 8F 0F 8F 8F 8F 8F 8F 8F 8F 0F 8F 8F 8F 
010053B0  8F 0F 0F 8F 8F 8F 8F 8F 8F 8F 8F 8F 8F 8F 8F 10 
010053C0  10 8F 8F 8F 8F 8F 8F 8F 8F 8F 8F 8F 0F 8F 0F 8F 
010053D0  8F 8F 8F 8F 8F 8F 8F 8F 0F 8F 0F 0F 8F 8F 0F 10 
010053E0  10 8F 8F 8F 8F 8F 8F 8F 8F 8F 8F 8F 8F 8F 8F 8F 
010053F0  8F 8F 8F 8F 8F 8F 8F 8F 8F 8F 8F 8F 0F 8F 8F 10 
....skip
```

max size height 24 ,width 30


PS. If your first step were on mine,that mine will change it position

Write some code dump the memory out,use windows api to click the cell




## Demo

height 24 ,width 30,mines 667


![](https://raw.githubusercontent.com/0xdeciverAngel/Minesweeper-hack/main/demo.png)


